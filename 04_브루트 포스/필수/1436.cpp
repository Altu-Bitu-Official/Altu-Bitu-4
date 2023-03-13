#include <iostream>
#include <string>
using namespace std;
int n;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int i = 666;
  while(true){
    if(to_string(i).find("666")!=string::npos) {
        n--; //find()
    }
    if(n==0) {
        break;
    }
    i++; //브루트 포스 진행(666, 667, 668... 1666, ..., 2666)
  }
  cout << i << "\n";
  return 0;
}