#include <iostream>
#define MAX 7
using namespace std;

class circularQueue
{
private:
    int arr[MAX];
    int front, rear;

public:
    circularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "queue is full " << x << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " added to the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        cout << arr[front] << " removed from the queue" << endl;

        if (front == rear)
        {

            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main()
{
    circularQueue c;
    int choice, value;

    do
    {

        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter value to enqueue: ";
            cin >> value;
            c.enqueue(value);
            break;
        case 2:
            c.dequeue();
            break;
        case 3:
            c.peek();
            break;
        case 4:
            c.display();
            break;
        case 5:
            if (c.isEmpty())
                cout << "empty queue" << endl;
            else
                cout << "queue is not empty" << endl;
            break;
        case 6:
            if (c.isFull())
                cout << "queue is full" << endl;
            else
                cout << "queue is not full" << endl;
            break;
        case 0:
            cout << "exiting" << endl;
            break;
        default:
            cout << "invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}
