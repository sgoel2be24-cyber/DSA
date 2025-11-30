#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class HashSet
{
    Node *table[100];
    bool occupied[100];
    int size;

public:
    HashSet()
    {
        size = 100;
        for (int i = 0; i < size; i++)
        {
            occupied[i] = false;
            table[i] = NULL;
        }
    }

    int hashFunction(Node *ptr)
    {
        long long address = (long long)ptr;
        return (address % size);
    }

    bool search(Node *ptr)
    {
        int index = hashFunction(ptr);
        int startIndex = index;

        while (occupied[index])
        {
            if (table[index] == ptr)
            {
                return true;
            }
            index = (index + 1) % size;

            if (index == startIndex)
            {
                break;
            }
        }

        return false;
    }

    void insert(Node *ptr)
    {
        int index = hashFunction(ptr);

        while (occupied[index])
        {
            if (table[index] == ptr)
            {
                return;
            }
            index = (index + 1) % size;
        }

        table[index] = ptr;
        occupied[index] = true;
    }
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

bool detectLoop(Node *head)
{
    HashSet hashSet;
    Node *temp = head;

    while (temp != NULL)
    {
        if (hashSet.search(temp))
        {
            return true;
        }
        hashSet.insert(temp);
        temp = temp->next;
    }

    return false;
}

void display(Node *head)
{
    Node *temp = head;
    int count = 0;

    cout << "List: ";
    while (temp != NULL && count < 10)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    if (count == 10)
    {
        cout << "...";
    }
    cout << endl;
}

int main()
{
    int n, value, loopPos;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;
    Node *nodes[20];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        Node *newNode = createNode(value);
        nodes[i] = newNode;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Create a loop? (1 for Yes, 0 for No): ";
    cin >> loopPos;

    if (loopPos == 1)
    {
        int pos;
        cout << "Enter position to create loop (0 to " << n - 1 << "): ";
        cin >> pos;
        if (pos >= 0 && pos < n)
        {
            tail->next = nodes[pos];
            cout << "Loop created at position " << pos << endl;
        }
    }

    if (detectLoop(head))
    {
        cout << "Output: true" << endl;
        cout << "Loop detected in the linked list" << endl;
    }
    else
    {
        cout << "Output: false" << endl;
        cout << "No loop detected in the linked list" << endl;
    }

    return 0;
}