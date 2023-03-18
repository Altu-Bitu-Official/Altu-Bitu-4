#include <iostream>
#include <string>
using namespace std;

//����� �ܾ� ���� ��� �Լ�
bool cmpSim(string a, string b) {
	int aArr[26] = { 0 };
	int bArr[26] = { 0 };

	//word�� ���� ���ĺ� �迭�� �÷���
	for (int i = 0; i < a.length(); i++) {
		aArr[a[i] - 'A'] += 1;
	}
	for (int i = 0; i < b.length(); i++) {
		bArr[b[i] - 'A'] += 1;
	}

	int diff = 0, acnt = 0, bcnt = 0;
	for (int i = 0; i < 26; i++) {
		diff += abs(aArr[i] - bArr[i]); //diff: ���� ����
	}
	if (abs(int(a.length() - b.length())) <= 1 && diff <= 2) { //���� �� ���̰� 1 �����̰�, ���� ���̰� 2 �����϶�
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;
	string word;

	//�Է�
	cin >> n;
	cin >> word;

	//����
	while (--n) {
		string input;
		cin >> input;
		if (cmpSim(word, input)) {
			cnt++;
		}
	}

	//���
	cout << cnt;
	return 0;
}