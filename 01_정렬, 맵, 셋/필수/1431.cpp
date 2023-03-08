#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시리얼 번호를 구성하는 숫자의 합을 구하는 함수
int sumNum(string serial_num) {
	int sum = 0;
	for (int i = 0; i < serial_num.size(); i++) {
		if (isdigit(serial_num[i])) { // 문자(char)가 숫자인 경우에만 더함
			sum += serial_num[i] - '0'; // char to int (아스키 코드 사용)
		}
	}
	return sum;
}

// 비교 함수
bool cmp(const string& s1, const string& s2)
{
	if (s1.size() != s2.size()) { // 길이가 다르면 짧은 것 먼저
		return s1.size() < s2.size();
	}
	if (sumNum(s1) != sumNum(s2)) { // 길이가 같고 자리수의 합이 다르면 작은 합을 가지는 것 먼저
		return sumNum(s1) < sumNum(s2);
	}
	return s1 < s2; // 길이와 자리수의 합이 같으면 사전순 (숫자 < 알파벳)
}

/*
* 시리얼 번호의 정렬 조건을 비교 함수로 구현
* 문자열에서 숫자만의 합 구하기
*/

int main()
{
	int n;
	// 입력
	cin >> n;
	vector<string> guitar(n, "");
	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}
	// 연산
	sort(guitar.begin(), guitar.end(), cmp);
	// 출력
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}
	return 0;
}
