// client.hpp

#pragma once 

#include <string>

namespace client {
    
    struct stClient 
    {
        std::string accountNumber;
        std::string pinCode;
        std::string name;
        std::string phone;
        double accountBalance = 0.0;
    };
 
    void ReadNewClient (stClient& client);
    stClient ReadNewClient (const stClient& client);
    std::string convertRecordToLine (const stClient& client, const std::string& separator="#//#");
    void ConvertLineToRecord (stClient& client, std::string& line);
    stClient ConvertLineToRecord (std::string& line);
    void PrintClientRecord (client::stClient& client);

    void AddClients();
    void AddLineToFile (const std::string& fileName=DEFAULT_CLIENTS_FILE, const std::string& data_line);
    void AddNewClient ();

    void ShowClients(const std::string& fileName=DEFAULT_CLIENTS_FILE);
    void PrintRecord (const std::vector<stClient>& vClients);
    void PrintLineRecord (const stClient& client);
    void ShowTable ();
    void ShowHeader (const std::string& title);

    std::string GetAccountNumber ();
    bool FindClientByAccountNumber (
        const std::vector<stClient>& vClients, 
        stClient client_to_find, 
        const std::string& accountNumber);

        
        
        
}