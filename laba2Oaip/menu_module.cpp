#include "menu_module.h"
#include "io_module.h"
#include "stack_module.h"

#include <iomanip>
#include <iostream>

using namespace std;

void displayMenu(Stack *stack)
{

    int choice;
    do
    {
        cout << "/------------------------------------------------------------------------------" << endl;
        cout << "| Меню:                                                                        |" << endl;
        cout << "| 1. Создать нового клиента                                                    |" << endl;
        cout << "| 2. Вывести данные в формате 'поле: значение'                                 |" << endl;
        cout << "| 3. Вывести данные в табличном формате                                        |" << endl;
        cout << "| 4. Сохранить данные в файл                                                   |" << endl;
        cout << "| 5. Загрузить данные из файла                                                 |" << endl;
        cout << "| 6. Удалить файл базы данных                                                  |" << endl;
        cout << "| 7. Отсортиворать данные                                                      |" << endl;
        cout << "| 8. Поиск клиента                                                             |" << endl;
        cout << "| 9. Удалить клиента по индексу                                                |" << endl;
        cout << "| 10. Изменить данные клиента                                                  |" << endl;
        cout << "| 0. Выход                                                                     |" << endl;
        cout << "-------------------------------------------------------------------------------/" << endl;
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
        case 7: {
            if (isEmpty(stack))
            {
                Show(stack);
                break;
            }
            int ascending;
            int fieldChoice;
            do
            {
                cout << "Выберите поле для сортировки:" << endl;
                cout << "1. Login" << endl;
                cout << "2. Email" << endl;
                cout << "3. Баланс" << endl;
                cout << "4. Пароль" << endl;
                cout << "5. Адрес" << endl;
                cout << "Выберите поле: ";
                fieldChoice = getIntInput();

                if (fieldChoice < 1 || fieldChoice > 5)
                {
                    cout << "Ошибка: Невалидный выбор поля" << endl;
                }
            } while (fieldChoice < 1 || fieldChoice > 5);

            do
            {

                cout << "Выберите направление сортировки:" << endl;
                cout << "1. По возрастанию" << endl;
                cout << "2. По убыванию" << endl;
                cout << "Выберите направление: ";
                ascending = getIntInput();

                if (ascending != 1 && ascending != 2)
                {
                    cout << "Ошибка: Некорректный ввод" << endl;
                    continue;
                }

            } while (ascending != 1 && ascending != 2);

            sortStack(stack, fieldChoice, ascending);

            cout << "Данные отсортированы" << endl;
            

            Show(stack);
            break;
        }

        case 8: {
            if (!isEmpty(stack))
            {

                int fieldChoice;
                do
                {

                    cout << "Выберите поле для поиска:" << endl;
                    cout << "1. Login" << endl;
                    cout << "2. Email" << endl;
                    cout << "3. Пароль" << endl;
                    cout << "4. Адрес" << endl;
                    cout << "Выберите поле: ";
                    fieldChoice = getIntInput();

                } while (fieldChoice < 1 || fieldChoice > 5);

                char searchValue[256];
                cout << "Введите значение для поиска: ";
                cin.ignore();
                cin.getline(searchValue, 256);

                findAllClients(stack, searchValue, fieldChoice);
            }
            else
            {
                cout << "Стек пуст" << endl;
            }

            break;
        }

        case 9: {
            if (!isEmpty(stack))
            {
                int index;
                cout << "Введите номер клиента для удаления: ";
                cin >> index;
                deleteClient(stack, index);
            }
            else
            {
                cout << "Стек пуст" << endl;
            }
            break;
        }

             case 10: { // Добавляем новый пункт 10 для обновления клиента
            if (!isEmpty(stack))
            {
                int index;
                cout << "Введите номер клиента для обновления: ";
                cin >> index;
                Bank_Client newClientData;
                readData(newClientData);
                updateClient(stack, index, newClientData);
            }
            else
            {
                cout << "Стек пуст" << endl;
            }
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
