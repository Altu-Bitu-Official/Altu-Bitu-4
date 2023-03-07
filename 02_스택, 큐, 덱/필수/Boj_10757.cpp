#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 100000;

int main() {
    ios::sync_with_stdio(false);   //연산 속도 증가를 위한 코드 
    cin.tie(NULL); cout.tie(NULL);

    //두 수 입력받기 
    string a,b;     
    cin >> a >> b ;

    string ans;
    vector<int> a_vec, b_vec; 
    int carry, sum ;              //올림수 carry에 저장, 한자리수 덧셈 sum에 저장 

    //연산
    //자릿수가 다른 경우 
    if (a.size() < b.size()){
        swap(a,b);
    }
    int diff_len = a.size() - b.size();

    //a,b 문자열을 숫자 int형으로 바꿔서 vector에 넣기 
    for (int i =0; i <a.size(); i++)
    {
        a_vec.push_back(a[i]-'0');          //문자 -> 숫자 '0'을 빼주면 됨 
    }
    //b의 자릿수가 더 적으니까 앞에 0 넣어주기 
    for(int i=0; i<diff_len; i++)
    {
        b_vec.push_back(0);
    }
    
    for (int i=0; i < b.size(); i ++) 
    {
        b_vec.push_back(b[i] - '0'); 
    }

    for (int i =a_vec.size()-1; i>=0; i--)
    {
        sum = a_vec[i] + b_vec[i]; 
        if (carry == 1)
       {
        sum++;
        carry=0;
       }
       //올림수 발생 
       if(sum >9) 
       {
        sum %= 10; 
        carry = 1 ;
       }
       ans += (sum+'0');    //숫자를 문자열에 이어 붙인다
    }

    if(carry ==1)
    {
        ans += '1';
    }

    reverse(ans.begin(),ans.end()); // 문자 뒤에서부터 출력 

    //출력
    cout << ans <<'\n';

    return 0;
}
