// client.hpp

#pragma once 

#include <string>
#include <string_view>

#include "../../config.hpp"

namespace client {
    
    struct Client 
    {
        std::string accountNumber;
        std::string pinCode;
        std::string name;
        std::string phone;
        double accountBalance = 0.0;
    };
    
    void addClients();
    void addLineToFile (const std::string& data_line, const std::string_view& fileName = config::DEFAULT_CLIENTS_FILE);
    void addNewClient ();
    
    bool doesClientExist (
        const std::vector<Client>& Clients, 
        Client& client, 
        const std::string& accountNumber);
    
    void findClientsScreen (const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);

    std::vector<Client> loadDataFromFile (const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);

    void parseLineToClient (Client& client, std::string& line);
    Client parseLineToClient (std::string& line);
    void printClientRecord (Client& client);
    void printRecord (const std::vector<Client>& Clients);
    void printLineRecord (const Client& client);
    std::string promptAccountNumber ();
    
    
    void readNewClient (Client& client);
    Client readNewClient ();

    void showClients(const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);
    // void showClients(const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);
    void showTable ();
    void showHeader (const std::string& title);

        
    std::string toLine  (const Client& client, const std::string& separator="#//#");
        
        
        
}