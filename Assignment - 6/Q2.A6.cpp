#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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

    void displayWithRepeat()
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

        cout << head->data << endl;
    }
};

int main()
{
    CircularLinkedList list;
    int n, value;

    cout << "How many nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insert(value);
    }

    cout << "Output: ";
    list.displayWithRepeat();

    return 0;
}