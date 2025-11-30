#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class HashSet
{
    int table[100];
    bool occupied[100];
    int size;

public:
    HashSet()
    {
        size = 100;
        for (int i = 0; i < size; i++)
        {
            occupied[i] = false;
        }
    }

    int hashFunction(int key)
    {
        if (key < 0)
        {
            return (key * -1) % size;
        }
        return key % size;
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        int startIndex = index;

        while (occupied[index])
        {
            if (table[index] == key)
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

    void insert(int key)
    {
        int index = hashFunction(key);

        while (occupied[index])
        {
            if (table[index] == key)
            {
                return;
            }
            index = (index + 1) % size;
        }

        table[index] = key;
        occupied[index] = true;
    }
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool checkDuplicates(Node *root, HashSet &hashSet)
{
    if (root == NULL)
    {
        return false;
    }

    if (hashSet.search(root->data))
    {
        return true;
    }

    hashSet.insert(root->data);

    bool leftDuplicate = checkDuplicates(root->left, hashSet);
    bool rightDuplicate = checkDuplicates(root->right, hashSet);

    return leftDuplicate || rightDuplicate;
}

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "How many nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Tree (Inorder): ";
    inorder(root);
    cout << endl;

    HashSet hashSet;

    if (checkDuplicates(root, hashSet))
    {
        cout << "Output: true" << endl;
        cout << "Duplicates Found" << endl;
    }
    else
    {
        cout << "Output: false" << endl;
        cout << "No Duplicates" << endl;
    }

    return 0;
}