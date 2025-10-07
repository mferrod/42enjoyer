#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        // Cargamos una copia del data.csv como base de datos
        exchange.loadDatabase(argv[1]);
        // Y lo procesamos
        exchange.processInputFile(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}