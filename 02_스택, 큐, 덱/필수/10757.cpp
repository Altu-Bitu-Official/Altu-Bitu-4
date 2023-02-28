#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void leftOperate(stack<int>& longer, stack<int>& result, bool up, int n)
{
    for(int i =0 ; i< n; i++)
    {
        if(i==0 && up)
        {
            result.push(longer.top()+ up);
        }
        else
        {
            result.push(longer.top());
        }
        longer.pop();
    }
}

int main()
{
    string a, b, l, s;
    int sum_size, temp =0;
    bool up =0;
    stack<int> longer, shorter, result;

    cin >> a >> b;

    // a와 b 중 긴 숫자는 l에 짧은 숫자는 s에 복사
    s = (a.size()<b.size()) ? a : b;
    l = (a.size()<b.size()) ? b : a;

    // stack에 숫자 저장
    for(int i=0; i<l.size() ; i++)
    {
        longer.push(l[i] - '0');
    }
    for(int i=0; i<s.size() ; i++)
    {
        shorter.push(s[i] - '0');
    }

    sum_size = longer.size() - shorter.size();

    // 1의 자리부터 짧은 숫자의 자릿수까지 차례로 덧셈
    for(int i=0; i<s.size() ; i++)
    {
        // 각 숫자의 자리 합
        temp = longer.top() + shorter.top();
        // 올림까지 더해서 9를 초과한다면
        if(temp + up > 9)
        {
            // 더한 값에 -1 해준뒤 result에 push, 올림값을 true로 설정.
            temp -= 10;
            result.push(temp + up);
            up = true;
        }
        else
        {
            // 아니라면 그대로 result에 push, 올림값은 false.
            result.push(temp + up);
            up = false;
        }
        // 덧셈이 끝난 자리를 제거
        longer.pop();
        shorter.pop();
    }

    // 자릿수가 똑같은데 마지막 연산에서 올림이 있을 때
    if(sum_size==0 && up)
    {
        result.push(up);
    }
    // 긴 숫자 쪽에 남은 자리가 있다면 처리
    else
    {
        leftOperate(longer, result, up, longer.size());
    }

    // 출력
    temp = result.size();
    for(int i=0; i<temp; i++)
    {
        cout << result.top();
        result.pop();
    }
}