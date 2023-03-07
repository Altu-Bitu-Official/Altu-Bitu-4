#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int generateWheel(int s, char l, int size, char* p_wheel, int* ptr) {
	// 화살표가 가리키는 위치 변경
	* ptr = (*ptr + size - (s % size)) % size;

	// 바퀴에 글자 입력
	if (p_wheel[*ptr] == '?') {	// 칸이 비어있을 때
		bool check = find(p_wheel, p_wheel + size, l) == p_wheel + size;	// 이미 입력된 글자인지 체크
		if (check) {	// 없는 글자라면 새로 입력하고 1 리턴 (성공)
			p_wheel[*ptr] = l;
			return 1;
		}
		else return 0;	// 중복된 글자 존재하면 0 리턴 (실패)
	}
	else {	// 칸이 채워져있을 때
		if (p_wheel[*ptr] == l) {	// 입력하고자 하는 글자가 이미 있다면 1 리턴 (성공)
			return 1;
		}
		else return 0;	// 다른 글자가 입력되어 있다면 0 리턴 (실패)
	}
}

int main() {
	// 입력
	int n, k, s, arrow, result;
	char letter;
	cin >> n >> k;

	// 바퀴 초기 설정
	char* wheel = new char[n];
	for (int i = 0; i < n; i++) {
		wheel[i] = '?';
	}
	arrow = 0;

	// 연산
	int c = 0;
	while (k--) {
		cin >> s >> letter;
		result = generateWheel(s, letter, n, wheel, &arrow);
		if (!result) {
			c++;
		}
	}

	// 결과 출력	
	if (c > 0) {
		cout << "!" << '\n';
		return 0;
	}
	int size = n;
	while (n--) {
		cout << wheel[arrow];
		arrow = (arrow + 1) % size;
	}

	delete[] wheel;

	return 0;
}
