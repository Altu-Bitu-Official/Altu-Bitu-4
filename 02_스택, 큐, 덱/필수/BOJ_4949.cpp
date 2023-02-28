#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> checkString(string str, int* flag, stack<char> s)
{
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if ((c == '(') || (c == '[')) {
            s.push(c);
        }
        else if (c == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            else {
                (*flag) = 1;
                break;
            }
        }
        else if (c == ']') {
            if (!s.empty() && s.top() == '[') {
                s.pop();
            }
            else {
                (*flag) = 1;
                break;
            }
        }
    }
    return s;
}

int main()
{
    while (1)
    {
        string str;
        getline(cin, str);
        if (str == ".")
            break;
        stack<char> s;
        int flag = 0;
        s = checkString(str, &flag, s);
        if (s.empty() && flag == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}