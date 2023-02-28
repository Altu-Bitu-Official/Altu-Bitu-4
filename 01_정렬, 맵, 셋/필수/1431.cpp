#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sumUp(int &sum, const char &n)
{
    if (isdigit(n))
    {
        sum += n - '0';
    }
}

bool comp(const string &n1, const string &n2)
{
    // 1번째 기준
    if (n1.length() != n2.length())
    {
        return n1.length() < n2.length();
    }

    // 2번째 기준
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n1.length(); i++)
    {
        sumUp(sum1, n1[i]);
        sumUp(sum2, n2[i]);
    }

    if (sum1 != sum2)
        return sum1 < sum2;

    // 3번째 기준
    return n1 < n2;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<string> serial_num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> serial_num[i];
    }

    sort(serial_num.begin(), serial_num.end(), comp);

    for (int i = 0; i < n; i++)
    {
        cout << serial_num[i] << '\n';
    }
}
