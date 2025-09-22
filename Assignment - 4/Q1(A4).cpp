#include <iostream>
#define MAX 75
using namespace std;

class Queue
{

    int front, rear;
    int arr[MAX];

public:
    Queue()
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
        return (rear == MAX - 1);
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
        rear++;
        arr[rear] = x;
        cout << x << "is added in the queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        cout << arr[front] << " removed from the queue.";
        front++;
        if (front > rear)
        {

            front = rear = -1;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
        }
        else
        {
            cout << "front element is of the queue is : " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
            return;
        }
        cout << "queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {

        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. peek" << endl;
        cout << "4. display" << endl;
        cout << "5.  if empty" << endl;
        cout << "6. if full" << endl;
        cout << "0. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "value to add in the queue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "queue is empty." << endl;
            else
                cout << "queue is not empty." << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "queue is full." << endl;
            else
                cout << "queue is not full." << endl;
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
