#include <iostream>
#include <set>

using namespace std;

/*
* set::find 함수 사용 (key 값이 존재하면 해당 iterator, 존재하지 않으면 set::end 반환)
* vector를 이용하면 원소를 탐색하면 시간 복잡도가 O(n) (시간 초과)
* set은 이진트리 구조를 사용하므로 원소 탐색의 시간 복잡도가 O(log2n)
* 1. find 함수 사용
* 2. count 함수 사용
*/

int main()
{
	int n, m, cnt = 0;
	set<string> s;
	string input;
	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> input;
		s.insert(input); // set에 원소 추가
	}
	// 연산
	while (m--) {
		cin >> input;
		// 1. find 함수 사용
		if (s.find(input) != s.end()) { // set에 원소가 포함되어 있는지 확인
			cnt++;
		}
		//  2. count 함수 사용
		// cnt += s.count(input); // set에 해당 원소의 존재 여부를 int형으로 리턴
	}
	// 출력
	cout << cnt << '\n';
	return 0;
}