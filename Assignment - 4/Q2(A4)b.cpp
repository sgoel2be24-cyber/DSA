#include <iostream>
#define SIZE 8
using namespace std;

class CircularQueue
{
private:
    int queue[SIZE];
    int front, rear;
    int count;

public:
    CircularQueue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty()
    {
        return (count == 0);
    }

    bool isFull()
    {
        return (count == SIZE);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "queue overflow" << data << endl;
            return;
        }
        queue[rear] = data;
        rear = (rear + 1) % SIZE;
        count++;
        cout << data << " inserted " << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "queue underflow" << endl;
            return;
        }
        cout << queue[front] << " deleted from queue." << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
        }
        else
        {
            cout << "Front element: " << queue[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
            return;
        }
        cout << "queue conten : ";
        int i = front;
        for (int j = 0; j < count; j++)
        {
            cout << queue[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

void showMenu()

        cout
    << "1. enqueue " << endl;
cout << "2. dequeue" << endl;
cout << "3. peek " << endl;
cout << "4. display " << endl;
cout << "5. check " << endl;
cout << "6. check " << endl;
cout << "0. exit" << endl;
cout << "Choose an option: ";
}

int main()
{
    CircularQueue cq;
    int option, element;

    do
    {
        showMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "enter element to insert: ";
            cin >> element;
            cq.enqueue(element);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
            break;
        case 5:
            if (cq.isEmpty())
                cout << "queue is empty" << endl;
            else
                cout << "queue has elements" << endl;
            break;
        case 6:
            if (cq.isFull())
                cout << "queue is full" << endl;
            else
                cout << "queue is not full" << endl;
            break;
        case 0:
            cout << "exiting" << endl;
            break;
        default:
            cout << "invalid option" << endl;
        }

    } while (option != 0);

    return 0;
}