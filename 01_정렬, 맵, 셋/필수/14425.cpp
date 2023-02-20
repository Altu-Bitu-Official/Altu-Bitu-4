#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
//문제의 의도와 안 맞게 푼 것 같습니다.
//어떻게 풀어야 문제의 의도에 맞게 풀 수 있나요? 
int main() {

	int n1, n2,num=0;
	cin >> n1 >> n2;
	string s;
	map<string, int> 집합_s;
	for (int i = 0; i < n1; i++) {
		//입력
		cin >> s;
		집합_s[s]=1;
	}
	for (int i = 0; i < n2; i++) {
		//입력
		cin >> s;
		if (집합_s[s] == 1) {
			num++;
		}
	}
	//출력
	cout << num;

	return 0;
}
