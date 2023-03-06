#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> stackDigits(string n)
{
    stack<int> num;
    for (char &c : n)
    {
        num.push(c - '0');
    }
    return num;
}

stack<int> sumUp(stack<int> &num1, stack<int> &num2)
{
    stack<int> sum;

    // 각 stack에서 하나씩 꺼내서 덧셈연산 후 결과에 stack함
    int carry = 0;

    while (!num1.empty() || !num2.empty())
    {
        // element가 존재할때만 stack에서 하나씩 꺼내기
        int num1_top = 0;
        int num2_top = 0;
        if (!num1.empty())
        {
            num1_top = num1.top();
            num1.pop();
        }
        if (!num2.empty())
        {
            num2_top = num2.top();
            num2.pop();
        }

        // 덧셈연산
        sum.push((carry + num1_top + num2_top) % 10);

        // 합이 10 넘어갈경우 다음 자릿수 올림
        if (carry + num1_top + num2_top >= 10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    // 남은 carry 처리
    if (carry)
    {
        sum.push(carry);
    }
    return sum;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;

    // 일의자리(뒤쪽 수)부터 계산할 예정이므로 stack 사용
    stack<int> num1, num2, result;

    // string을 앞숫자부터 int화해서 stack함
    num1 = stackDigits(n1);
    num2 = stackDigits(n2);

    result = sumUp(num1, num2);

    // 결과값 출력
    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }
}