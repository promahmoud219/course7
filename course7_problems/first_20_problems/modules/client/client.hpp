// client.hpp

#pragma once 

#include <string>
#include <string_view>

#include "../../config.hpp"

namespace client {
    
    struct Client 
    {
        std::string account_number;
        std::string pinCode;
        std::string name;
        std::string phone;
        double account_balance = 0.0;
        bool delete_mark = false;
    };

    enum class DeleteResult { Success, Cancelled, NotFound, Error };
    
    void addClients();
    void addLineToFile (const std::string& data_line, const std::string_view& fileName = config::DEFAULT_CLIENTS_FILE);
    void addNewClient ();
    void deleteClientScreen();
    DeleteResult deleteClient();
    bool doesClientExist (
        const std::vector<Client>& Clients, 
        Client& client, 
        const std::string& account_number);
    
    void findClientsScreen (const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);

    std::vector<Client> loadDataFromFile (const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);

    void parseLineToClient (Client& client, std::string& line);
    Client parseLineToClient (std::string& line);
    void printClientRecord (Client& client);
    void printRecord (const std::vector<Client>& Clients);
    void printLineRecord (const Client& client);
    std::string promptAccountNumber ();
    void printDeleteResult(const DeleteResult& delete_result)   ;
    
    void readNewClient (Client& client);
    Client readNewClient ();
    bool removeClientByAccount (std::vector<Client>& clients, const std::string& account_number);
    
    void saveToFile (std::vector<Client>& clients, const std::string_view& file_name=config::DEFAULT_CLIENTS_FILE);
    void showClients(const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);
    // void showClients(const std::string_view& fileName=config::DEFAULT_CLIENTS_FILE);
    void showTable ();
    void showHeader (const std::string& title);

        
    std::string toLine  (const Client& client, const std::string& separator="#//#");
        
        
        
}