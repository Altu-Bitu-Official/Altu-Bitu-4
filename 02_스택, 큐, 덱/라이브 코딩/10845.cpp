// ť
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, x;
	queue<int> s;
	string input;

	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "push") {
			cin >> x;
			s.push(x);
		}
		else if (input == "pop") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.front() << '\n';
				s.pop();
			}
		}
		else if (input == "size") {
			cout << s.size() << '\n';
		}
		else if (input == "empty") {
			cout << s.empty() << '\n';
		}
		else if (input == "front") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.front() << '\n';
			}
		}
		else if (input == "back") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.back() << '\n';
			}
		}
	}
}




