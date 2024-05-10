#define _CRT_SECURE_NO_WARNINGS

#include "stack_module.h"
#include "io_module.h"

#include <iostream>

using namespace std;

int getStackSize(Stack *stack);

bool isEmpty(Stack *stack)
{
    return stack->top == nullptr;
}

void push(Stack *stack, Bank_Client *data)
{
    Node *newNode = new Node(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        delete temp;
    }
    else
    {
        cout << "Стек пуст" << endl;
    }
}
void deleteClient(Stack *stack, int index)
{
    int stackSize = getStackSize(stack);
    if (index < 0 || index >= stackSize)
    {
        cout << "Ошибка: неверный индекс" << endl;
        return;
    }

    Node *current = stack->top;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    if (prev == nullptr)
    {
        stack->top = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
    cout << "Клиент удален" << endl;
}


Bank_Client *GetClientIndex(Stack *stack, int index)
{
    if (isEmpty(stack))
    {
        return nullptr;
    }
    Node *current = stack->top;
    int count = 0;

    while (current != nullptr)
    {
        if (count == index)
        {
            return current->data;
        }
        current = current->next;
        count++;
    }
    return nullptr;
}

void clear(Stack *stack)
{
    while (!isEmpty(stack))
    {
        Bank_Client *client = stack->top->data;
        free(client->login);
        free(client->password);
        free(client->address);
        free(client->email);
        delete client;
        pop(stack);
    }
}

void sortStack(Stack *stack, int fieldChoice, int ascending)
{
    Stack tempStack;
    tempStack.top = nullptr;

    while (!isEmpty(stack))
    {
        Bank_Client *topClient = stack->top->data;
        pop(stack);

        if (ascending == 1)
        {

            while (!isEmpty(&tempStack) && compareClients(tempStack.top->data, topClient, fieldChoice) > 0)
            {

                push(stack, tempStack.top->data);
                pop(&tempStack);
            }
        }
        else
        {

            while (!isEmpty(&tempStack) && compareClients(tempStack.top->data, topClient, fieldChoice) < 0)
            {

                push(stack, tempStack.top->data);
                pop(&tempStack);
            }
        }

        push(&tempStack, topClient);
    }

    while (!isEmpty(&tempStack))
    {
        push(stack, tempStack.top->data);
        pop(&tempStack);
    }
}

int compareClients(Bank_Client *a, Bank_Client *b, int fieldChoice)
{
    switch (fieldChoice)
    {
    case 1:
        return strcmp(a->login, b->login);
    case 2:
        return strcmp(a->email, b->email);
    case 3:
        if (a->dBalance < b->dBalance)
            return -1;
        if (a->dBalance > b->dBalance)
            return 1;
        return 0;
    case 4:
        return strcmp(a->password, b->password);
    case 5:
        return strcmp(a->address, b->address);
    default:
        return 0;
    }
}

int getStackSize(Stack *stack)
{
    int size = 0;
    Node *current = stack->top;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}

void updateClient(Stack *stack, int index, const Bank_Client &newClientData)
{
    int stackSize = getStackSize(stack);
    if (index < 0 || index >= stackSize)
    {
        cout << "Ошибка: неверный индекс" << endl;
        return;
    }

    Node *current = stack->top;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    free(current->data->address);
    free(current->data->email);
    free(current->data->login);
    free(current->data->password);

    current->data->login = new char[strlen(newClientData.login) + 1];
    strcpy(current->data->login, newClientData.login);

    current->data->password = new char[strlen(newClientData.password) + 1];
    strcpy(current->data->password, newClientData.password);

    current->data->dBalance = newClientData.dBalance;

    current->data->address = new char[strlen(newClientData.address) + 1];
    strcpy(current->data->address, newClientData.address);
    
    current->data->email = new char[strlen(newClientData.email) + 1];
    strcpy(current->data->email, newClientData.email);

    cout << "Данные клиента обновлены" << endl;
}


void findAllClients(Stack *stack, char *searchValue, int fieldIndex)
{
    sortStack(stack, fieldIndex, 1);
    if (searchValue == nullptr || *searchValue == '\0')
    {
        cout << "Ошибка: Невалидное значение для поиска" << endl;
        return;
    }

    if (fieldIndex < 1 || fieldIndex > 2)
    {
        cout << "Ошибка: Невалидный индекс поля" << endl;
        return;
    }

    int stackSize = getStackSize(stack);
    bool foundMatchingClients = false;

    for (int index = 0; index < stackSize; ++index)
    {
        Bank_Client *client = GetClientIndex(stack, index);
        if (client == nullptr)
        {
            cout << "Ошибка: Не удалось получить клиента с индексом " << index << endl;
            continue;
        }

        const char *fieldToSearch = nullptr;
        switch (fieldIndex)
        {
        case 1:
            fieldToSearch = client->login;
            break;
        case 2:
            fieldToSearch = client->email;
            break;
        case 3:
            fieldToSearch = client->password;
        case 4:
            fieldToSearch = client->address;
        default:
            cout << "Ошибка: Невалидный индекс поля" << endl;
            return;
        }

        if (strcmp(fieldToSearch, searchValue) == 0)
        {
            printData(client);
            foundMatchingClients = true;
        }
        else if (strcmp(fieldToSearch, searchValue) > 0)
        {
            break;
        }
    }

    if (!foundMatchingClients)
    {
        cout << "Совпадений не найдено" << endl;
    }
}
