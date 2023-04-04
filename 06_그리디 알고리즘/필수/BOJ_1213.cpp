#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 팰린드롬인지 검사하는 함수
bool checkPalindrome(string s, string &left, char &m) {
	string tmp;
	int n = ceil(s.size() / 2);
	while (s.size()) {
		if (s.size() == 1) {		
			tmp.push_back(s[0]);
			s.erase(0, 1);
		}
		else {
			if (s[0] == s[1]) {
				left.push_back(s[0]);
				s.erase(0, 2);
			}

			else {
				tmp.push_back(s[0]);
				s.erase(0, 1);
			}
		}
	}

	if (tmp.size() > 1) {
		return false;
	}
	if (tmp.size() == 1) {
		m = tmp[0];
	}
	return true;	
}

int main() {
	string str, left_str;
	char mid = NULL;
	bool ch;
	
	// 입력
	cin >> str;

	// 사전순으로 정렬
	sort(str.begin(), str.end());

	// 연산
	ch = checkPalindrome(str, left_str, mid);

	if (ch) {	// 성공 시 팰린드롬 출력
		if (mid) {	// 문자열의 길이가 홀수인 경우
			cout << left_str << mid;
			reverse(left_str.begin(), left_str.end());
			cout << left_str << '\n';
		}

		else {	// 문자열의 길이가 짝수인 경우
			cout << left_str;
			reverse(left_str.begin(), left_str.end());
			cout << left_str << '\n';
		}		
	}

	else {
		cout << "I'm Sorry Hansoo" << '\n';
	}

	return 0;
}