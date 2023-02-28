#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) { //문자마다 반복
        int ans = 0;
        stack<char> s = {};
        string sentence;
        getline(cin, sentence); //공백포함 문자 입력
        if (sentence[0] == '.') {
            break;//입력이 . 뿐이면 입력 끝
        }//처음 입력이 
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == '(') s.push('(');
            if (sentence[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    ans = 1;
                    break;
                }
            }
            if (sentence[i] == '[') s.push('[');
            if (sentence[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    ans = 1;
                    break;
                }
            }
        }
        if (ans == 0 && s.empty()) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
}