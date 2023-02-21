#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string n1, string n2)
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
        if (isdigit(n1[i]))
            sum1 += n1[i] - 48;
        if (isdigit(n2[i]))
            sum2 += n2[i] - 48;
    }

    if (sum1 != sum2)
        return sum1 < sum2;

    // 3번째 기준
    return n1 < n2;
}

int main()
{
    int N = 0;
    cin >> N;
    vector<string> serial_num(N);
    for (int i = 0; i < N; i++)
    {
        cin >> serial_num[i];
    }

    sort(serial_num.begin(), serial_num.end(), comp);

    for (int i = 0; i < N; i++)
    {
        cout << serial_num[i] << '\n';
    }
}
