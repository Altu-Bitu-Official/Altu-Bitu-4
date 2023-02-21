/*시리얼 번호*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	int sumA = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			sumA += int(a[i]) - 48;
		}
	}
	int sumB = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] >= '0' && b[i] <= '9') {
			sumB += int(b[i]) - 48;
		}
	}
	if (sumA != sumB) {
		return sumA < sumB;
	}
	return a < b;
}


int main() {
	int n;
	cin >> n;
	vector<string> serial;
	serial.assign(n, "a");
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	sort(serial.begin(), serial.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}
}