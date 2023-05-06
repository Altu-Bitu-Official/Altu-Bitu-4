#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str;
    stack<int> s;

    while(true){
        while(!s.empty()) {s.pop();}
        getline(cin, str);

        if(str[0]=='.'){
            break;
        }

        for (int i=0; i<100; i++){
            if((str[i]=='(')||(str[i]=='[')){
                s.push(str[i]);
            }
            else if (str[i]==')'){
                if(s.empty()){
                    cout << "no" << '\n';
                    break;
                }
                else if(s.top()=='('){
                    s.pop();
                }
                else {
                    cout << "no" << '\n';
                    break;
                }
            }
            else if (str[i]==']'){
                if(s.empty()){
                    cout << "no" << '\n';
                    break;
                }
                else if(s.top()=='['){
                    s.pop();
                }
                else {
                    cout << "no" << '\n';
                    break;
                }
            }
            if(str[i]=='.'){
                if(s.empty()){
                    cout << "yes" << '\n';
                    break;
                }
                else{
                    cout << "no" << '\n';
                    break;
                }
            }

        }
    }

    return 0;
}
