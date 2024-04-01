#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>

#include "io_module.h"

using namespace std;

void readData(Bank_Client &client)
{
    char clientLogin[100];
    cout << "¬ведите login: ";
    cin.ignore();
    cin.getline(clientLogin, 100);
    if (cin.fail())
    {
        cout << "ќшибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.login = (char *)malloc((strlen(clientLogin) + 1) * sizeof(char));
    strcpy(client.login, clientLogin);

    char clientPass[50];
    cout << "¬ведите пароль: ";
    cin.getline(clientPass, 50);
    if (cin.fail())
    {
        cout << "ќшибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.password = (char *)malloc((strlen(clientPass) + 1) * sizeof(char));
    strcpy(client.password, clientPass);

    cout << "¬ведите сумму на счЄте: ";
    cin >> client.dBalance;
    if (cin.fail())
    {
        cout << "ќшибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }

    char clientAddress[100];
    cout << "¬ведите адрес: ";
    cin.ignore();
    cin.getline(clientAddress, 100);
    if (cin.fail())
    {
        cout << "ќшибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.address = (char *)malloc((strlen(clientAddress) + 1) * sizeof(char));
    strcpy(client.address, clientAddress);

    char clientEmail[100];
    cout << "¬ведите email: ";
    cin >> clientEmail;
    if (cin.fail())
    {
        cout << "ќшибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.email = (char *)malloc((strlen(clientEmail) + 1) * sizeof(char));
    strcpy(client.email, clientEmail);
}

void printData(Bank_Client *client)
{
    cout << "Login: " << client->login << endl;
    cout << "Ѕаланс: " << client->dBalance << endl;
    cout << "јдрес: " << client->address << endl;
    cout << "Email: " << client->email << endl;
    cout << "Password: " << client->password << endl;
}

void DataInTable(Bank_Client *client)
{
    cout << "|" << setw(15) << "Login"
         << " | " << setw(10) << "Ѕаланс"
         << " | " << setw(15) << "јдрес"
         << " | " << setw(20) << "Email"
         << " | " << setw(15) << "Password"
         << " |" << endl;

    cout << "|" << setw(15) << client->login << " | " << setw(10) << client->dBalance << " | " << setw(15)
         << client->address << " | " << setw(20) << client->email << " | " << setw(15) << client->password << " |"
         << endl;
}

void Show(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        Node* current = stack->top;
        while (current->next != nullptr)
        {
            DataInTable(current->data);
            current = current->next;
        }
  
    }
}