#include <iostream>
#include <queue>
using namespace std;

class Stack2Q
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "stack empty" << endl;
            return;
        }
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

class Stack1Q
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        for (int i = 1; i < sz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "stack empty" << endl;
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    Stack2Q s1;
    cout << "stack using two queues:" << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "top: " << s1.top() << endl;
    s1.pop();
    cout << "top after pop: " << s1.top() << endl;

    Stack1Q s2;
    cout << endl
         << "stack using one queue:" << endl;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "top: " << s2.top() << endl;
    s2.pop();
    cout << "top after pop: " << s2.top() << endl;

    return 0;
}
