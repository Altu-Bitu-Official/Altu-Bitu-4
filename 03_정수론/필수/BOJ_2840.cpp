#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, s, arrow = 0;
	char letter;
	bool is_wheel = true;

	//�Է�
	cin >> n >> k;
	vector<char> wheel(n,'?'); //nĭ�� ���� ����
	for (int i = 0; i < k; i++) {
		cin >> s >> letter;
		arrow = (arrow + s) % n;
		if (wheel[arrow] == '?' || wheel[arrow] == letter) {
			wheel[arrow] = letter;
		}
		else { //�ٸ� ���ڰ� ��������
			is_wheel = false; //�ش��ϴ� ������ �������� ����
			break;
		}
	}
	//�ߺ��� Ȯ��
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (wheel[i] == wheel[j] && wheel[i] != '?') {
				is_wheel = false;
			}
		}
	}

	//���
	arrow += n;
	if (!is_wheel) {
		cout << '!';
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << wheel[(arrow - i) % n];
		}
	}
	return 0;
}