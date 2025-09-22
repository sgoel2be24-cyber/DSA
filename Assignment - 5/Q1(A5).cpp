#include <iostream>
using namespace std;

struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll *node;

node head = NULL;
node tail = NULL;

void insertBegin()
{
    node temp = new ll;
    cout << "Enter value: ";
    cin >> temp->data;
    temp->next = head;
    head = temp;
    if (tail == NULL)
        tail = head;
}

void insertEnd()
{
    if (head == NULL)
    {
        insertBegin();
        return;
    }
    tail->next = new ll;
    cout << "Enter value: ";
    cin >> tail->next->data;
    tail->next->next = NULL;
    tail = tail->next;
}

void insertBefore(int val)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == val)
    {
        insertBegin();
        return;
    }
    node temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found.\n";
        return;
    }
    node newNode = new ll;
    cout << "Enter value to insert: ";
    cin >> newNode->data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int val)
{
    node temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value not found.\n";
        return;
    }
    node newNode = new ll;
    cout << "Enter value to insert: ";
    cin >> newNode->data;
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail)
        tail = newNode;
}

void deleteBegin()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node temp = head;
    head = head->next;
    delete temp;
    if (head == NULL)
        tail = NULL;
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = tail = NULL;
        return;
    }
    node temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
}

void deleteSpecific(int val)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == val)
    {
        deleteBegin();
        return;
    }
    node temp = head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Value not found.\n";
        return;
    }
    node delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == tail)
        tail = temp;
    delete delNode;
}

void searchNode(int val)
{
    node temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, val;
    while (1)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertBegin();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            cout << "Enter value before which to insert: ";
            cin >> val;
            insertBefore(val);
            break;
        case 4:
            cout << "Enter value after which to insert: ";
            cin >> val;
            insertAfter(val);
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteSpecific(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
