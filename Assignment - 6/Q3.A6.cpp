#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getSize()
    {
        if (head == NULL)
        {
            return 0;
        }

        int count = 0;
        Node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    CircularLinkedList clist;
    DoublyLinkedList dlist;
    int choice, n, value;

    while (true)
    {
        cout << "\n1. Circular Linked List" << endl;
        cout << "2. Doubly Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        cout << "How many elements: ";
        cin >> n;

        cout << "Enter values: ";
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            if (choice == 1)
            {
                clist.insert(value);
            }
            else
            {
                dlist.insert(value);
            }
        }

        if (choice == 1)
        {
            cout << "Circular List: ";
            clist.display();
            cout << "Size: " << clist.getSize() << endl;
        }
        else
        {
            cout << "Doubly List: ";
            dlist.display();
            cout << "Size: " << dlist.getSize() << endl;
        }
    }

    return 0;
}