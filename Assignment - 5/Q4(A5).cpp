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

void findMiddle()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    node slow = head, fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "middle: " << slow->data << endl;
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    cout << "list: 1->2->3->4->5" << endl;
    findMiddle();

    return 0;
}
