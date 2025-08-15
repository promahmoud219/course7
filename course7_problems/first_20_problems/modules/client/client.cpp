// client.cpp

#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <fstream>

#include "client.hpp"
#include "../mystring/mystring.hpp"
#include "../array/array.hpp"
#include "../inputvalidation/inputvalidation.hpp"

namespace client {
   
    void addNewClient ()
    {
        Client client;
        readNewClient(client);
        printClientRecord(client);
    
        if (inputvalidation::AskYesNo("\nSave this client to file?")) {
            addLineToFile(toLine(client), config::DEFAULT_CLIENTS_FILE);
            std::cout << "\nRecord saved!\n";
        } 
        else
        std::cout << "\nRecord discarded.\n";
    }
    
    void addLineToFile (const std::string& data_line, const std::string_view& fileName)
    {
        std::fstream file;
        file.open(fileName.data(), std::ios::out | std::ios::app);
        if (file.is_open()) {
            file << data_line << std::endl;
            file.close();
        }
    }
    
    void addClients()
    {
        char addMore = 'y';
    
        do
        {
            std::cout << "\n\n\nAdding New Client:\n\n";
            addNewClient();
            std::cout << "\nAdd another client? (y/n): ";
            std::cin >> addMore;
    
        } while (toupper(addMore) == 'Y');
    }


    bool doesClientExist (const std::vector<Client>& Clients, Client& client, const std::string& accountNumber)
    {
        for (const Client& c : Clients)
        {
            if (c.accountNumber == accountNumber)
            {   
                client = c;
                return true;
            }
        } 
        return false;
    }

    
    void findClientsScreen (const std::string_view& fileName)
    {
        client::Client client;
        std::vector<Client> Clients = loadDataFromFile(fileName);
        std::string account_number = promptAccountNumber();
        if (doesClientExist(Clients, client, account_number))
        {
            std::cout << "\nclient found 😊\n";
            printClientRecord(client);
        }
        else
            std::cout << "\nthis is account number doesn't esist";
    }

    
    std::vector<Client> loadDataFromFile (const std::string_view& fileName)
    {
        std::vector<Client> Clients;
        std::fstream file;
        file.open(fileName.data(), std::ios::in);
        if (file.is_open())
        {
            std::string line = "";
            Client client;

            while(getline(file, line))
            {
                client = parseLineToClient(line);
                Clients.push_back(client);
            }
            file.close();
        }
        return Clients;
    }

    
    void parseLineToClient(Client& client, std::string& line)
    {
        std::vector<std::string> vClientData = mystring::SplitString(line, "#//#");

        client.accountNumber   = vClientData[0];
        client.pinCode         = vClientData[1];
        client.name            = vClientData[2];
        client.phone           = vClientData[3];
        client.accountBalance  = std::stod(vClientData[4]);
    }
    
    Client parseLineToClient (std::string& line)
    {
        Client client;
        parseLineToClient(client, line); // Reuse the first version
        return client;
    }

    void printClientRecord(Client& client) 
    {     
        std::cout << "\n\nThe following is the extracted client record:\n";     
        std::cout << "\nAccout Number: " << client.accountNumber;     
        std::cout << "\nPin Code     : " << client.pinCode;     
        std::cout << "\nName         : " << client.name;     
        std::cout << "\nPhone        : " << client.phone;     
        std::cout << "\nAccount Balance: "<<client.accountBalance << "\n"; 
    }

    void printLineRecord (const Client& client)
    {
        std::cout << "| " << std::left << std::setw(15) << client.accountNumber;
        std::cout << "| " << std::left << std::setw(10) << client.pinCode;
        std::cout << "| " << std::left << std::setw(40) << client.name;
        std::cout << "| " << std::left << std::setw(16) << client.phone;
        std::cout << "| " << std::left << std::setw(12) << client.accountBalance << "\n";
    }

    void printRecord (const std::vector<Client>& Clients)
    {
        for (const Client& client : Clients)
        {
            printLineRecord(client);    
        }
        
    }
    
    std::string promptAccountNumber () 
    {
        
        //! this is utils in back-end 
        std::string accountNumber = "";
        std::cout << "\nPlease enter Account Number:\n";//! helper
        std::cin >> accountNumber;
        return accountNumber;
    }
    
    
    void readNewClient (Client& client)
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

    Client readNewClient ()
    {
        Client result;
        readNewClient(result);
        return result;
    }
    
    
    void showClients(const std::string_view& fileName)
    {
        std::vector<Client> Clients = loadDataFromFile(fileName); //! backend
        std::string title = "Client List " + std::to_string(Clients.size()) + " Client(s)";  //! front-end -> UI
        showHeader(title); //! UI in front-end
        showTable(); 
        printRecord(Clients);
        
    }

    void showHeader (const std::string& title)
    {
        std::cout << "\n\t\t\t\t" << title;
    }

    void showLine()
    {
        std::cout << "\n-----------------------------------------------------------";
        std::cout << "-----------------------------------------------------------\n";
    }
    
    void showTable () 
    {
        showLine();
        
        std::cout << "| " << std::left << std::setw(15) << "Account Number";
        std::cout << "| " << std::left << std::setw(10) << "Pin Code";
        std::cout << "| " << std::left << std::setw(40) << "Client Name";
        std::cout << "| " << std::left << std::setw(16) << "Phone";
        std::cout << "| " << std::left << std::setw(12) << "Balance";
        
        showLine();
    }


    std::string toLine (const Client& client, const std::string& separator)
    {
        return client.accountNumber + separator +
            client.pinCode + separator +
            client.name + separator +
            client.phone + separator +
            std::to_string(client.accountBalance);
    }
}