#include <iostream>
#include <cmath>

using namespace std;

void diet(const int& i, const int& d, const int& a, const int& t, int& k1, int& k2, int& w1, int& w2) {
	for (int j = 0; j < d; j++) {
		w1 += i - (k1 + a);
		w2 += i - (k2 + a);

		if (abs(i - (k2 + a)) > t) {
			k2 += floor((i - (k2 + a)) / 2.0);
		}
	}
}

int main() {
	int w0, i0, t, d, i, a;

	//�Է�
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	int k1, k2, w1, w2;
	k1 = i0; //��ȭ���� �ʴ� ���� ���� ��緮
	k2 = i0; //��ȭ�ϴ� ���� ���� ��緮

	w1 = w0; //���� ���ʴ�緮 ��ȭ X
	w2 = w0; //���� ���ʴ�緮 ��ȭ O

	//����
	diet(i, d, a, t, k1, k2, w1, w2);

	//���
	//ù��°�� ��� (��ȭ X)
	if (w1 <= 0) { //k1�� �׻� 0���� ŭ
		cout << "Danger Diet" << "\n";
	}
	else {
		cout << w1 << " " << k1 << "\n";
	}
	//�ι�°�� ��� (��ȭ O)
	if (w2 <= 0 || k2 <= 0) {
		cout << "Danger Diet";
	}
	else {
		cout << w2 << " " << k2 << " ";
		if (k2 >= k1) { //��� �߻� ����
			cout << "NO";
		}
		else {
			cout << "YOYO";
		}
	}

	return 0;
}