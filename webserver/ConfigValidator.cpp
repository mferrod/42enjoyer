#include "ConfigValidator.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <sys/stat.h>

ConfigValidator::ConfigValidator() {
    initializeValidMethods();
    initializeValidDirectives();
    initializeValidLocationDirectives();
}

ConfigValidator::~ConfigValidator() {}

void ConfigValidator::initializeValidMethods() {
    _validMethods.push_back("GET");
    _validMethods.push_back("POST");
    _validMethods.push_back("DELETE");
    _validMethods.push_back("PUT");
    _validMethods.push_back("HEAD");
    _validMethods.push_back("OPTIONS");
    _validMethods.push_back("PATCH");
}

void ConfigValidator::initializeValidDirectives() {
    _validDirectives.push_back("listen");
    _validDirectives.push_back("server_name");
    _validDirectives.push_back("root");
    _validDirectives.push_back("index");
    _validDirectives.push_back("client_max_body_size");
    _validDirectives.push_back("error_page");
    _validDirectives.push_back("redirect");
}

void ConfigValidator::initializeValidLocationDirectives() {
    _validLocationDirectives.push_back("root");
    _validLocationDirectives.push_back("index");
    _validLocationDirectives.push_back("allowed_methods");
    _validLocationDirectives.push_back("autoindex");
    _validLocationDirectives.push_back("cgi_path");
    _validLocationDirectives.push_back("upload_dir");
    _validLocationDirectives.push_back("error_page");
    _validLocationDirectives.push_back("redirect");
}

bool ConfigValidator::isValidPort(int port) const {
    return port > 0 && port < 65536;
}

bool ConfigValidator::isValidHttpCode(int code) const {
    return code >= 100 && code <= 599;
}

bool ConfigValidator::isValidMethod(const std::string &method) const {
    return std::find(_validMethods.begin(), _validMethods.end(), method) != _validMethods.end();
}

bool ConfigValidator::isValidDirective(const std::string &directive, bool isLocationContext) const {
    if (isLocationContext)
        return std::find(_validLocationDirectives.begin(), _validLocationDirectives.end(), directive) != _validLocationDirectives.end();
    return std::find(_validDirectives.begin(), _validDirectives.end(), directive) != _validDirectives.end();
}

bool ConfigValidator::isValidPath(const std::string &path) const {
    if (path.empty())
        return false;
    // Verificar caracteres válidos en path
    for (size_t i = 0; i < path.length(); ++i) {
        char c = path[i];
        if (!isalnum(c) && c != '/' && c != '_' && c != '-' && c != '.' && c != '~')
            return false;
    }
    return true;
}

bool ConfigValidator::isValidIP(const std::string &ip) const {
    if (ip == "0.0.0.0" || ip == "127.0.0.1" || ip == "localhost")
        return true;
    
    // Validar formato básico de IP (a.b.c.d) usando std::string
    std::string temp = ip;
    std::vector<int> parts;
    size_t pos = 0;
    size_t found = 0;
    
    while ((found = temp.find('.', pos)) != std::string::npos) {
        std::string part = temp.substr(pos, found - pos);
        std::istringstream iss(part);
        int num;
        if (!(iss >> num) || !iss.eof())
            return false;
        if (num < 0 || num > 255)
            return false;
        parts.push_back(num);
        pos = found + 1;
    }
    
    // Procesar la última parte
    std::string lastPart = temp.substr(pos);
    std::istringstream iss(lastPart);
    int num;
    if (!(iss >> num) || !iss.eof())
        return false;
    if (num < 0 || num > 255)
        return false;
    parts.push_back(num);
    
    // Debe haber exactamente 4 partes
    return parts.size() == 4;
}

int ConfigValidator::parsePort(const std::string &portStr) const {
    std::istringstream iss(portStr);
    int port;
    if (!(iss >> port) || !iss.eof()) {
        throw std::invalid_argument("Error: invalid port format");
    }
    if (!isValidPort(port)) {
        throw std::invalid_argument("Error: port must be between 1 and 65535");
    }
    return port;
}

std::vector<int> ConfigValidator::parseErrorPages(const std::string &codes) const {
    std::vector<int> result;
    std::istringstream iss(codes);
    std::string token;
    
    while (iss >> token) {
        if (token[0] == '/')
            continue; // Es el path
        
        int code = atoi(token.c_str());
        if (!isValidHttpCode(code)) {
            throw std::invalid_argument("Error: invalid HTTP status code: " + token);
        }
        result.push_back(code);
    }
    return result;
}

void ConfigValidator::validateListen(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: listen directive cannot be empty");
    }
    
    size_t colonPos = value.find(':');
    if (colonPos == std::string::npos) {
        throw std::invalid_argument("Error: listen format must be host:port");
    }
    
    std::string host = value.substr(0, colonPos);
    std::string portStr = value.substr(colonPos + 1);
    
    if (!isValidIP(host)) {
        throw std::invalid_argument("Error: invalid IP address: " + host);
    }
    
    parsePort(portStr); // Lanza excepción si es inválido
}

void ConfigValidator::validateServerName(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: server_name cannot be empty");
    }
    // Validar que sea un nombre de dominio válido (muy básico)
    if (value.find(' ') != std::string::npos) {
        throw std::invalid_argument("Error: server_name contains invalid characters");
    }
}

void ConfigValidator::validateRoot(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: root path cannot be empty");
    }
    if (!isValidPath(value)) {
        throw std::invalid_argument("Error: root path contains invalid characters: " + value);
    }
}

void ConfigValidator::validateIndex(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: index cannot be empty");
    }
    // Index puede contener múltiples archivos separados por espacios
    std::istringstream iss(value);
    std::string file;
    while (iss >> file) {
        if (!isValidPath(file)) {
            throw std::invalid_argument("Error: invalid index filename: " + file);
        }
    }
}

void ConfigValidator::validateClientMaxBodySize(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: client_max_body_size cannot be empty");
    }
    
    // Parsear valor con unidad (1M, 10K, 100, etc)
    std::string numStr = value;
    char unit = '\0';
    
    if (!isdigit(numStr[numStr.length() - 1])) {
        unit = numStr[numStr.length() - 1];
        numStr = numStr.substr(0, numStr.length() - 1);
    }
    
    char *endptr = NULL;
    long size = strtol(numStr.c_str(), &endptr, 10);
    
    if (endptr == numStr.c_str() || size <= 0) {
        throw std::invalid_argument("Error: invalid client_max_body_size format");
    }
    
    // Validar unidades conocidas
    if (unit != '\0' && unit != 'M' && unit != 'K' && unit != 'G') {
        throw std::invalid_argument("Error: invalid unit in client_max_body_size (use M, K, G)");
    }
}

void ConfigValidator::validateAllowedMethods(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: allowed_methods cannot be empty");
    }
    
    std::istringstream iss(value);
    std::string method;
    
    while (iss >> method) {
        if (!isValidMethod(method)) {
            throw std::invalid_argument("Error: invalid HTTP method: " + method);
        }
    }
}

void ConfigValidator::validateErrorPage(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: error_page cannot be empty");
    }
    
    // Formato: "404 /404.html" o "500 502 503 /50x.html"
    parseErrorPages(value); // Valida códigos
    
    size_t lastSpace = value.rfind(' ');
    if (lastSpace == std::string::npos) {
        throw std::invalid_argument("Error: error_page format invalid (needs path)");
    }
    
    std::string path = value.substr(lastSpace + 1);
    if (path[0] != '/') {
        throw std::invalid_argument("Error: error_page path must start with /");
    }
    if (!isValidPath(path)) {
        throw std::invalid_argument("Error: error_page path contains invalid characters");
    }
}

void ConfigValidator::validateAutoindex(const std::string &value) {
    if (value != "on" && value != "off") {
        throw std::invalid_argument("Error: autoindex must be 'on' or 'off'");
    }
}

void ConfigValidator::validateCgiPath(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: cgi_path cannot be empty");
    }
    if (!isValidPath(value)) {
        throw std::invalid_argument("Error: cgi_path contains invalid characters");
    }
    // Opcional: comprobar si el ejecutable existe
    struct stat buffer;
    if (stat(value.c_str(), &buffer) != 0) {
        std::cerr << "Warning: cgi_path does not exist or is not accessible: " << value << std::endl;
    }
}

void ConfigValidator::validateUploadDir(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: upload_dir cannot be empty");
    }
    if (!isValidPath(value)) {
        throw std::invalid_argument("Error: upload_dir path contains invalid characters");
    }
}

void ConfigValidator::validateRedirect(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Error: redirect cannot be empty");
    }
    
    size_t spacePos = value.find(' ');
    if (spacePos == std::string::npos) {
        throw std::invalid_argument("Error: redirect format must be 'code url'");
    }
    
    std::string codeStr = value.substr(0, spacePos);
    int code = atoi(codeStr.c_str());
    
    // Códigos de redirección válidos
    if (code != 301 && code != 302 && code != 303 && code != 307 && code != 308) {
        throw std::invalid_argument("Error: redirect code must be 301, 302, 303, 307, or 308");
    }
}

void ConfigValidator::validateDirective(const std::string &key, const std::string &value, bool isLocationContext) {
    if (!isValidDirective(key, isLocationContext)) {
        throw std::invalid_argument("Error: unknown directive: " + key);
    }
    
    if (value.empty()) {
        throw std::invalid_argument("Error: directive " + key + " has empty value");
    }
    
    if (key == "listen")
        validateListen(value);
    else if (key == "server_name")
        validateServerName(value);
    else if (key == "root")
        validateRoot(value);
    else if (key == "index")
        validateIndex(value);
    else if (key == "client_max_body_size")
        validateClientMaxBodySize(value);
    else if (key == "allowed_methods")
        validateAllowedMethods(value);
    else if (key == "error_page")
        validateErrorPage(value);
    else if (key == "autoindex")
        validateAutoindex(value);
    else if (key == "cgi_path")
        validateCgiPath(value);
    else if (key == "upload_dir")
        validateUploadDir(value);
    else if (key == "redirect")
        validateRedirect(value);
}

void ConfigValidator::validateServerConfig(const ServerConfig &server) {
    std::map<std::string, std::string> directives = server.getAllDirectives();
    
    // Validar que existan directivas obligatorias
    if (directives.find("listen") == directives.end()) {
        throw std::invalid_argument("Error: 'listen' directive is mandatory in server block");
    }
    
    if (directives.find("root") == directives.end()) {
        throw std::invalid_argument("Error: 'root' directive is mandatory in server block");
    }
    
    // Validar todas las directivas
    for (std::map<std::string, std::string>::const_iterator it = directives.begin(); it != directives.end(); ++it) {
        validateDirective(it->first, it->second, false);
    }
    
    // Validar locations
    std::vector<Location> locations = server.getLocations();
    for (size_t i = 0; i < locations.size(); ++i) {
        validateLocation(locations[i]);
    }
}

void ConfigValidator::validateLocation(const Location &location) {
    if (location.getPath().empty()) {
        throw std::invalid_argument("Error: location path cannot be empty");
    }
    
    std::map<std::string, std::string> directives = location.getAllDirectives();
    
    // Validar todas las directivas de location
    for (std::map<std::string, std::string>::const_iterator it = directives.begin(); it != directives.end(); ++it) {
        validateDirective(it->first, it->second, true);
    }
}

void ConfigValidator::validateServers(const std::vector<ServerConfig> &servers) {
    if (servers.empty()) {
        throw std::invalid_argument("Error: at least one server block must be defined");
    }
    
    std::map<std::string, int> listenPorts;
    
    for (size_t i = 0; i < servers.size(); ++i) {
        validateServerConfig(servers[i]);
        
        // Validar puertos duplicados
        std::string listen = servers[i].getDirective("listen");
        if (listenPorts.find(listen) != listenPorts.end()) {
            throw std::invalid_argument("Error: duplicate listen directive: " + listen);
        }
        listenPorts[listen] = 1;
    }
}
