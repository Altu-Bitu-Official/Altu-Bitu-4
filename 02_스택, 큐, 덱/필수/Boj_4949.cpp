#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

     ios::sync_with_stdio(false);   //연산 속도 증가를 위한 코드 
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        string input;
        getline(cin,input); // 한 줄씩 저장
        stack<char>s; //괄호를 저장 할 스택 
        bool ans = true; //yes or no 
        
        if(input.length()==1 && input[0] == '.')  // '.' 만 있는 문장을 만나면 종료 
        {
            break;
        }

        for (int i =0; i<input.length(); i++)  
        {
            if(input[i] =='(' || input[i] =='[') 
            {
                s.push(input[i]);
            }
            if(input[i] ==')'){    // 닫힘 소괄호를 만났을 때 
                if(s.empty() || s.top() =='[') 
                {
                    ans = false;
                }
                else{
                    s.pop();
                }
            }
            if(input[i] == ']'){
                if(s.empty() || s.top() =='(')
                {
                    ans =false;
                }
                else {
                    s.pop();
                }
            }
        }

        if(s.empty() && ans) cout <<"yes" << '\n';  // 모든 과정 종료 후 stack이 비어있고 ans가 true면 문자열이 균형 

        else cout << "no" << '\n';  //아니면 no 

    }

    return 0;
}