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
	if (s1.kor == s2.kor) { // 국어 점수가 같으면
		if (s1.eng == s2.eng) { // 국어, 영어 점수가 같으면
			if (s1.math == s2.math) { // 국어, 영어, 수학 점수가 같으면 
				return s1.name < s2.name; // 이름이 사전 순으로 증가하는 순서
			}
			return s1.math > s2.math; // 수학 점수가 감소하는 순서
		}
		return s1.eng < s2.eng; // 영어 점수가 증가하는 순서
	}
	return s1.kor > s2.kor; // 국어 점수가 감소하는 순서
}

// 비교 함수(good)
bool cmpAdv(const student& s1, const student& s2) {
	if (s1.kor != s2.kor) {// 국어 점수가 감소하는 순서
		return s1.kor > s2.kor;
	}
	if (s1.eng != s2.eng) {// (국어 점수가 같으면) 영어 점수가 증가하는 순서
		return s1.eng < s2.eng;
	}
	if (s1.math != s2.math) {// (국어, 영어 점수가 같으면) 수학 점수가 감소하는 순서
		return s1.math > s2.math;
	}
	return s1.name < s2.name; // (국어, 영어, 수학 점수가 같으면) 이름이 사전 순으로 증가하는 순서
}

/*
* 학생 정보를 구조체에 저장
* 정렬 방법을 비교 함수에 추가
*/

int main()
{
	int n;
	vector<student> my_class;
	// 입력
	cin >> n;
	my_class.assign(n, {});
	for (int i = 0; i < n; i++) { // 이름, 국어, 영어, 수학 점수
		cin >> my_class[i].name >> my_class[i].kor >> my_class[i].eng >> my_class[i].math;
	}
	// 연산
	sort(my_class.begin(), my_class.end(), cmpAdv);
	// 출력
	for (int i = 0; i < my_class.size(); i++) {
		cout << my_class[i].name << '\n';
	}
	return 0;
}