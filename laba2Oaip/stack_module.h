#ifndef STACK_MODULE_H
#define STACK_MODULE_H

#include <iostream>

struct Bank_Client
{
    char *login;
    double dBalance;
    char *address;
    char *email;
    char *password;
};


struct Node
{
    Bank_Client *data;
    Node *next;
    Node *prev;
    Node(Bank_Client *data) : data(data), next(nullptr)
    {
    }
};


struct Stack
{
    Node *top;
};

Node *getTail(Stack *stack);

bool isEmpty(Stack *stack);
void push(Stack *stack, Bank_Client *data);
void pop(Stack *stack);
Bank_Client *GetClientIndex(Stack *stack, int index);
void clear(Stack *stack);


Node *partition(Node *low, Node *high, int fieldIndex, bool ascending);
void quickSortUtil(Node *low, Node *high, int fieldIndex, bool ascending);
void quickSort(Stack *stack, int fieldIndex, bool ascending);

int binarySearch(Stack *stack, char *searchValue, int fieldIndex);
void findAllClients(Stack *stack, char *searchValue, int fieldIndex);
int compareField(Bank_Client *client, const char *searchValue, int fieldIndex);
Node *findMiddle(Node *low, Node *high);


#endif