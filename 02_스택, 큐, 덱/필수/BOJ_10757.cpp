#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string a, b, max, min;
    cin >> a >> b;

    // 문자열의 순서를 역순으로
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    max = (a.size() >= b.size() ? a : b);
    min = (a.size() < b.size() ? a : b);

    stack<int> stack;
    int carry = 0;

    for (int i = 0; i < max.length(); i++)
    {
        int sum;
        // 문자열은 아스키코드를 담기에 '0'을 두 번 빼줘야함
        if (i < min.length())
        {
            sum = max[i] + min[i] - '0' - '0';
        }
        else
        { // max의 문자열만 담기에 '0'을 한 번 빼줘야함
            sum = max[i] - '0';
        }

        if (carry == 1)
        { // 올림수가 존재하면
            sum++;
            carry = 0;
        }

        if (sum >= 10)
        { // 합이 10이 넘어갈 떄 올림처리
            sum %= 10;
            carry = 1;
        }

        stack.push(sum);
    }

    // 최종 수의 합이 10이 넘어갈 때 최종으로 1을 push
    if (carry == 1)
    {
        stack.push(1);
    }

    // empty할때까지 top을 pop
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}
