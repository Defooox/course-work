#include "stack_module.h"
#include "io_module.h"

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

Node *findMiddle(Node *low, Node *high)
{
    if (low == nullptr)
    {
        return nullptr;
    }

    Node *slow = low;
    Node *fast = low;

    while (fast != high && fast->next != high)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}



Node *partition(Node *low, Node *high, int fieldIndex, bool ascending)
{
    // Найдите средний узел между low и high
    Node *middleNode = findMiddle(low, high);
    Bank_Client *warp = middleNode->data;

    // Используем i = low вместо i = low->next
    Node *i = low;

    for (Node *j = low; j != high; j = j->next)
    {
        int cmpResult;
        switch (fieldIndex)
        {
        case 1:
            cmpResult = strcmp(j->data->login, warp->login);
            break;
        case 2:
            cmpResult = strcmp(j->data->password, warp->password);
            break;
        case 3:
            cmpResult = (j->data->dBalance < warp->dBalance) ? -1 : ((j->data->dBalance > warp->dBalance) ? 1 : 0);
            break;
        case 4:
            cmpResult = strcmp(j->data->address, warp->address);
            break;
        case 5:
            cmpResult = strcmp(j->data->email, warp->email);
            break;
        default:
            return nullptr;
        }

        if ((ascending && cmpResult < 0) || (!ascending && cmpResult > 0))
        {
            // Переключение данных между i и j
            Bank_Client *temp = i->data;
            i->data = j->data;
            j->data = temp;
            // Смещение указателя i на следующий узел
            i = i->next;
        }
    }

    // Меняем данные узлов i и high
    Bank_Client *temp = i->data;
    i->data = high->data;
    high->data = temp;

    return i;
}


void quickSortUtil(Node *low, Node *high, int fieldIndex, bool ascending)
{
    if (low != nullptr && high != nullptr && low != high && low != high->next)
    {

        Node *pi = partition(low, high, fieldIndex, ascending);

        quickSortUtil(low, pi->next, fieldIndex, ascending);
        quickSortUtil(pi->next, high, fieldIndex, ascending);
    }
}

void quickSort(Stack *stack, int fieldIndex, bool ascending)
{

    Node *high = stack->top;
    while (high->next != nullptr)
        high = high->next;

    quickSortUtil(stack->top, high, fieldIndex, ascending);
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

int binarySearch(Stack *stack, char *searchValue, int fieldIndex)
{
    int low = 0;
    int high = getStackSize(stack) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        Bank_Client *midClient = GetClientIndex(stack, mid);

        if (midClient != nullptr)
        {
            int cmpResult = 0;
            switch (fieldIndex)
            {
            case 1:
                cmpResult = strcmp(midClient->login, searchValue);
                break;
            case 4:
                cmpResult = strcmp(midClient->address, searchValue);
                break;
            default:
                return -1;
            }

            if (cmpResult == 0)
            {
                return mid;
            }
            else if (cmpResult < 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            return -1;
        }
    }

    return -1;
}

void findAllClients(Stack *stack, char *searchValue, int fieldIndex)
{

    bool foundMatchingClients = false;

    cout << "Клиенты с одинаковым значением: " << endl;

    Node *currentNode = stack->top;
    while (currentNode != nullptr)
    {
        Bank_Client *client = currentNode->data;

        int cmpResult = 0;
        if (fieldIndex == 1)
        {
            cmpResult = strcmp(client->login, searchValue);
        }
        else if (fieldIndex == 4)
        {
            cmpResult = strcmp(client->address, searchValue);
        }

        if (cmpResult == 0)
        {
            printData(client);
            foundMatchingClients = true;
        }

        currentNode = currentNode->next;
    }

    if (!foundMatchingClients)
    {
        cout << "Клиентов с таким значением не найдено" << endl;
    }
}
