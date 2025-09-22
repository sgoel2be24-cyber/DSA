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

int findMiddle()
{
    node slow = head;
    node fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    cout << "list: ";
    display();

    cout << "middle: " << findMiddle() << endl;

    return 0;
}
