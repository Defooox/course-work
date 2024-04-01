#define _CRT_SECURE_NO_WARNINGS

#define strdup _strdup

#include <cstring>
#include <fstream>
#include <iostream>

#include "file_module.h"
#include <string>

using namespace std;

void remove_DB(const char *filename)
{
    if (remove(filename) != 0)
    {
        perror("������ �������� �����");
    }
    else
    {
        cout << "���� ������� ������." << endl;
    }
}

void save_DB(Stack *stack, const char *filename)
{
    std::ofstream fout(filename);

    if (!fout.is_open())
    {
        std::cout << "������ �������� ����� ��� ������ " << std::endl;
        return;
    }

    Node *current = stack->top;
    while (current != nullptr)
    {
        fout << current->data->login << std::endl;
        fout << current->data->password << std::endl;
        fout << current->data->dBalance << std::endl;
        fout << current->data->email << std::endl;
        fout << current->data->address << std::endl;
        current = current->next;
    }

    std::cout << "������ ������� ��������� � ����." << std::endl;
}

void load_DB(Stack *stack, const char *filename)
{
    std::ifstream fin(filename);

    if (!fin.is_open())
    {
        std::cout << "������ �������� ����� ��� ������" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line))
    {
        Bank_Client *client = new Bank_Client;
        client->login = strdup(line.c_str());
        std::getline(fin, line);
        client->password = strdup(line.c_str());
        std::getline(fin, line);
        client->dBalance = std::stoi(line);
        std::getline(fin, line);
        client->email = strdup(line.c_str());
        std::getline(fin, line);
        client->address = strdup(line.c_str());
        push(stack, client);
    }

    fin.close();
    std::cout << "������ ������� ��������� �� �����" << std::endl;
}

ofstream new_DB(const char *filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cout << "������ �������� ����� ��� ������" << endl;
        return ofstream();
    }
    cout << "����� ���� ���� ������ ������� ������ " << endl;
    return outFile;
}
