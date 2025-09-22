#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q)
{
    int n = q.size();
    if (n == 0)
        return;

    if (n % 2 != 0)
    {
        cout << "queue should have even number of elements";
        return;
    }

    int half = n / 2;
    queue<int> first;

    for (int i = 0; i < half; i++)
    {
        first.push(q.front());
        q.pop();
    }

    while (!first.empty())
    {
        q.push(first.front());
        first.pop();

        q.push(q.front());
        q.pop();
    }
}

void show(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    queue<int> q;
    int n;
    cout << "enter even number of elements : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "original queue: ";
    show(q);

    interleave(q);

    cout << "interleaved queue: ";
    show(q);

    return 0;
}
