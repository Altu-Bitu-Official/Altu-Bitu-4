//2607 비슷한 단어
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
  /* 구성이 같은 경우 */
  //1 길이가 같을 때
  //  1-(1) 구성까지 완전히 똑같을 때 
  //  1-(2) 하나의 문자 치환해서 다른 문자 만들 수 있을 때
  //2 길이가 다를 때 
  //  2-(1) 하나의 문자를 빼서 구성을 만들 수 있는가
  //  2-(2) 하나의 문자를 더해서 구성을 만들 수 있는가
  
bool isPossible(string input, int alpha[], string str){
  int cmp_alpha[26]={0,};
  for(int i =0; i < str.size(); i++){
    cmp_alpha[str[i]-'A']++;
  }
  if(input.size()==str.size()){ //둘의 길이가 같다면
    // cout << str << "은 길이가 같은 경우에 속합니다.\n";
    int sub_stitute=0; //치환할 문자 갯수. 하나의 문자만 치환할 수 있으므로 2를 넘어가서는 안됨.
    for(int i =0; i < 26; i++) {
      if(alpha[i]!=cmp_alpha[i]){
        sub_stitute++;
      }
    }
    if(sub_stitute>2){
      return false;
    }
    return true;
  }
  else { //둘의 길이가 다르다면
    // cout << str << "은 길이가 다른 경우에 속합니다.\n";
    for(int i=0; i < 26; i++){
      int plus_or_minus=0; //하나씩 빼거나 더하는 행위를 세어주는 변수. 하나의 문자만을 더하거나oR빼어야 하므로 2를 넘어가서는 안됨
      if(alpha[i]!=cmp_alpha[i]){
        if(abs(alpha[i]-cmp_alpha[i])>2){
          return false; //문자 하나 이상을 빼거나/더하면 하면 안됨.
        }
        else {
          plus_or_minus++;
        }
      }
      if(plus_or_minus>2){
        return false;
      }
      return true;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N; cin>> N;
  int similar=0;
  string input;
  cin >> input; //DOG
  cout << input.size() << "\n";
  int alpha[26]={0,}; bool is_alpha[26]={false,};
  for(int i =0; i < input.size(); i++){
    alpha[input[i]-'A']++; //알파벳 구성
    is_alpha[input[i]-'A']=true; //알파벳 존재
  }
  for(int i =0; i < N-1; i++){
    string str;
    cin >> str;
    if(isPossible(input, alpha, str)){
      similar++;
    }
  }
  cout << similar << "\n";
}
