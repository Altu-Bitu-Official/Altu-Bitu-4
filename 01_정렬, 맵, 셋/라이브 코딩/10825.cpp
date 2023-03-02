// �����̳� �� �л� N���� �̸��� ����, ����, ���� ������ �־�����. �̶�, ������ ���� �������� �л��� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ���� ������ �����ϴ� ������
// ���� ������ ������ ���� ������ �����ϴ� ������
// ���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
// ��� ������ ������ �̸��� ���� ������ �����ϴ� ������(��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student { // �л� ���� ����ü: �̸�, ���� ����, ���� ����, ���� ����
	string name;
	int kor, eng, math;
};

// �� �Լ�(bad)
bool cmp(const student& s1, const student& s2) {
	if (s1.kor == s2.kor) {
		if (s1.eng == s2.eng) {
			if (s1.math == s2.math) {
				return s1.name < s2.name;
			}
			return s1.math > s2.math;
		}
		return s1.eng < s2.eng;
	}
	return s1.kor > s2.kor;
}

// �� �Լ�(good)
bool cmpAdv(const student& s1, const student& s2) {
	if (s1.kor != s2.kor) {
		return s1.kor > s2.kor;
	}
	if (s1.eng != s2.eng) {
		return s1.eng < s2.eng;
	}
	if (s1.math != s2.math) {
		return s1.math > s2.math;
	}
	return s1.name < s2.name;
}

int main() {
	int n;
	vector<student> my_class;
	cin >> n;
	my_class.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> my_class[i].name >> my_class[i].kor >> my_class[i].eng >> my_class[i].math;
	}
	sort(my_class.begin(), my_class.end(), cmpAdv);
	for (int i = 0; i < n; i++) {
		cout << my_class[i].name << ' ';
	}
	return 0;
}