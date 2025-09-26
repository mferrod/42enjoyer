#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
	BitcoinExchange exchange;
	try {
		std::ifstream file(argv[1]);
		if (!file.is_open()) {
			throw std::runtime_error("Could not open file");
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
    return 0;
}