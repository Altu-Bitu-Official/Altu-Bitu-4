#include <iostream>
#include <string>

using namespace std;

int main() {
	int answer = 0;
	int n;
	//입력
	cin >> n;
	//연산 
	for (int i = 1; i < n; i++) {
		string s = to_string(i);
		int sum = i;
		for (int j = 0; j < s.size(); j++) {
			sum += s[j] - '0';
		}
		if (sum == n) {
			answer = i;
			break;
		}
	}
	//출력
	cout << answer;
}