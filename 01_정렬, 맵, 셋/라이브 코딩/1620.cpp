/*
첫째 줄에는 도감에 수록되어 있는 포켓몬의 개수 N이랑 내가 맞춰야 하는 문제의 개수 M이 주어져. 
N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수야.
둘째 줄부터 N개의 줄에 포켓몬의 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와. 포켓몬의 이름은 모두 영어로만 이루어져있고, 또, 음... 첫 글자만 대문자이고, 나머지 문자는 소문자로만 이루어져 있어.
일부 포켓몬은 마지막 문자만 대문자일 수도 있어. 포켓몬 이름의 최대 길이는 20, 최소 길이는 2야. 그 다음 줄부터 총 M개의 줄에 내가 맞춰야하는 문제가 입력으로 들어와. 문제가 알파벳으로만 들어오면 포켓몬 번호를 말해야 하고, 
숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야해. 입력으로 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어져.
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
* 입출력 속도 향상 필요
* 두 개의 map을 이용하여 이름과 번호를 저장
* 숫자/문자열 입력을 구분하여 풀이
*/

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string input;
	map<string, int> name; // key: 이름, value: 번호
	map<int, string> num; // key: 번호, value: 이름

	cin >> n >> m;
	// vector<string> num(n + 1, ""); // key가 int 형일 때는 vector를 사용하는 것이 빠름
	
	for (int i = 1; i <= n; i++) {
		cin >> input;
		name[input] = i;
		num[i] = input;
	}

	while (m--) {
		cin >> input;
		if (isdigit(input[0])) {
			cout << num[stoi(input)] << '\n'; // stoi: string to int
		}
		else {
			cout << name[input] << '\n';
		}
	}
	return 0;
}