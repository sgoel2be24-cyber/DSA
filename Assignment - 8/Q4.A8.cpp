#include <iostream>
#include <climits>
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

bool isBSTHelper(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data <= minValue || root->data >= maxValue)
    {
        return false;
    }

    return isBSTHelper(root->left, minValue, root->data) &&
           isBSTHelper(root->right, root->data, maxValue);
}

bool isBST(Node *root)
{
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

Node *insertAnyWhere(Node *root, int value, char position)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (position == 'l' || position == 'L')
    {
        root->left = createNode(value);
    }
    else if (position == 'r' || position == 'R')
    {
        root->right = createNode(value);
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
    int choice, value, parent;
    char position;

    cout << "Create a Binary Tree" << endl;
    cout << "Enter root value: ";
    cin >> value;
    root = createNode(value);

    while (true)
    {
        cout << "\n1. Insert Node" << endl;
        cout << "2. Check if BST" << endl;
        cout << "3. Display Tree (Inorder)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter parent node value: ";
            cin >> parent;
            cout << "Enter position (L for left, R for right): ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;

            if (root->data == parent)
            {
                insertAnyWhere(root, value, position);
                cout << "Node inserted" << endl;
            }
            else
            {
                Node *temp = root;
                bool found = false;

                if (temp->left != NULL && temp->left->data == parent)
                {
                    insertAnyWhere(temp->left, value, position);
                    found = true;
                }
                else if (temp->right != NULL && temp->right->data == parent)
                {
                    insertAnyWhere(temp->right, value, position);
                    found = true;
                }

                if (found)
                {
                    cout << "Node inserted" << endl;
                }
                else
                {
                    cout << "Parent not found at this level" << endl;
                }
            }
            break;

        case 2:
            if (isBST(root))
            {
                cout << "The tree is a BST" << endl;
            }
            else
            {
                cout << "The tree is NOT a BST" << endl;
            }
            break;

        case 3:
            cout << "Tree (Inorder): ";
            inorder(root);
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