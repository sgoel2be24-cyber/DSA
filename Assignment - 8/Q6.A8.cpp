#include <iostream>
using namespace std;

class PriorityQueue
{
    int heap[100];
    int size;

public:
    PriorityQueue()
    {
        size = 0;
    }

    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent])
        {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;

            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;

            heapifyDown(largest);
        }
    }

    void insert(int value)
    {
        if (size >= 100)
        {
            cout << "Queue is full" << endl;
            return;
        }

        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << "Element " << value << " inserted" << endl;
    }

    void deleteMax()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Deleted element: " << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void getMax()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Maximum element: " << heap[0] << endl;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    PriorityQueue pq;
    int choice, value;

    while (true)
    {
        cout << "\n1. Insert Element" << endl;
        cout << "2. Delete Maximum Element" << endl;
        cout << "3. Get Maximum Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Get Size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.insert(value);
            break;

        case 2:
            pq.deleteMax();
            break;

        case 3:
            pq.getMax();
            break;

        case 4:
            pq.display();
            break;

        case 5:
            cout << "Size: " << pq.getSize() << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}