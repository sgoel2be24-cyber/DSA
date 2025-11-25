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
    CircularLinkedList() { head = NULL; }

    void insertFirst(int value)
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
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at beginning" << endl;
    }

    void insertLast(int value)
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
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted at end" << endl;
    }

    void insertAfter(int target, int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->data == target)
            {
                Node *newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted after " << target << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == value)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                Node *toDelete = head;
                head = head->next;
                delete toDelete;
            }
            cout << "Deleted" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->next->data == value)
            {
                Node *toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Deleted" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void search(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == value)
            {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not found" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        cout << "List: ";
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
    DoublyLinkedList() { head = NULL; }

    void insertFirst(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        cout << "Inserted at beginning" << endl;
    }

    void insertLast(int value)
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
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted at end" << endl;
    }

    void insertAfter(int target, int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                Node *newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                cout << "Inserted after " << target << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void insertBefore(int target, int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == target)
        {
            insertFirst(value);
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                Node *newNode = new Node();
                newNode->data = value;
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                cout << "Inserted before " << target << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        if (head->data == value)
        {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            cout << "Deleted" << endl;
            return;
        }

        while (temp != NULL && temp->data != value)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        delete temp;
        cout << "Deleted" << endl;
    }

    void search(int value)
    {
        Node *temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found" << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        cout << "List: ";
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
    int choice, listType, value, target;

    while (true)
    {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert after node\n";
        cout << "4. Insert before node\n5. Delete node\n6. Search\n7. Display\n8. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 8)
            break;

        cout << "List type (1-Circular, 2-Doubly): ";
        cin >> listType;

        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> value;
            listType == 1 ? clist.insertFirst(value) : dlist.insertFirst(value);
            break;
        case 2:
            cout << "Value: ";
            cin >> value;
            listType == 1 ? clist.insertLast(value) : dlist.insertLast(value);
            break;
        case 3:
            cout << "Target: ";
            cin >> target;
            cout << "Value: ";
            cin >> value;
            listType == 1 ? clist.insertAfter(target, value) : dlist.insertAfter(target, value);
            break;
        case 4:
            if (listType == 2)
            {
                cout << "Target: ";
                cin >> target;
                cout << "Value: ";
                cin >> value;
                dlist.insertBefore(target, value);
            }
            else
                cout << "Only for Doubly list" << endl;
            break;
        case 5:
            cout << "Value: ";
            cin >> value;
            listType == 1 ? clist.deleteNode(value) : dlist.deleteNode(value);
            break;
        case 6:
            cout << "Value: ";
            cin >> value;
            listType == 1 ? clist.search(value) : dlist.search(value);
            break;
        case 7:
            listType == 1 ? clist.display() : dlist.display();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}