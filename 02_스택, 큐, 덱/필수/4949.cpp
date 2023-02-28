#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (true)
    {
        stack<char> s;
        getline(cin, str, '.');
        // 마지막 온점 식별자, getline의 buffer 특성상 emtpy string을 단일 \n으로 읽음
        if (str.empty() || (str.size() == 1 && str[0] == '\n'))
            break;
        for (char &c : str)
        {
            if (c == '[' || c == '(')
            {
                s.push(c);
            }
            if (c == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else // 그 외의 경우는 모두 탈락이므로 empty stack이 나오지 못하도록 push해준다.
                {
                    s.push(c);
                }
            }
            if (c == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
        }

        if (s.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}