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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int n, value, choice;

    cout << "How many nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insertNode(root, value);
    }

    while (true)
    {
        cout << "\n1. Preorder Traversal" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 2:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}