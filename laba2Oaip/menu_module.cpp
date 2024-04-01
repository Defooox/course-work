#include "menu_module.h"
#include "io_module.h"

#include <iostream>

using namespace std;

void displayMenu(Stack *stack)
{
    int choice;
    do
    {
        cout << "Меню:" << endl;
        cout << "1. Создать нового клиента" << endl;
        cout << "2. Вывести данные в формате 'поле: значение'" << endl;
        cout << "3. Вывести данные в табличном формате" << endl;
        cout << "4. Сохранить данные в файл" << endl;
        cout << "5. Загрузить данные из файла" << endl;
        cout << "6. Удалить файл базы данных" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";


        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите числовое значение" << endl;
            cout << "Выберите действие: ";
        }


        switch (choice)
        {
        case 1: {
            Bank_Client *newClient = new Bank_Client;
            readData(*newClient);
            push(stack, newClient);
            break;
        }
        case 2: {
            if (!isEmpty(stack))
            {
                int index;
                cout << "Введите номер клиента в стеке: ";
                cin >> index;
                Bank_Client *client = GetClientIndex(stack, index);
                if (client != nullptr)
                {
                    cout << "Данные клиента: " << endl;
                    printData(client);
                }
                else
                {
                    cout << "Клиент с указанным номером не найден" << endl;
                }
            }
            else
            {
                cout << "Стек пуст" << endl;
            }
            break;
        }
        case 3: {
            if (!isEmpty(stack))
            {    
                cout << "Данные клиентов в табличном формате:" << endl;

                Show(stack);
            }
            else
            {
                cout << "Стек пуст" << endl;
            }
            break;
        }
        case 4: {
            save_DB(stack, "database.txt");
            break;
        }
        case 5: {
            load_DB(stack, "database.txt");
            break;
        }
        case 6: {
            remove_DB("database.txt");
            break;
        }
        case 0:
            cout << "Выход" << endl;
            break;
        default:
            cout << "Некорректный ввод" << endl;
            break;
        }
    } while (choice != 0);
}
