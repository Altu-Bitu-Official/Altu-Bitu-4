#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBalance(string &str)
{
	// 초기화
    stack<char> s;
    bool balance = true; // 균형잡힌 세상일 때 true, 아닐 시 false

    // 입력받은 문자열을 문자 하나씩 검사
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')') // 입력받은 문자가 ) 이면
        {
            // 스택이 비지 않고 앞에 짝 괄호가 있을 때
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            // 스택이 비었거나 앞에 짝괄호가 없을 때 균형 X라고 판단해서 루프 벗어남 -> 바로 균형잡힌 세상인지 검사
            else
            {
                balance = false;
                return balance;
            }
        }
        else if (str[i] == ']')
        {
            // 스택이 비지 않고 앞에 짝 괄호가 있을 때
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            // 스택이 비었거나 앞에 짝괄호가 없을 때 균형 X라고 판단해서 루프 벗어남 -> 바로 균형잡힌 세상인지 검사
            else
            {
                balance = false;
                return balance;
            }
        }
        // 문자열이 ( 혹은 [ 라면 스택에 넣기
        else if (str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
    }

    if(s.empty()){
        return balance;
    }
    else{
        return false;   //balance = false;
    }
	
}

int main()
{
    string str;
    while (1)
    {
        
        // 입력
        getline(cin, str);
        //'.'만 입력받으면 종료
        if (str == ".")
        {
            return 0;
        }

        bool balance = checkBalance(str);

        // 균형잡힌 세상인지 검사
        if (balance == true)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}