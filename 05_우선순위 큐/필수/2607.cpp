#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<string> s;
int similarWord(vector<string>& s) {
	string strdef = s[0]; // ù�ܾ �������� 
	int words = 0;
	for (int i = 1; i < s.size(); i++) {
		int cnt = 0;
		string strvar = s[i];
		int l = strvar.length() - strdef.length();
		// ���� ���� 2 �̻��̸� ������
		if (abs(l) > 1) {
			continue;
		}
		// �������� 0�̸�
		else if (l == 0) {
			// find�� �˻�
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) { // find �ؼ� ã�� ���� ������ string::npos �� ��ȯ�Ѵ�.
					cnt++;
				}
			}
			if (cnt <= 1) { // �ϳ��� �ٸ� �� ������
				words++;
			}
		}
		// �������� 1�̸�
		else if (l == 1) {
			// find�� �˻�
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt == 0) { // ���� ���̰� 1�̸� �ϳ��� ���� ���� ������ �ȴ�. ��� ���ڰ� �־����. 
				words++;
			}
		}
		else if (l == -1) {
			// find�� �˻�
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt <= 1) { // ���� ���̰� -1�̸� �ϳ��� ���ؾ� ���� ������ ��. ���� ���� ���� �ϳ� ����� ��� �־���Ѵ�.
				words++;
			}
		}
	}
	return words;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}
	cout << similarWord(s);
	return 0;
}