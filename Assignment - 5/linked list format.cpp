#include <iostream>
using namespace std;

struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll node;
node *head = NULL;
node *tail;
void print();

int main()
{
    int n;
    cin >> n;
    int i = 0;
    while (i != n)
    {
        if (head == NULL)
        {
            head = new node;
            cin >> head->data;
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = new node;
            cin >> tail->next->data;
            tail->next->next = NULL;
            tail = tail->next;
        }
        i++;
    }
    print();
    return 0;
}

void print()
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
