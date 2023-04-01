#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, x, input;
    cin >> n;
    priority_queue<int> max_heap;

    while (n--)
    {
        cin >> x;
        if (x == 0)
        {
            if (max_heap.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        }
        else
        {
            while (x--)
            {
                cin >> input; // 3 2가 들어온다.
                max_heap.push(input);
            }
        }
    }
    return 0;
}