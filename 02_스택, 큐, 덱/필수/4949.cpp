#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if(s[i] == ']'){
            if(!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if(!st.empty())
        return false;
    return true;
}

int main(){

    string s;
    cin.ignore();
    getline(cin, s);

    while(s != "."){
        if(check(s))
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
        getline(cin, s);
    }
}