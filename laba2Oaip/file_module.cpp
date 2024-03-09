#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>

#include "file_module.h"

using namespace std;

void remove_DB(const char *filename)
{
    if (remove(filename) != 0)
    {
        perror("Ошибка удаления файла");
    }
    else
    {
        cout << "Файл успешно удален." << endl;
    }
}

void save_DB(Stack *stack, const char *filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    Node *current = stack->top;
    while (current != nullptr)
    {
        outFile << "Login: " << current->data->login << endl;
        outFile << "Password: " << current->data->password << endl;
        outFile << "Balance: " << current->data->dBalance << endl;
        outFile << "Email: " << current->data->email << endl;
        outFile << "Address: " << current->data->address << endl;
        outFile << "-----------------------" << endl;
        current = current->next;
    }
    cout << "Данные успешно сохранены в файл." << endl;
}

// Функция загрузки данных из файла
void load_DB(Stack *stack, const char *filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    clear(stack);

    Bank_Client *client = nullptr;
    char buffer[1000];
    while (inFile.getline(buffer, 1000))
    {
        if (strncmp(buffer, "Login: ", 7) == 0)
        {
            client = new Bank_Client;
            client->login = (char *)malloc((strlen(buffer + 7) + 1) * sizeof(char));
            strcpy(client->login, buffer + 7);
        }
        else if (strncmp(buffer, "Password: ", 10) == 0)
        {
            client->password = (char *)malloc((strlen(buffer + 10) + 1) * sizeof(char));
            strcpy(client->password, buffer + 10);
        }
        else if (strncmp(buffer, "Balance: ", 9) == 0)
        {
            client->dBalance = atof(buffer + 9);
        }
        else if (strncmp(buffer, "Email: ", 7) == 0)
        {
            client->email = (char *)malloc((strlen(buffer + 7) + 1) * sizeof(char));
            strcpy(client->email, buffer + 7);
        }
        else if (strncmp(buffer, "Address: ", 9) == 0)
        {
            client->address = (char *)malloc((strlen(buffer + 9) + 1) * sizeof(char));
            strcpy(client->address, buffer + 9);
            push(stack, client);
        }
    }
    cout << "Данные успешно загружены из файла." << endl;
}

ofstream new_DB(const char *filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Ошибка открытия файла для записи." << endl;
        return ofstream();
    }
    cout << "Новый файл базы данных успешно создан." << endl;
    return outFile;
}
