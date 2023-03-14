#include <iostream>
#include <string>

using namespace std;

bool isValid(int i)
{
    // 세자리 수 미만은 모두 한수
    if (i < 100)
    {
        return true;
    }

    // 각 자리수의 차 비교
    string idx = to_string(i);
    int diff = idx[0] - idx[1];
    for (int j = 1; j < idx.size(); j++)
    {
        if (idx[j - 1] - idx[j] != diff)
        {
            return false;
        }
    }

    return true;
}

int getAnswer(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isValid(i))
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << getAnswer(n);
}