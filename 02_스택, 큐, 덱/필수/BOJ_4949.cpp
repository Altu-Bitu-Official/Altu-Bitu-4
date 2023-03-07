#include <iostream>
#include <stack>
#include <string> //getline()함수 사용하기위해

using namespace std;

bool is_balanced(string input)
{
    stack<char> s;

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];

        switch (ch)
        {
        case '(':
        case '[':
            s.push(ch);
            break;
        case ')':
            if (s.empty() || s.top() != '(')
            {
                return false; // 바로 종료조건 때린다.
            }
            else
            {
                s.pop();
                break; // 한 순간의 ex) input [2]에서의 switch문이 끝난다.
            }
        case ']':
            if (s.empty() || s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
                break;
            }
        }
    }

    return s.empty();
}

int main()
{
    string input;

    while (true)
    {
        // 입력
        getline(cin, input); // 줄바꿈 \n이 나올 때 까지 읽기 (한줄 읽기)
        if (input == ".")
        {
            break;
        }

        // 연산 & 출력
        if (is_balanced(input))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}

/*수정 전 코드*/
/*
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string str;
        bool flag = true; // 플래그 이용해서 괄호의 짝이 잘 맞는지 확인하기
        stack<char> ch;   // 문자를 담는 스택

        getline(cin, str); // 공백 문자 포함 된 문자열 입력받기

        if (str == ".") // str 이 . 이면 while문 빠져나가기
        {
            break;
        }

        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];

            if (c == '(' || c == '[')
            {
                ch.push(c);
            }
            else if (c == ')')
            {
                if (!ch.empty() && ch.top() == '(') // 스택이 비어있지 않고 스택에서 가장 위에 있는 문자가 '('일 경우
                {
                    ch.pop(); // 스택에서 가장 위에있는 정수를 뺀다
                }
                else
                {
                    flag = false; // 플래그를 false로 변화시키고
                    break;        // for 문을 빠져나온다.
                }
            }

            else if (c == ']')
            {
                if (!ch.empty() && ch.top() == '[')
                {
                    ch.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && ch.empty()) // flag가 true이고 스택이 비어있으면
        {
            cout << "yes\n";
        }
        else // flag가 flase이거나 스택이 비어있지 않으면
        {
            cout << "no\n";
        }
    }

    return 0;
}
*/