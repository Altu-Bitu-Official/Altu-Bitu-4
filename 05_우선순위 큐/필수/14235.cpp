#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int givePresent( priority_queue<int> & bag) {
	int present;
	if (bag.empty()) {
		present = -1;
	}
	else {
		present = bag.top();
		bag.pop();
	}
	return present;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���� ����
	priority_queue<int> bag;
	// �Է�
	int n, a;
	cin >> n;

	int p;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) { // ���̵��� ����
			cout << givePresent(bag) << endl;
		}
		else { // ���� ����
			for (int j = 0; j < a; j++) {
				cin >> p;
				bag.push(p);
			}
		}
	}
	return 0;
}