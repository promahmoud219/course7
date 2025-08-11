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
    void AddLineToFile (const std::string& fileName, const std::string& data_line);
    void AddNewClient ();
}