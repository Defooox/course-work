#include "menu_module.h"
#include "io_module.h"

#include <iostream>

using namespace std;

void displayMenu(Stack *stack)
{
    int choice;
    do
    {
        cout << "����:" << endl;
        cout << "1. ������� ������ �������" << endl;
        cout << "2. ������� ������ � ������� '����: ��������'" << endl;
        cout << "3. ������� ������ � ��������� �������" << endl;
        cout << "4. ��������� ������ � ����" << endl;
        cout << "5. ��������� ������ �� �����" << endl;
        cout << "6. ������� ���� ���� ������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";


        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������: ������� �������� ��������" << endl;
            cout << "�������� ��������: ";
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
                cout << "������� ����� ������� � �����: ";
                cin >> index;
                Bank_Client *client = GetClientIndex(stack, index);
                if (client != nullptr)
                {
                    cout << "������ �������: " << endl;
                    printData(client);
                }
                else
                {
                    cout << "������ � ��������� ������� �� ������" << endl;
                }
            }
            else
            {
                cout << "���� ����" << endl;
            }
            break;
        }
        case 3: {
            if (!isEmpty(stack))
            {    
                cout << "������ �������� � ��������� �������:" << endl;

                Show(stack);
            }
            else
            {
                cout << "���� ����" << endl;
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
            cout << "�����" << endl;
            break;
        default:
            cout << "������������ ����" << endl;
            break;
        }
    } while (choice != 0);
}
