#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>

#include "io_module.h"

using namespace std;

void readData(Bank_Client &client)
{
    char clientLogin[100];
    cout << "������� login: ";
    cin.ignore();
    cin.getline(clientLogin, 100);
    if (cin.fail())
    {
        cout << "������ �����" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.login = new char[strlen(clientLogin) + 1];
    strcpy(client.login, clientLogin);

    char clientPass[50];
    cout << "������� ������: ";
    cin.getline(clientPass, 50);
    if (cin.fail())
    {
        cout << "������ �����" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.password = new char[strlen(clientPass) + 1];
    strcpy(client.password, clientPass);

    cout << "������� ����� �� �����: ";
    cin >> client.dBalance;
    if (cin.fail())
    {
        cout << "������ �����" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    char clientAddress[100];
    cout << "������� �����: ";
    cin.ignore();
    cin.getline(clientAddress, 100);
    if (cin.fail())
    {
        cout << "������ �����" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.address = new char[strlen(clientAddress) + 1];
    strcpy(client.address, clientAddress);

    char clientEmail[100];
    cout << "������� email: ";
    cin >> clientEmail;
    if (cin.fail())
    {
        cout << "������ �����" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.email = new char[strlen(clientEmail) + 1];
    strcpy(client.email, clientEmail);
}

void printData(Bank_Client *client)
{
    cout << "Login: " << client->login << endl;
    cout << "������: " << client->dBalance << endl;
    cout << "�����: " << client->address << endl;
    cout << "Email: " << client->email << endl;
    cout << "Password: " << client->password << endl;
}

void DataInTable(Bank_Client *client)
{
    cout << "|" << setw(15) << client->login << " | " << setw(10) << client->dBalance << " | " << setw(15)
         << client->address << " | " << setw(20) << client->email << " | " << setw(15) << client->password << " |"
         << endl;
}

void Show(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "���� ����" << endl;
    }
    else
    {
        Node *current = stack->top;
        while (current != nullptr)
        {
            DataInTable(current->data);
            current = current->next;
        }
    }
}

int getIntInput()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cout << "������: ������������ ����. ����������, ������� �����." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return input;
        }
    }
}

char getCharInput()
{
    char input;
    while (true)
    {
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cout << "������: ������������ ����. ����������, ������� ������." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return input;
        }
    }
}
