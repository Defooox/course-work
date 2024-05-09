#ifndef IO_MODULE_H
#define IO_MODULE_H

#include "stack_module.h"
#include <cstring>
#include <iostream>
#include <limits>

bool isDigit(const char *str);

void readData(Bank_Client &client);
void printData(Bank_Client *client);
void printClient(Bank_Client *client);
void Show(Stack *stack);

int getIntInput();
char getCharInput();

#endif // IO_MODULE_H