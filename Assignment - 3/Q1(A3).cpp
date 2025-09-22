#include <iostream>
#include <stack>
#define MAX 10
using namespace std;

class Stack
{
    int top;
    int arr[MAX];

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "overflow" << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow" << endl;
        }
        else
        {
            cout << "popped : " << arr[top--] << endl;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == MAX - 1);
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "empty stack" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i];
            }
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "empty stack" << endl;
        }
        else
        {
            cout << "top: " << arr[top] << endl;
        }
    }
};
int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. display" << endl;
        cout << "7. exit" << endl;
        cout << "enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            if (s.isEmpty())
                cout << " empty stack" << endl;
            else
                cout << "stack is not empty." << endl;
            break;
        case 5:
            if (s.isFull())
                cout << "stack is full." << endl;
            else
                cout << "stack is not full." << endl;
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "Invalid " << endl;
        }
    } while (choice != 7);

    return 0;
}
