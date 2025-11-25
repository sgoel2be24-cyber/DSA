#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

Node *searchRecursive(Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchRecursive(root->left, key);
    }

    return searchRecursive(root->right, key);
}

Node *searchNonRecursive(Node *root, int key)
{
    Node *temp = root;

    while (temp != NULL && temp->data != key)
    {
        if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return temp;
}

Node *findMin(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *findMax(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

Node *findSuccessor(Node *root, int key)
{
    Node *current = searchNonRecursive(root, key);

    if (current == NULL)
    {
        return NULL;
    }

    if (current->right != NULL)
    {
        return findMin(current->right);
    }

    Node *successor = NULL;
    Node *temp = root;

    while (temp != NULL)
    {
        if (key < temp->data)
        {
            successor = temp;
            temp = temp->left;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }

    return successor;
}

Node *findPredecessor(Node *root, int key)
{
    Node *current = searchNonRecursive(root, key);

    if (current == NULL)
    {
        return NULL;
    }

    if (current->left != NULL)
    {
        return findMax(current->left);
    }

    Node *predecessor = NULL;
    Node *temp = root;

    while (temp != NULL)
    {
        if (key > temp->data)
        {
            predecessor = temp;
            temp = temp->right;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            break;
        }
    }

    return predecessor;
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
    int n, value, choice, key;
    Node *result;

    cout << "How many nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "BST (Inorder): ";
    inorder(root);
    cout << endl;

    while (true)
    {
        cout << "\n1. Search (Recursive)" << endl;
        cout << "2. Search (Non-Recursive)" << endl;
        cout << "3. Find Minimum" << endl;
        cout << "4. Find Maximum" << endl;
        cout << "5. Find Inorder Successor" << endl;
        cout << "6. Find Inorder Predecessor" << endl;
        cout << "7. Display BST" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to search: ";
            cin >> key;
            result = searchRecursive(root, key);
            if (result != NULL)
            {
                cout << "Found " << key << " in BST" << endl;
            }
            else
            {
                cout << key << " not found" << endl;
            }
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> key;
            result = searchNonRecursive(root, key);
            if (result != NULL)
            {
                cout << "Found " << key << " in BST" << endl;
            }
            else
            {
                cout << key << " not found" << endl;
            }
            break;

        case 3:
            result = findMin(root);
            if (result != NULL)
            {
                cout << "Minimum element: " << result->data << endl;
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        case 4:
            result = findMax(root);
            if (result != NULL)
            {
                cout << "Maximum element: " << result->data << endl;
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        case 5:
            cout << "Enter node value: ";
            cin >> key;
            result = findSuccessor(root, key);
            if (result != NULL)
            {
                cout << "Inorder Successor of " << key << " is " << result->data << endl;
            }
            else
            {
                cout << "No successor found" << endl;
            }
            break;

        case 6:
            cout << "Enter node value: ";
            cin >> key;
            result = findPredecessor(root, key);
            if (result != NULL)
            {
                cout << "Inorder Predecessor of " << key << " is " << result->data << endl;
            }
            else
            {
                cout << "No predecessor found" << endl;
            }
            break;

        case 7:
            cout << "BST (Inorder): ";
            inorder(root);
            cout << endl;
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}