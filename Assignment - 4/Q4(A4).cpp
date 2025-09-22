#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeat(string s)
{
    queue<char> q;
    int freq[100] = {0};

    for (char c : s)
    {
        if (c == ' ')
            continue;

        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "enter string: ";
    getline(cin, str);

    cout << "output: ";
    firstNonRepeat(str);

    return 0;
}
