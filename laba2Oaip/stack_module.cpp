#include "stack_module.h"

#include <iostream>

using namespace std;

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