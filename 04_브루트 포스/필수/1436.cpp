#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, cnt = 0;	
	//입력
	cin >> n;
	//연산 & 출력
	for (int i = 666; i < 2066666666; i++) {
		// 방법 1
		string s = to_string(i);
		int suc = 0; // 연속하는 6의 개수
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '6') {  
				suc++;
			}
			else {
				suc = 0; 
			}
			if (suc == 3) { 
				cnt++; 
				break;
			}
		}
		/*
		* 방법 2 
		* s.substr(j, 3) == "666" 
		* substr 사용법 : https://en.cppreference.com/w/cpp/string/basic_string/substr
		* 방법 3  
		* if (s.find("666") != -1) 
		* find 사용법 : https://en.cppreference.com/w/cpp/string/basic_string/find
		*/
		if (cnt == n) {
			return cout << s, 0;
		}
	}
}