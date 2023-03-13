#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    string line;    //주어진 문자열
    bool is_balanced;   //괄호 균형 여부

    //입력
    getline(cin, line);     //'\n' 기준으로 입력받음
    //"." 입력받을 때까지 계속
    while (line != "."){    
        stack<char> br;

        //is_balanced 판단
        is_balanced = true;
        for (auto i:line){
            if (i=='(' || i=='['){
                br.push(i);
            }
            if (i==')'){
                if (!br.empty() && br.top() == '(') {br.pop();} //!br.empty() && 가 없으면 왜 틀릴까?
                else {
                    is_balanced = false;
                    break;
                }
            }
            if (i==']'){
                if (!br.empty() && br.top() == '[') {br.pop();} //마찬가지
                else {
                    is_balanced = false;
                    break;
                }
            }
        }
        //출력
        string ans = (is_balanced && br.empty())? "yes\n" : "no\n";
        cout << ans;
        //다음줄 입력받음
        getline(cin, line);
    }
    return 0;
}