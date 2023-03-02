/*
�Է��� �� 2N+1���� �ٷ� �̷���� �ִ�. ù �ٿ��� ���� ��� N(1 �� N �� 1,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ����̰� ���� ���� ��ȣ ����� �־�����, N+2° �ٺ��� N���� �ٿ��� �����̰� ���� ���� ��ȣ ����� �־�����. 
�� ���� ��ȣ�� 6���� �̻� 8���� ������ ���ڿ���, ���� �빮��('A'-'Z')�� ����('0'-'9')�θ� �̷���� �ִ�.
���� ���� ��ȣ�� �� �� �̻� �־����� ���� ����.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// A���� �ͳο��� �ʰ� ���� �� �߿��� A���� �ε����� ���� ���� �ϳ��� �ִٸ� ���� ���Դµ� ���� �� A���� �ڿ� �ִٴ� ���̹Ƿ� �߿��� �ǹ�

// �ͳ� �ȿ��� �߿��� ���� ����� ���ϴ� �Լ�
int overtake(int n, vector<int>& order_out) {
	int ans = 0; // �߿��� ���� ���
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // ���� ������ �� �ʰ� ���� ������ Ȯ��
			if (order_out[i] > order_out[j]) { // �� �ʰ� �� ���� �� ���� ������ ��� -> �߿�
				ans++;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	string car;
	map<string, int> order_in; 
	vector<int> order_out; 
	cin >> n;
	for (int i = 1; i <= n; i++) { // ���� ����
		cin >> car;
		order_in[car] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> car;
		order_out.push_back(order_in[car]);
	}
	cout << overtake(n, order_out) << '\n';
}