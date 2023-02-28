/*총 n개의 문자열로 이루어진 집합S
력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개*/

#include <iostream>
#include <set>

using namespace std;
int main() {
	//입력: 문자열의 개수n, m
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int count = 0;
	cin >> n >> m;
	//입력: 집합 s에 포함된 문자열 n개
	string str, str_i;
	set<string> s;
	set<string> test;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
	}
	//입력:문자열m개
	for (int i = 0; i < m; i++) {
		cin >> str_i;
		if (s.count(str_i)) count++; //count 함수 특정 원소의 갯수 셀 수 있음
		}
	//출력: m개중 집합s에 포함되는 문자열 개수
	cout << count;
	return 0;
}