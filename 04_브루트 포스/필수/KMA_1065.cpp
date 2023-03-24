#include <iostream>
#include <string>
using namespace std;

//한수인지 검사 (한수이면 true, 아니면 false)
bool is_number(int num){
    //두자리수 이하 자연수는 항상 한수(1~99)
    if (num<100) {return true;} 
    
    //세자리수 이상 자연수는 검사
    string s = to_string(num); 
    int d = (s[1]-'0') - (s[0]-'0');    //공차 d
    for (int i=2; i<s.size(); i++){     //등차수열이 아니면 false 반환
        int temp = (s[i]-'0') - (s[i-1]-'0');
        if (temp != d){
           return false;}
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int input;  //input이하인 한수의 개수를 구해야 한다
    int cnt = 0;    //input이하인 한수의 개수

    cin >> input;
    //1부터 input까지의 자연수 하나하나 한수인지 검사하고, 한수이면 cnt++
    for (int i=1; i<=input; i++){   
        cnt = (is_number(i)) ? cnt+1 : cnt;
    }
    cout << (cnt);
    
    return 0;
}