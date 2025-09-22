#include <iostream>
using namespace std;

struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll *node;

node head = NULL;
node tail = NULL;

void insertEnd(int val)
{
    node temp = new ll;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void display()
{
    node temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int deleteOccurrences(int key)
{
    int count = 0;
    while (head != NULL && head->data == key)
    {
        node temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    node curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data == key)
        {
            node delNode = curr->next;
            curr->next = delNode->next;
            if (delNode == tail)
                tail = curr;
            delete delNode;
            count++;
        }
        else
        {
            curr = curr->next;
        }
    }
    return count;
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(2);
    insertEnd(1);
    insertEnd(3);
    insertEnd(1);

    cout << "original list: ";
    display();

    int key = 1;
    int count = deleteOccurrences(key);

    cout << "count: " << count << endl;
    cout << "updated list: ";
    display();

    return 0;
}
