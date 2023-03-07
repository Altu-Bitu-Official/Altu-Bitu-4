
#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;

int main()
{
    // 런타임 에러가 나지 않게 하기 위함
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int, long 타입으로 받아올 수 없는 수의 범위이므로 문자열 형태로 받아옴
    string A, B;
    int carry = 0; // 올림수
    int length;    // A와 B중 긴 것의 길이
    cin >> A >> B;

    // A,B를 저장하는 스택, 결과값을 저장하는 스택
    stack<int> stack_A;
    stack<int> stack_B;
    stack<int> stack_result;

    // A와 B중 긴 것의 길이에 맞춤
    // 더 짧은 것의 앞에 0을 넣어줌
    if (A.length() > B.length())
    {
        length = A.length();
        for (int i = 0; i < A.length() - B.length(); i++)
        {
            stack_B.push(0);
        }
    }
    else if (A.length() < B.length())
    {
        length = B.length();
        for (int i = 0; i < B.length() - A.length(); i++)
        {
            stack_A.push(0);
        }
    }
    // 길이가 같은 경우 0을 앞에 넣어주지 않음
    else
    {
        length = A.length();
    }
    // A와 B를 스택에 저장함
    // ***문자열 -> int 변환을 위해 '0'을 빼주어야함***

    for (int i = 0; i < A.length(); i++)
    {
        stack_A.push(A[i] - '0');
    }
    for (int i = 0; i < B.length(); i++)
    {
        stack_B.push(B[i] - '0');
    }

    // A와 B의 스택이 빌 때까지 각 자리수를 더하고 올림수를 계산함
    for (int i = 0; i < length; i++)
    {
        if (!stack_A.empty() && !stack_B.empty()) // 스택에 값이 존재할 때만 top()을 쓸 수 있음
        {
            // 올림수 + A에서 나온 한자리수 + B에서 나온 한자리수
            int result = stack_A.top() + stack_B.top() + carry;
            carry = result / 10;
            int push_result = result % 10;

            // 결과 스택에 값을 저장하고, A와 B의 스택에서는 값을 제거
            stack_result.push(push_result);
            stack_A.pop();
            stack_B.pop();
        }
    }
    // 마지막 올림수는 for문 밖에서 따로 넣어줌(존재한다면)
    if (carry != 0)
    {
        stack_result.push(carry);
    }

    // 마지막 올림수까지 고려한 결과 스택의 길이: length+1
    for (int i = 0; i < length + 1; i++)
    {
        if (!stack_result.empty()) // 스택에 값이 존재한다면 (스택에 값이 존재할 때만 top()을 쓸 수 있음)
        {
            cout << stack_result.top();
            stack_result.pop();
        }
    }

    return 0;
}
