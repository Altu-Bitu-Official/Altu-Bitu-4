#include <iostream>
#include <string>

using namespace std;

string namingMovie(int n){
  int i = 666;
  string tmp;

  while (n >0){
    tmp = to_string(i);
    if(tmp.find("666") != -1){  //666문자를 찾으면 n 줄이기 
        n--;
    }
    i++;
  }
  return tmp;
}

int main() {
    int n;
    //입력
    cin >> n;

    //출력 
    cout << namingMovie(n);
    return 0;
}