#include <iostream>
#include <queue>
using namespace std;

//n��° ū ���� ����ϴ� �Լ�
int nLarge(int n) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //��� ���� ���� �ݺ�
			int input;
			cin >> input;
			if (pq.size() < n) { //pq�� n�� �̸��� ���� ��������� push
				pq.push(input);
			}
			else { //pq�� n�� �̻��� ���� ���������
				if (pq.top() < input) { //�� �� ���� ���� ���� ���ؼ� Ŭ ��쿡�� push
					pq.pop(); //���� ���� ���� ����
					pq.push(input);
				}
			}
		}
	}
	return pq.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	//�Է�
	cin >> n;
	//����&���
	cout << nLarge(n);
	return 0;
}