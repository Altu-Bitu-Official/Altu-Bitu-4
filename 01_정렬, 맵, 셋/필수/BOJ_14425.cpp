#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m;
	string input;
	set<string> s;
	int result = 0;

	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		s.insert(input);
	}

	//����
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (s.find(input) != s.end()) {
			result++;
		}
	}

	//���� & ���
	cout << result;

	return 0;
}