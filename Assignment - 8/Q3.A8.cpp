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
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        cout << "Duplicate value not allowed" << endl;
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        cout << "Value not found" << endl;
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
}

int minDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    if (root->left == NULL)
    {
        return minDepth(root->right) + 1;
    }

    if (root->right == NULL)
    {
        return minDepth(root->left) + 1;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth < rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
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
    int choice, value;

    while (true)
    {
        cout << "\n1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Maximum Depth" << endl;
        cout << "4. Minimum Depth" << endl;
        cout << "5. Display BST" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "Element inserted" << endl;
            break;

        case 2:
            if (root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
            }
            break;

        case 3:
            if (root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                cout << "Maximum Depth: " << maxDepth(root) << endl;
            }
            break;

        case 4:
            if (root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                cout << "Minimum Depth: " << minDepth(root) << endl;
            }
            break;

        case 5:
            if (root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                cout << "BST (Inorder): ";
                inorder(root);
                cout << endl;
            }
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}