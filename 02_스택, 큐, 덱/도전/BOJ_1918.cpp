#include <iostream>
#include <stack>

using namespace std;

int priority(char c) {
    switch(c) {
        case '(' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    } 
}

string postFix(string& str) {
    string answer = "";
    stack<char> oper;
    int l = str.length();

    for (int i = 0; i < l; i++) {
        char c = str[i];
        switch (c)
        {
        case '(' : 
            oper.push(c);
            break;
        
        case ')' :
            while (!oper.empty() && oper.top() != '(') {
                answer += oper.top();
                oper.pop();
            }
            oper.pop();
            break;
        case '+' : case '-' : case '*' : case '/' :
            while(!oper.empty() && priority(oper.top()) >= priority(c)) {
                answer += oper.top();
                oper.pop();
            }
            oper.push(c);
            break;
        default:
            answer += c;
        }
    }

    while (!oper.empty()) {
        answer += oper.top();
        oper.pop();
    }
    return answer;
}

int main() {
    string str;
    cin >> str;
    cout << postFix(str);

}