#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);   


    while (true){ // 한줄 한줄 판단해야 하므로, .이 나오면 다음 문장으로 넘어가야 하므로 while 사용해줌
		string line;
        getline(cin, line); 
        stack<char> st;
        bool flag = true;

		if (line[0] == '.') {
            break;
        } // 줄 나눔 역할

		for(int i=0; i<line.size(); i++){
			
			if(line[i] == '[' || line[i] == '('){
				st.push(line[i]);
			}
			
			else if(line[i] == ']'){
				if(st.empty()){
					flag = false;
					break;
				}
				
				else if(st.top() == '['){
					st.pop();
				}
				
				else if(st.top() == '('){
					flag = false;
					break;
				}
			}
			
			else if(line[i] == ')'){
				if(st.empty()){
					flag = false;
					break;
				}
				
				else if(st.top() == '('){
					st.pop();
				}
				
				else if(st.top() == '['){
					flag = false;
					break;
				}
			}
			
		}
		
		if(st.empty() && flag)
			cout << "yes\n" ;
			
		else
			cout << "no\n" ;
	
	}
    return 0;
}