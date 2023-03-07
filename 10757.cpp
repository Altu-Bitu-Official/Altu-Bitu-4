//10757 큰 수 A+B 문제
// 범위가 많이 크기 때문에, 문자열로 입력값을 받아야 합니다.
// 덧셈을 처리하려면 10^0, 10^1, ..., 10^(s.size()-1)의 자리 순으로 처리해야함.
//:= 숫자값이 반대로 저장되어야하므로--> LIFO구조인 '스택(stack)'을 이용합니다.
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
vector<int> adder(stack<int> &a_stk, stack<int> &b_stk){
    //매개 변수로 두 스택을 받아, 결괏값을 vector의 형태로 반환해주는 함수.
    int a_opd=0, b_opd=0; 
    int carry=0; //전의 자릿수
    vector<int> res;

    while(1){

        int a_opd, b_opd;
        if(!a_stk.empty()&&!b_stk.empty()) 
        { //스택 두 개 다 비지 않았다면
            a_opd=a_stk.top(); 
            a_stk.pop();
            b_opd=b_stk.top();
            b_stk.pop();
        } 
        else if(!a_stk.empty()&&b_stk.empty()) 
        {
            a_opd=a_stk.top();
            a_stk.pop();
            b_opd=0;
        } 
        else if(a_stk.empty()&&!b_stk.empty()) 
        {
            a_opd=0;
            b_opd=b_stk.top();
            b_stk.pop();
        } 
        else 
        {
            a_opd=0; b_opd=0;
        }
        
        int sum=carry+a_opd+b_opd;
        //9와 3를 더했을 시에,
        carry=(sum/10); //올림수: 1
        int remain=(sum%10); //남는 수:2
        res.push_back(remain);
        if(a_stk.size()==0&&b_stk.size()==0&&carry==0){
            //a스택이고 b스택이고 죄다 뽑아냈고 올림수도 더 이상 남지 않았더라면?
            break; //반복문 종료
        }

    }
    return res;
}

void print(vector<int> &vec){
    reverse(vec.begin(), vec.end());
    for(auto x: vec){
        cout << x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b;
    cin >> a >> b; //12312 //22232
    stack<int> a_stk;
    stack<int> b_stk;
    for(char c:a){
        a_stk.push(c-'0'); 
        //스택의 맨 위-->아래 순으로: 21321(reverse처리 한 효과가 남) 
    }
    for(char c:b){
        b_stk.push(c-'0'); //23222
    }
    vector<int> ans= adder(a_stk, b_stk);
    print(ans);
    return 0;
}