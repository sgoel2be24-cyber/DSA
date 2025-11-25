#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insert(char value)
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

    bool checkPalindrome()
    {
        if (head == NULL)
        {
            return true;
        }

        Node *start = head;
        Node *end = head;

        while (end->next != NULL)
        {
            end = end->next;
        }

        while (start != end && start->prev != end)
        {
            if (start->data != end->data)
            {
                return false;
            }
            start = start->next;
            end = end->prev;
        }

        return true;
    }
};

int main()
{
    DoublyLinkedList list;
    int n;
    char ch;

    cout << "How many characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        list.insert(ch);
    }

    cout << "List: ";
    list.display();

    if (list.checkPalindrome())
    {
        cout << "The list is a palindrome" << endl;
    }
    else
    {
        cout << "The list is not a palindrome" << endl;
    }

    return 0;
}