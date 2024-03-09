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
    Node(Bank_Client *data) : data(data), next(nullptr)
    {
    }
};

struct Stack
{
    Node *top;
};

bool isEmpty(Stack *stack);
void push(Stack *stack, Bank_Client *data);
void pop(Stack *stack);
Bank_Client *GetClientIndex(Stack *stack, int index);
void clear(Stack *stack);

#endif