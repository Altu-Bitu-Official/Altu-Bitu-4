#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> pq;
	int n;

	cin >> n;

	while(n--) {
		int a;
		cin >> a;
		if (a == 0) { //���̵��� ������ ��
			if (pq.empty()) { //������ ������
				cout << "-1\n";
			}
			else { //������ ������ ��ġ ���
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else { //�������϶�
			while (a--) {
				int input;
				cin >> input;
				pq.push(input);
			}
		}
	}

	return 0;
}