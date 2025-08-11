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
        std::cout << "\nAccount Balance: "<<client.accountBalance; 
    }
    
    void AddNewClient ()
    {
        stClient client;
        ReadNewClient(client);
        PrintClientRecord(client);

        char saveChoice = 'y';
        std::cout << "\nSave this client to file? (y/n): ";
        std::cin >> saveChoice;    
        if (saveChoice)
            AddLineToFile("clients.txt", convertRecordToLine(client));
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

    void ShowTable () 
    {
        ShowLine();
        
        std::cout << "| " << std::left << std::setw(15) << " ";
        std::cout << "| " << std::left << std::setw(10) << " ";
        std::cout << "| " << std::left << std::setw(40) << " ";
        std::cout << "| " << std::left << std::setw(12) << " ";
        std::cout << "| " << std::left << std::setw(12) << " ";

        ShowLine();
    }

    void ShowLine()
    {
        std::cout << "\n-----------------------------------------------------------";
        std::cout << "-----------------------------------------------------------\n";
    }

    void PrintLineRecord (const stClient& client)
    {
        std::cout << ""
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
        std::string title = "Client List (" + std::to_string(vClients.size()) + " Client(s)";  //! front-end -> UI
        ShowHeader(title); //! UI in front-end
        ShowTable();
        PrintLineRecord();
        
    }
    


}