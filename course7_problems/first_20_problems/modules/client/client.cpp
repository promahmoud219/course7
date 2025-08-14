// client.cpp

#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <fstream>

#include "client.hpp"
#include "../mystring/mystring.hpp"
#include "../array/array.hpp"


namespace client {

    inline constexpr const char* DEFAULT_CLIENTS_FILE = "clients.csv";


    void ReadNewClient (stClient& client)
    {

        std::cout << "Enter Account Number? ";
        std::getline(std::cin >> std::ws, client.accountNumber);

        std::cout << "Enter PinCode? ";
        std::getline(std::cin, client.pinCode);

        std::cout << "Enter Name? ";
        std::getline(std::cin, client.name);

        std::cout << "Enter Phone? ";
        std::getline(std::cin, client.phone);

        std::cout << "Enter Account Balance? ";
        std::cin >> client.accountBalance;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover input
    }

    stClient ReadNewClient (const stClient& client)
    {
        stClient result;
        result = client;
        ReadNewClient(result);
        return result;
    }

    std::string convertRecordToLine(const stClient& client, const std::string& separator)
    {
        return client.accountNumber + separator +
            client.pinCode + separator +
            client.name + separator +
            client.phone + separator +
            std::to_string(client.accountBalance);
    }

    void ConvertLineToRecord(stClient& client, std::string& line)
    {
        std::vector<std::string> vClientData = mystring::SplitString(line, "#//#");

        client.accountNumber   = vClientData[0];
        client.pinCode         = vClientData[1];
        client.name            = vClientData[2];
        client.phone           = vClientData[3];
        client.accountBalance  = std::stod(vClientData[4]);
    }
    
    stClient ConvertLineToRecord (std::string& line)
    {
        stClient client;
        ConvertLineToRecord(client, line); // Reuse the first version
        return client;
    }

    void PrintClientRecord(client::stClient& client) 
    {     
        std::cout << "\n\nThe following is the extracted client record:\n";     
        std::cout << "\nAccout Number: " << client.accountNumber;     
        std::cout << "\nPin Code     : " << client.pinCode;     
        std::cout << "\nName         : " << client.name;     
        std::cout << "\nPhone        : " << client.phone;     
        std::cout << "\nAccount Balance: "<<client.accountBalance << "\n"; 
    }
    
    void AddNewClient ()
    {
        stClient client;
        ReadNewClient(client);
        PrintClientRecord(client);

        char saveChoice = 'y';
        std::cout << "\nSave this client to file? (y/n): "; //! 
        std::cin >> saveChoice;    
        if (saveChoice)
            AddLineToFile(DEF, convertRecordToLine(client));
    }

    void AddLineToFile (const std::string& fileName, const std::string& data_line)
    {
        std::fstream file;
        file.open(fileName, std::ios::out | std::ios::app);
        if (file.is_open()) {
            file << data_line << std::endl;
            file.close();
        }
    }
    
    void AddClients()
    {
        char addMore = 'y';

        do
        {
            std::cout << "\n\n\nAdding New Client:\n\n";
            AddNewClient();
            std::cout << "\nAdd another client? (y/n): ";
            std::cin >> addMore;

        } while (toupper(addMore) == 'Y');
    }

    std::vector<stClient> LoadDataFromFile (const std::string& fileName)
    {
        std::vector<stClient> vClients;
        std::fstream file;
        file.open(fileName, std::ios::in);
        if (file.is_open())
        {
            std::string line = "";
            stClient client;

            while(getline(file, line))
            {
                client = ConvertLineToRecord(line);
                vClients.push_back(client);
            }
            file.close();
        }
        return vClients;
    }

    void ShowHeader (const std::string& title)
    {
        std::cout << "\n\t\t\t\t" << title;
    }

    void ShowLine()
    {
        std::cout << "\n-----------------------------------------------------------";
        std::cout << "-----------------------------------------------------------\n";
    }
    
    void ShowTable () 
    {
        ShowLine();
        
        std::cout << "| " << std::left << std::setw(15) << "Account Number";
        std::cout << "| " << std::left << std::setw(10) << "Pin Code";
        std::cout << "| " << std::left << std::setw(40) << "Client Name";
        std::cout << "| " << std::left << std::setw(16) << "Phone";
        std::cout << "| " << std::left << std::setw(12) << "Balance";
        
        ShowLine();
    }
    
    void PrintLineRecord (const stClient& client)
    {
        std::cout << "| " << std::left << std::setw(15) << client.accountNumber;
        std::cout << "| " << std::left << std::setw(10) << client.pinCode;
        std::cout << "| " << std::left << std::setw(40) << client.name;
        std::cout << "| " << std::left << std::setw(16) << client.phone;
        std::cout << "| " << std::left << std::setw(12) << client.accountBalance << "\n";
    }

    void PrintRecord (const std::vector<stClient>& vClients)
    {
        for (const stClient& client : vClients)
        {
            PrintLineRecord(client);    
        }
        
    }
    
    void ShowClients(const std::string& fileName)
    {
        std::vector<stClient> vClients = LoadDataFromFile(fileName); //! backend
        std::string title = "Client List " + std::to_string(vClients.size()) + " Client(s)";  //! front-end -> UI
        ShowHeader(title); //! UI in front-end
        ShowTable(); 
        PrintRecord(vClients);
        
    }

    std::string GetAccountNumber () 
    {
        //! this is utils in back-end 
        std::string accountNumber = "";
        std::cout << "\nPlease enter Account Number:\n";//! helper
        std::cin >> accountNumber;
        return accountNumber;
    }

    bool FindClientByAccountNumber (const std::vector<stClient>& vClients, stClient client_to_find, const std::string& accountNumber)
    {
        for (const stClient& client : vClients)
        {
            if (client.accountNumber == accountNumber)
            {
                client_to_find = client;
                return true;
            }
        } 
        return false;
    }

    void findClientsScreen (const std::string& fileName)
    {
            
    }
}
/*
!  

*/