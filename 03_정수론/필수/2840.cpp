#include <iostream>
#include <vector>

using namespace std;

vector<char> circle;
bool flag = true;
void turn(int s, char c, int p) {
	p += s;
	p %= circle.size();
	if (circle[p] == '?') {
		circle[p] = c;
	}
	else if (circle[p] == c) {
		circle[p] = c;
	}
	else {
		flag = false;
	}
	return;
}
int main() {
	// 입력
	int n, k;
	int s;
	char c;
	cin >> n >> k;
	circle.assign(n, '?'); // '?'로 초기화
	int p = 0; // 바퀴 포인터
	for (int i = k; i > 0; i--) {
		cin >> s >> c;
		turn(s, c, p);
	}

	//출력
	if (flag) {
		for (int i = 0; i < circle.size(); i++) {
			if (p < 0) {
				p += circle.size();
			}
			cout << circle[p];
			p--;
		}
	}
	else {
		cout << '!';
	}
	return 0;
}