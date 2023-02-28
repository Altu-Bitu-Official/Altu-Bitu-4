#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  //시간 초과 방지
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);



while(1){ //입력 개수가 주어지지 않음

//입력
stack<char> st;
string sentence;
getline(cin,sentence); //입력 가능한 최대 문자 수를 지정하지 않아도 됨.
//개행 문자 만나기 전까지 모든 문자 읽어서 string 객체 (sentence) 에 저장


//괄호가 하나도 없는 경우도 균형잡힌 문자열
if(sentence=="."){
  cout << "yes\n";
  break;
}

//글자 하나씩 탐색
for(int i=0; i<sentence.length(); i++){
  if(sentence[i]=='(' || sentence[i]=='['){
    st.push(sentence[i]);
  }

  else if(sentence[i]==')' || sentence[i]==']'){
    st.pop();
  }

}


if(st.empty()){
  cout << "yes\n";
}
else{ 
  cout << "no\n";
}

}
return 0;
}