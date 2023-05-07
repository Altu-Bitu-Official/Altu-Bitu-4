// µ¦
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, x;
	deque<int> s;
	string input;

	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "push_front") {
			cin >> x;
			s.push_front(x);
		}
		else if (input == "push_back") {
			cin >> x;
			s.push_back(x);
		}
		else if (input == "pop_front") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.front() << '\n';
				s.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.back() << '\n';
				s.pop_back();
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




