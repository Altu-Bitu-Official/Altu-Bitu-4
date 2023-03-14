#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool CheckNum(int n)
{
    if (n / 100 == 0)
    {
        return true;
    }
    else
    {
        int hundred = n / 100;
        int ten = (n % 100) / 10;
        int one = n % 10;
        if (hundred - ten == ten - one)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (CheckNum(i))
        {
            count++;
        }
    }

    cout << count;
    return 0;
}