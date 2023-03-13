#include <iostream>
#include <string>
using namespace std;
int hansu(int n)
{
    int cnt = 0, answer = 0;
    if (n < 100)
    {
        return n;
    }

    for (int i = 100; i <= n; i++)
    {
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        if (b - a == c - b)
        {
            cnt++;
        }
    }
    return 99 + cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << hansu(n);

    return 0;
}