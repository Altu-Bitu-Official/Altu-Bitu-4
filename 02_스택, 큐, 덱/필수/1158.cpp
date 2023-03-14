#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, kth_person;
    cin >> num >> kth_person;
    cout << "<";

    queue<int> q;
    for (int i = 1; i <= num; i++)
    {
        q.push(i);
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < kth_person - 1; j++)
        {
            int not_remove_person = q.front();
            q.pop();
            q.push(not_remove_person);
        }
        cout << q.front();
        if (i < num - 1)
        {
            cout << ", ";
        }

        q.pop();
    }
    cout << ">";
}