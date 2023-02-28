// 시리얼 넘버 문제
// 2176300 이지현
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int sumNum(string a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if ('0' <= a[i] && a[i] <= '9')
            sum += a[i] - '0';
    }
    return sum;
}

bool compare(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else if (a.length() == b.length())
    {
        if (sumNum(a) != sumNum(b))
        {
            return sumNum(a) < sumNum(b);
        }
        else if (sumNum(a) == sumNum(b))
        {
            return a < b;
        }
    }
}

int main()
{
    int n;
    string arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}