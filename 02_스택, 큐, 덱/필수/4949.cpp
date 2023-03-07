#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        stack<char> stack_for_parentthesis;
        string text;
        getline(cin, text);
        if (text == ".")
            break;
        for (int i = 0; i < text.length(); i++)
        {

            if (text[i] == '[')
            {
                stack_for_parentthesis.push(text[i]);
            }
            if (text[i] == '(')
            {
                stack_for_parentthesis.push(text[i]);
            }
            if (text[i] == ']')
            {
                if (!stack_for_parentthesis.empty() && stack_for_parentthesis.top() == '[')
                {
                    stack_for_parentthesis.pop();
                }
                else
                {
                    stack_for_parentthesis.push(text[i]);
                    break;
                }
            }
            if (text[i] == ')')
            {
                if (!stack_for_parentthesis.empty() && stack_for_parentthesis.top() == '(')
                {
                    stack_for_parentthesis.pop();
                }
                else
                {
                    stack_for_parentthesis.push(text[i]);
                    break;
                }
            }
        }

        if (stack_for_parentthesis.empty())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
