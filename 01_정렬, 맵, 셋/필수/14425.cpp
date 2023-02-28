//문자열 정렬
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n, m;
  int result=0;
	string input;
  map<string, bool> str;

	// 입력 및 연산
	cin >> n >> m;
  for (int i=0;i<n;i++){
    cin >> input;
    str[input]=true;

  }

  for (int i=0;i<m;i++){
    cin >> input;
    if (str[input]) result++;

  }


//출력

cout << result;
	return 0;
}