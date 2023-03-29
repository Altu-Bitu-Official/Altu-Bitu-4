#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string getPalindrome(string name){
   vector<int> v(26); // 입력받은 문자열의 알파벳 갯수 저장할 벡터
   int odd=0; // 홀수개의 문자 갯수
   char odd_char; //가운데 삽입해야하는 홀수 개 문자 저장할 변수
   string half_ans,ans; //펠린드롬의 앞쪽 절반 저장, 펠린드롬 저장

   for(int i=0;i<name.length();i++){ //입력받은 문자열의 알파벳 갯수 세기
       v[name[i]-'A']++;
   }

    for(int i=0;i<26;i++){
        if(v[i]%2 !=0){
            odd_char=char(i+65); //홀수 문자 저장해둠
            odd++;//홀수 개의 문자 갯수 세기
            v[i]--; //하나를 따로 저장했으므로 갯수 하나 빼줌
        }
    }
    if(odd>1){ //홀수개인 문자가 2개 이상이면 펠린드롬이 될 수 없음
        return "I'm Sorry Hansoo";
    }
    for(int i=0;i<26;i++){
        if(v[i]%2 ==0 && v[i]!=0){
            int tmp =v[i]/2;
            while(tmp--){ //가지고있는 문자 갯수의 절반만큼을 앞에서 붙여나감
                half_ans+= char(i+65);
            }
        }
    }
    ans=half_ans;
    if(odd>0){ //홀수 갯수인 문자가 있다면
        ans+=odd_char; //앞쪽 절반 마지막에 붙여줌
    }

    reverse(half_ans.begin(),half_ans.end()); //뒤쪽 절반은 앞쪽 절반의 reverse
    return ans+half_ans;

}

int main(){
    string name,ans;
    cin >>name;

    ans=getPalindrome(name);

  cout <<ans;



    return 0;
}