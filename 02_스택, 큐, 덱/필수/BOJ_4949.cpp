#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        string str;
        getline(cin, str); // 입력한 문자열을 한줄씩 인식
        stack<char> s;     // stack을 이용
        int check = 0;     // 만약 ()이나 []이 쌍으로 존재하지 않을 시에 1로 초기화

        if (str == ".")
        { // . 을 입력하면 종료
            break;
        }

        for (int i = 0; i < str.length(); i++)
        {

            // (,[ 인 경우에는 stack에 쌓기
            if ((str[i] == '(') || (str[i] == '['))
            {
                s.push(str[i]);
            }

            if (str[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                {            // 괄호의 짝이 맞으면
                    s.pop(); // ( 를 배출
                }
                else
                {
                    check = 1;
                    break;
                }
            }

            if (str[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                { // 괄호의 짝의 맞으면
                    s.pop();
                }
                else
                {
                    check = 1;
                    break;
                }
            }
        }

        // 모든쌍이 제거되어 s가 empty인 경우
        if (s.empty() && check == 0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }

        return 0;
    }
}