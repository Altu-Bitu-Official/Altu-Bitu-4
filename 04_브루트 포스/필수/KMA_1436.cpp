#include <iostream>
#include <string>
using namespace std;

//종말의 수인지 검사 (종말의 수이면 true, 아니면 false)
bool is_number(int num){
    string s = to_string(num);

    for (int i=0; i<s.size()-2; i++){ 
        //연속된 세개의 수가 6이면 true 반환
        if ((s[i]=='6') && (s[i+1]=='6')  && (s[i+2]=='6')){
            return true;
        }
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int input;
    int answ = 666; //가장 작은 종말의 수 666
    int cnt = 0;    //종말의 수 개수

    cin >> input;
    while(cnt != input){
        //666부터 오름차순으로 종말의 수인지 검사해서 개수를 셈
        cnt = (is_number(answ++)) ? cnt+1 : cnt;
    }
    cout << (answ-1);
    
    return 0;
}