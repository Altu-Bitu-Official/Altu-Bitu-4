#include <iostream>
#include <stack> //스택 헤더파일 선언
using namespace std;

bool isBalanced(string input){ //괄호가 균형을 이루었는지 여부를 반환
    stack<char> s; //괄호를 저장하는 스택 선언

    for(int i=0; i<input.length(); i++) { //문자열의 길이만큼 반복
        char ch = input[i]; // 입력값의 첫 번째 원소부터 ch에 넣어주기

        //만약에 ch가 알파벳이라면 switch문에 해당되는게 없는데 그럼..아무 작업도 하지 않고 그냥 다시 for문으로 돌아가는 건가요?
        switch(ch) { //switch-case문 시작
            case '(' : case '[' : //여는 괄호 두 개는
                s.push(ch); //무조건 스택에 push
                break; // break문으로 빠져나온다

            case ')' : //닫는 소괄호가 들어왔을 때
                if(s.empty() || s.top() != '('){ //스택이 비었거나 스택의 맨 위에 있는 게 '('가 아니라면
                    return false; //false를 반환
                } //근데 왜 true인 경우는 리턴해주지 않고 false인 경우에 대해서만 코드를 쓴건가요??
                s.pop(); //왜..왜 맨 위에 있는 걸 pop해주죠ㅜㅜ?
                break;
            case ']' : //닫는 대괄호가 들어왔을 때
                if(s.empty() || s.top()!='['){ //스택이 비었거나 스택의 맨 위에 있는 게 '['가 아니라면
                    return false;
                }
                s.pop(); //스택의 맨 위에 있는 원소를 pop하고
                break; //빠져나온다

        }
    }
    return s.empty(); //for문이 끝나고 마지막에 왜 s.empty()를 리턴해야 하나요..?? 이게 무슨 역할인지 알고싶어요

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string input; //입력값을 문자열 타입으로 받음

    while(true){ //궁금한게 여기서 while(true)문을 왜 도는건가요..???
        getline(cin, input); //공백을 포함해서 한 줄을 통째로 입력받음
        if(input == ".") { //input이 온점이면
            break; //빠져나와서 그 다음줄 입력받기..?? 이 부분이 무슨 뜻인지 알고싶어요!
        }

        if(isBalanced(input)) {
            cout << "yes\n"; //isBalanced 함수의 결과가 참이면 yes
        }
        else{
            cout << "no\n"; //isBalanced 함수의 결과가 거짓이면 no
        }
    }
    return 0;
}
