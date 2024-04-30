#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "menu_module.h"
#include "stack_module.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    Stack stackClients;
    stackClients.top = nullptr;

    displayMenu(&stackClients);

    clear(&stackClients);
}