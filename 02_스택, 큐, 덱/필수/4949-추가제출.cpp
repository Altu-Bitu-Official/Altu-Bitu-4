 #include <iostream>
#include <stack> //stack을 이용해 여는 괄호가 생기면 push 닫는 괄호를 만나면 pop함

using namespace std;

bool isBalanced(string input) { // 괄호가 균형을 이루었는지 여부 반환
    stack<char> s; // 괄호 저장하는 스택

    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        switch(ch) {
            case '(': case '[': // 여는 괄호는 무조건 push
                s.push(ch);
                break;
            case ')': // 닫는 소괄호
                if(s.empty() || s.top() != '(') { 
                    return false; //닫는 소괄호는 있지만 여는 소괄호는 없는 경우-거짓반환
                }
                s.pop(); //소괄호가 균형 잡혀 있으므로 pop을 통해 stack을 비움
                break;
            case ']': // 닫는 대괄호
                if(s.empty() || s.top() != '[') {
                    return false; //닫는 대괄호는 있지만 여는 대괄호는 없는 경우-거짓반환
                }
                s.pop();//대괄호가 균형 잡혀 있으므로 pop을 통해 stack을 비움
                break;
        }
    }
    return s.empty();/* ture: 문장에 괄호가 하나도 없거나 모든 괄호가 균형을 이룸
    false: 문장의 괄호가 균형을 이루지 않음
    */
}

/*
 * [괄호 균형 확인하기]
 * 1. 여는 괄호는 바로 스택에 넣는다.
 * 2. 닫는 괄호가 나오면 가장 최근에 넣었던 여는 괄호와 비교한다.
 * 2-1. 닫는 괄호와 여는 괄호의 종류가 같다면 해당 닫는 괄호가 균형을 이룬다.
 * 2-2. 직전에 나온 여는 괄호가 없거나 그 종류가 다르다면 해당 닫는 괄호가 균형을 이루지 못한다.
 * 3. 모든 닫는 괄호가 여는 괄호와 짝을 이루었더라도 스택에 여는 괄호가 남아있다면 균형을 이루지 못한다.
*/


int main() {
    string input;

    while(true) {
        // 입력
        getline(cin, input); //'/n'을 만나면 읽기를 종료하기 때문에 문장 단위로 읽어들임
        if(input == ".") { //괄호 없이 .만 있을 경우  프로그램 종료
            break;
        }

        // 연산 & 출력
        if(isBalanced(input)) { 
            cout << "yes\n"; //isBalanced함수에서 1반환시(=스택이 비어 있음=균형잡힘) yes 출력
        }
        else {
            cout << "no\n"; //0반환시(=스택이 비어있지x=균형x) no출력
        }
    }
    return 0;
}