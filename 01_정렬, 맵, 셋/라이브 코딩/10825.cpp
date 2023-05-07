// 도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.
// 국어 점수가 감소하는 순서로
// 국어 점수가 같으면 영어 점수가 증가하는 순서로
// 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
// 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로(단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student { // 학생 정보 구조체: 이름, 국어 점수, 영어 점수, 수학 점수
	string name;
	int kor, eng, math;
};

// 비교 함수(bad)
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

// 비교 함수(good)
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