#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findH(int a) {
	int ans = 0;
	// 1000 �� ������ �ش� �ȵ�
	for (int i = 1; i <= a; i++) {
		string num = to_string(i);
		// ���ڸ���
		if (num.length() == 1) {
			ans++;
		}
		// ���ڸ���
		else if (num.length() == 2) {
			ans++;
		}
		// ���ڸ���
		else if (num.length() == 3) {
			if (num[0] - num[1] == num[1] - num[2]) {
				ans++;
			}
		}
		else {
			continue;
		}
	}
	return ans;
}
int main() {

	int a;
	cin >> a;

	cout << findH(a);
	return 0;
}