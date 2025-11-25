#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertCircular(int value)
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

    void insertNormal(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
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
        }
    }

    bool isCircular()
    {
        if (head == NULL)
        {
            return false;
        }

        Node *temp = head->next;

        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }

        if (temp == head)
        {
            return true;
        }

        return false;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        int count = 0;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        } while (temp != head && temp != NULL && count < 20);

        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, n, value;

    cout << "1. Create Circular Linked List" << endl;
    cout << "2. Create Normal Linked List" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "How many elements: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (choice == 1)
        {
            list.insertCircular(value);
        }
        else
        {
            list.insertNormal(value);
        }
    }

    cout << "List: ";
    list.display();

    if (list.isCircular())
    {
        cout << "The linked list is Circular" << endl;
    }
    else
    {
        cout << "The linked list is not Circular" << endl;
    }

    return 0;
}