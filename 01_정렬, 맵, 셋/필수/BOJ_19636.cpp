#include <iostream>
#include <cmath>

using namespace std;

void diet(const int& i, int& d, const int& a, const int& t, int& k2, int& w2) {
	while (d--) {
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
	w1 += (i - k1 - a) * d;
	diet(i, d, a, t, k2, w2);

	//���
	//ù��°�� ��� (��ȭ X), k1�� �׻� 0���� ŭ
	(w1 <= 0) ? cout << "Danger Diet\n" : cout << w1 << " " << k1 << "\n";

	//�ι�°�� ��� (��ȭ O)
	if (w2 <= 0 || k2 <= 0) {
		cout << "Danger Diet";
		return 0;
	}
	cout << w2 << " " << k2 << " ";
	if (k2 >= k1) { //��� �߻� ����
		cout << "NO";
	}
	else {
		cout << "YOYO";
	}

	return 0;
}