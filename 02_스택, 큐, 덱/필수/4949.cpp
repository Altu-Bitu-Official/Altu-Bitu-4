#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkSentence(string s)
{
    stack<char> brackets;

    for(int i= 0; i< s.size() ; i++)
    {
        switch (s[i])
        {
            case '(':
                brackets.push(s[i]);
                break;
            case '[':
                brackets.push(s[i]);
                break;
            case ')':
                if(brackets.size() == 0 || brackets.top() != 40)
                {
                    return false;
                }
                brackets.pop();
                break;
            case ']':
                if(brackets.size() == 0 || brackets.top() != 91)
                {
                    return false;
                }
                brackets.pop();
                break;
            default:
                break;
        }
    }
    if(brackets.size() != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    string sentence;
    while(true)
    {
        getline(cin, sentence);
        if(sentence == ".")
        {
            break;
        }
        cout << (checkSentence(sentence) ? "yes" : "no") << "\n";
    }
}