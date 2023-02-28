/**/
#include <iostream>
#include <stack>
#include <string> //getline()함수 사용하기위해

using namespace std;

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