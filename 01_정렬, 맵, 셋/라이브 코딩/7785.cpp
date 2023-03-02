// ����̴� ��� ����� ����ī�� �ý����� �α׸� ������ �ִ�. 
// �� �α״� � ����� ȸ�翡 ���Դ���, ���������� ��ϵǾ��� �ִ�. 
// �αװ� �־����� ��, ���� ȸ�翡 �ִ� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	string input, state;
	set<string> s;
	while (n--) {
		cin >> input >> state;
		if (state == "enter") {
			s.insert(input);
		}
		else {
			s.erase(input);
		}
	}
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) { // �̸��� ���� ���� ��������
		cout << *iter << '\n';
	}
	return 0;
}