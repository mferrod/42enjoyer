#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    bool isValidDate(const std::string &date) const;
    bool isValidValue(float value) const;
    std::string findClosestDate(const std::string &date) const;
    void parseDatabaseLine(const std::string &line);
    float stringToFloat(const std::string &str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void loadDatabase(const std::string &filename);
    float getExchangeRate(const std::string &date) const;
    void processInputFile(const std::string &filename) const;

    class FileError : public std::runtime_error {
    public:
        FileError(const std::string &msg) : std::runtime_error(msg) {}
    };

    class DateError : public std::runtime_error {
    public:
        DateError(const std::string &msg) : std::runtime_error(msg) {}
    };

    class ValueError : public std::runtime_error {
    public:
        ValueError(const std::string &msg) : std::runtime_error(msg) {}
    };
};

#endif