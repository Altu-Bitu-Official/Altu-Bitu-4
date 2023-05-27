#include <iostream>
#include <string>
using namespace std;
string input, s;
int cnt[200], flag;
char mid;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> input;
  for(char ch: input) cnt[ch]++;
  for(int i = 'Z'; i >= 'A'; i--) {
    if(cnt[i]) {
      if(cnt[i] & 1) { //홀수라면
        mid = char(i); flag++;
        cnt[i]--;
      }
      if(flag == 2) {
        break;
      }
      for(int j = 0; j < cnt[i]; j+= 2) {
        s = char(i) + s;
        s += char(i);
      }
    }  
  }
  if(mid){
    s.insert(s.begin()+s.size()/2, mid);
  } 
  if(flag == 2) {
     cout << "I'm Sorry Hansoo\n";
  }
    else {
      cout << s << "\n";
  }
}