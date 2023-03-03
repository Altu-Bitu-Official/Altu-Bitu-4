#include <iostream>
#include <vector>

using namespace std;

int charToint(char a)
{
    return (a - '0');
}

vector<int> calcPlus(string &a, string &b)
{
    vector<int> ans;
    int idx_a = a.size() - 1; // 일의자리 인덱스
    int idx_b = b.size() - 1;
    bool carry = 0;

    while (idx_a >= 0 && idx_b >= 0)
    {
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]);
        num += carry;
        carry = num / 10;
        ans.push_back(num % 10);
    }

    while (idx_a >= 0)
    {
        int num = charToint(a[idx_a--]);
        num += carry;
        carry = num / 10;
        ans.push_back(num % 10);
    }

    if (carry)
    {
        ans.push_back(1);
    }

    return ans;
}

int main()
{
    string a, b;
    vector<int> ans;

    cin >> a >> b;

    if (a.length() < b.length())
    {
        swap(a, b);
    }
    ans = calcPlus(a, b);
    while (ans.empty())
    {
        cout << ans.back();
        ans.pop_back();
    }
    return 0;
}

/*수정 전 코드 */
/*#include <algorithm>
#include <string> */

/*int main()
{
    string a, b;
    int a_arr[10001]; // a b 범위가 0 < a,b < 100000 이므로
    int b_arr[10001];
    int sum;
    vector<int> res;

    cin >> a >> b;

    int a_size = a.size();
    int b_size = b.size();

    if (b.size() > a.size())
    {
        swap(a, b);
        swap(a_size, b_size);
    }

    for (int i = 0; i < a_size; i++)
    {
        a_arr[i + 1] = a[i] - '0'; // 문자열 a를 정수 배열 a_arr로 바꾸기
    }
    for (int i = 0; i < b_size; i++)
    {
        b_arr[i + 1 + (a_size - b_size)] = b[i] - '0'; // 문자열 b를 정수 배열 b_arr로 바꾸기
    }

    for (int i = a_size; i > 0; i--)
    {
        sum = a_arr[i] + b_arr[i];
        if (sum >= 10)
        {
            a_arr[i - 1]++;
            sum -= 10;
        }
        res.push_back(sum);
    }

    if (a_arr[0])
    {
        cout << 1;
    }
    else
    {
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i];
        }
    }

    return 0;
}*/