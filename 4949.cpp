//4949 균형잡힌 세상
//괄호 '짝짓기' 문제 := 자료구조 '스택(stack)' 이용 
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(true){
        string input; getline(cin, input); //한줄단위로 입력받기
        if(input==".") break; //종료조건:= 온점 하나만 입력받으면 반복문 종료
        stack<char> stk; //문자를 담는 스택(stack). 여는 괄호는 스택에 넣고, 닫는 괄호 만나면 스택의 top값과 비교하는 전략.
        bool chk=true; 
        //균형이 잡혀있는지 확인하는 체킹변수

        for(char c: input){
            if(c=='('||c=='['){
                stk.push(c); //여는 괄호 만나면 스택에 밀어넣기
            } 

            if(c==')') { //닫는 괄호를 만난 순간
                if(!stk.empty()&&stk.top()=='(') stk.pop(); //스택이 비었는지 확인하고, 스택의 top값과 짝지어지면 스택에서 뽑아내주고
                else { //아니면
                    chk=false; break; //해당 문자열은 이미 가망이 없으므로(no) 체킹변수 false 체크후 없애준다.
                }
            }

            if(c==']') {
                if(!stk.empty()&&stk.top()=='[') stk.pop();
                else {
                    chk=false; break;
                } 
            }
        }

        if(chk&&stk.empty()) { //다 비교했을 때, 스택이 비어있으면
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
       }
    return 0;
}