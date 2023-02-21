#include <iostream>
#include <set>

using namespace std;

/*
* set을 이용하여 출퇴근 하는 사람들을 관리
*/

int main()
{
	int n;
	string input, state;
	set<string> s;
	// 입력 & 연산
	cin >> n;
	while (n--) {
		cin >> input >> state;
		if (state == "enter") { // 출근 시 set에 추가
			s.insert(input);
		}
		else { // 퇴근 시 set에서 제거
			s.erase(input);
		}
	}
	// 출력
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) { // 이름을 사전 순의 역순으로 
		cout << *iter << '\n';
	}
	return 0;
}