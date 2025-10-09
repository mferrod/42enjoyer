#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
    : _database(other._database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    std::istringstream iss(date);
    int year, month, day;
    char dash1, dash2;
    iss >> year >> dash1 >> month >> dash2 >> day;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return day <= (isLeap ? 29 : 28);
    }
    return true;
}

bool BitcoinExchange::isValidValue(float value) const {
    return value >= 0 && value <= 1000;
}

float BitcoinExchange::stringToFloat(const std::string &str) const {
    std::istringstream iss(str);
    float value;
    iss >> value;
    if (iss.fail())
        throw ValueError("not a valid number");
    return value;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it == _database.begin())
        return it->first;
    if (it == _database.end() || it->first != date)
        --it;
    return it->first;
}

void BitcoinExchange::parseDatabaseLine(const std::string &line) {
    size_t pos = line.find(',');
    if (pos == std::string::npos)
        throw ValueError("invalid database format");

    std::string date = line.substr(0, pos);
    std::string value = line.substr(pos + 1);

    if (!isValidDate(date))
        return;

    float rate = stringToFloat(value);
    _database[date] = rate;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileError("could not open database file");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                parseDatabaseLine(line);
            } catch (const std::exception &e) {
                std::cerr << "Warning: " << e.what() << std::endl;
            }
        }
    }

    if (_database.empty())
        throw ValueError("empty or invalid database");
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
    if (_database.empty())
        throw ValueError("database not loaded");

    if (!isValidDate(date))
        throw DateError("bad input => " + date);

    std::string closestDate = findClosestDate(date);
    return _database.at(closestDate);
}

void BitcoinExchange::processInputFile(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileError("could not open file");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        try {
            size_t pos = line.find(',');
            if (pos == std::string::npos)
                continue;

            std::string date = line.substr(0, pos);
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);

            std::string valueStr = line.substr(pos + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

            float value = stringToFloat(valueStr);
            if (value < 0) {
                throw ValueError("not a positive number");
            }
            if (value > 1000) {
                throw ValueError("too large a number");
            }
            if (isValidDate(date)) {
                std::cout << date << " => " << value << std::endl;
            }

        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}