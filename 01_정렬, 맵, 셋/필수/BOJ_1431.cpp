#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_num(const string& s) {
	int num = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			num += s[i] - '0';
		}
	}
	return num;
}

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	int a_num = sum_num(a), b_num = sum_num(b);
	if (a_num != b_num) {
		return a_num < b_num;
	}
	return a < b;
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<string> serial_num(n);
	for (int i = 0; i < n; i++) {
		cin >> serial_num[i];
	}

	//연산
	sort(serial_num.begin(), serial_num.end(), cmp);

	//출력
	for (auto iter : serial_num) {
		cout << iter << '\n';
	}

	return 0;
}