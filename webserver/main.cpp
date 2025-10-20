#include <iostream>
#include "ConfigParser.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " config_file" << std::endl;
        return 1;
    }
    
    ConfigParser parser;
    
    if (!parser.parseConfig(argv[1])) {
        return 1;
    }
    
    const std::vector<ServerConfig> &servers = parser.getServers();
    std::cout << "Parsed " << servers.size() << " server(s)" << std::endl;
    
    for (size_t i = 0; i < servers.size(); ++i) {
        std::cout << "Server " << (i + 1) << ":" << std::endl;
        std::map<std::string, std::string> directives = servers[i].getAllDirectives();
        for (std::map<std::string, std::string>::const_iterator it = directives.begin();
             it != directives.end(); ++it) {
            std::cout << "  " << it->first << " " << it->second << std::endl;
        }
        
        // Mostrar locations
        std::vector<Location> locations = servers[i].getLocations();
        for (size_t j = 0; j < locations.size(); ++j) {
            std::cout << "  Location: " << locations[j].getPath() << std::endl;
            std::map<std::string, std::string> locDirectives = locations[j].getAllDirectives();
            for (std::map<std::string, std::string>::const_iterator it = locDirectives.begin();
                 it != locDirectives.end(); ++it) {
                std::cout << "    " << it->first << " " << it->second << std::endl;
            }
        }
    }
    
    return 0;
}