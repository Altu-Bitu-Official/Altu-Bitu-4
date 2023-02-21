#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
* 입출력 속도 향상 필요
* 두 개의 map을 이용하여 이름과 번호를 저장
* 숫자/문자열 입력을 구분하여 풀이
*/

int main()
{
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string input;
	map<string, int> name; // key: 이름, value: 번호
	map<int, string> num; // key: 번호, value: 이름
	// 입력
	cin >> n >> m;
	// vector<string> num(n + 1, ""); // key가 int 형일 때는 vector를 사용하는 것이 빠름

	// 연산
	for (int i = 1; i <= n; i++) { // 번호: 1 ~ n
		cin >> input;
		name[input] = i; // 입력된 이름의 번호 저장
		num[i] = input; // 입력된 번호의 이름 저장
	}
	// 출력
	while (m--) {
		cin >> input;
		if (isdigit(input[0])) { // 입력이 숫자인 경우: 이름 출력
			cout << num[stoi(input)] << '\n'; // stoi: string to int
		}
		else { // 입력이 문자열인 경우: 번호 출력
			cout << name[input] << '\n';
		}
	}
	return 0;
}