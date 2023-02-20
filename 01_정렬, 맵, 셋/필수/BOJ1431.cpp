/*1.길이 짧은 순서
2.자리수의 합이 작은 순서
3. 사전순(숫자<알파벳)*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(const string& x, const string& y) {
	if (x.size() != y.size()) {
		return x.size() < y.size();
	}
	int sum_x = 0;
	int sum_y = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= '0' && x[i] <= '9') {
			sum_x += int(x[i])- 48;
		}
		if (y[i] >= '0' && y[i] <= '9') {
			sum_y += int(y[i])- 48;
		}
	}
	if (sum_x != sum_y) {
		return sum_x < sum_y;
	}
	return x < y;
}


int main() {
	int N;
	cin >> N;
	string serial[50];
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}
	sort(serial, serial+N, compare);
	for (int i = 0; i < N; i++) {
		cout << serial[i] << '\n';
	}
	return 0;
}