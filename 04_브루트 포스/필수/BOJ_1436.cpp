#include <iostream>
using namespace std;

//666�� ������ �Ǻ�
bool isApoNum(int i) {
	while (i != 0) {
		if (i % 1000 == 666) { //���� �������� 666�� ����
			return true;
		}
		else { //���� �������� 666�� �ȵ���
			i /= 10; //���� �ڸ����� ���ְ� ��ĭ�� ����
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0, i = 666;

	//�Է�
	cin >> n;

	while (true) {
		if (isApoNum(i)) { //666�� ����
			cnt++; //ī��Ʈ+1
			if (cnt == n) { //n��° ���̸� ���
				break;
			}
		}
		i++;
	}

	//���
	cout << i;
	return 0;
}