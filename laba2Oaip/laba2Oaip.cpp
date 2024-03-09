#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "menu_module.h"
#include "stack_module.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    Stack stackClients;
    stackClients.top = nullptr;

    displayMenu(&stackClients);

    clear(&stackClients);

}