#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	int a_num = 0, b_num = 0;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a[i])) {
			a_num += a[i] - '0';
		}
		if (isdigit(b[i])) {
			b_num += b[i] - '0';
		}
	}
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