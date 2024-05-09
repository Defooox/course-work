#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string>

#include "io_module.h"

using namespace std;

bool isDigit(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return false;
        ++str;
    }
    return true;
}

void readData(Bank_Client &client)
{
    char clientLogin[100];
    cout << "Введите login: ";
    cin.ignore();
    cin.getline(clientLogin, 100);
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.login = new char[strlen(clientLogin) + 1];
    strcpy(client.login, clientLogin);

    char clientPass[50];
    cout << "Введите пароль: ";
    cin.getline(clientPass, 50);
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.password = new char[strlen(clientPass) + 1];
    strcpy(client.password, clientPass);

    cout << "Введите сумму на счёте: ";
    string balanceInput;
    while (true)
    {
        getline(cin, balanceInput);
        if (balanceInput.empty())
        {
            cout << "Ошибка ввода. Повторите ввод: ";
            continue;
        }
        if (!isDigit(balanceInput.c_str()))
        {
            cout << "Ошибка ввода. Введите только цифры: ";
            continue;
        }
        break;
    }
    client.dBalance = stod(balanceInput); // Преобразовываем строку в double

    char clientAddress[100];
    cout << "Введите адрес: ";
    cin.getline(clientAddress, 100);
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        readData(client);
        return;
    }
    client.address = new char[strlen(clientAddress) + 1];
    strcpy(client.address, clientAddress);

    char clientEmail[100];
    cout << "Введите email: ";
    cin >> clientEmail;
    if (cin.fail())
    {
        cout << "Ошибка ввода" << endl;
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
    cout << "Баланс: " << client->dBalance << endl;
    cout << "Адрес: " << client->address << endl;
    cout << "Email: " << client->email << endl;
    cout << "Password: " << client->password << endl;
}

void printClient(Bank_Client *client, int maxLoginLength, int maxBalanceLength, int maxAddressLength,
                 int maxEmailLength, int maxPasswordLength)
{
    cout << "| " << right << setw(maxLoginLength) << client->login << " | " << setw(maxBalanceLength)
         << client->dBalance << " | " << setw(maxAddressLength) << client->address << " | " << setw(maxEmailLength)
         << client->email << " | " << setw(maxPasswordLength) << client->password << " |\n";
}

void Show(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Стек пуст" << endl;
    }
    else
    {
        int maxLoginLength = 15, maxBalanceLength = 15, maxAddressLength = 15, maxEmailLength = 15,
            maxPasswordLength = 15;

        Node *current = stack->top;
        while (current != nullptr)
        {
            maxLoginLength = std::max(maxLoginLength, static_cast<int>(strlen(current->data->login)));
            maxBalanceLength =
                std::max(maxBalanceLength, static_cast<int>(std::to_string(current->data->dBalance).length()));
            maxAddressLength = std::max(maxAddressLength, static_cast<int>(strlen(current->data->address)));
            maxEmailLength = std::max(maxEmailLength, static_cast<int>(strlen(current->data->email)));
            maxPasswordLength = std::max(maxPasswordLength, static_cast<int>(strlen(current->data->password)));
            current = current->next;
        }

        cout << "+-" << string(maxLoginLength, '-') << "-+-" << string(maxBalanceLength, '-') << "-+-"
             << string(maxAddressLength, '-') << "-+-" << string(maxEmailLength, '-') << "-+-"
             << string(maxPasswordLength, '-') << "-+\n";
        cout << "| " << right << setw(maxLoginLength) << "Логин"
             << " | " << setw(maxBalanceLength) << "Баланс"
             << " | " << setw(maxAddressLength) << "Адрес"
             << " | " << setw(maxEmailLength) << "Эл. почта"
             << " | " << setw(maxPasswordLength) << "Пароль"
             << " |\n";
        cout << "+-" << string(maxLoginLength, '-') << "-+-" << string(maxBalanceLength, '-') << "-+-"
             << string(maxAddressLength, '-') << "-+-" << string(maxEmailLength, '-') << "-+-"
             << string(maxPasswordLength, '-') << "-+\n";

        current = stack->top;
        while (current != nullptr)
        {
            printClient(current->data, maxLoginLength, maxBalanceLength, maxAddressLength, maxEmailLength,
                        maxPasswordLength);
            current = current->next;
        }

        cout << "+-" << string(maxLoginLength, '-') << "-+-" << string(maxBalanceLength, '-') << "-+-"
             << string(maxAddressLength, '-') << "-+-" << string(maxEmailLength, '-') << "-+-"
             << string(maxPasswordLength, '-') << "-+\n";
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
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
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
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите символ." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return input;
        }
    }
}
