#include <iostream>
#include <string>
#include <stack>

using namespace std;



int main(){
    


    while(true){//한줄씩 판단
        string buffer;
        getline(cin,buffer);
        stack<char> stk;
        if(buffer==".") break;
        
        
        

        int len=buffer.length();
        bool isB=1;
        for(int i=0;i<len;i++){
        char c=buffer[i];
        if(c=='(') stk.push(c);

        else if(c=='[') stk.push(c);
        else if(c==')'){
            if(!stk.empty()&&stk.top()=='(') stk.pop();
            else {
                isB=0; break;
            }
        }
        else if(c==']'){
            if(!stk.empty()&&stk.top()=='[') stk.pop();
            else {
                isB=0; break;
            }
        }
    }
        if(stk.empty()&&isB==1) cout << "yes\n";
        else cout << "no\n";
    }
}