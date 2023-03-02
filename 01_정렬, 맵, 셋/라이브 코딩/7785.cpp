// 상근이는 모든 사람의 출입카드 시스템의 로그를 가지고 있다. 
// 이 로그는 어떤 사람이 회사에 들어왔는지, 나갔는지가 기록되어져 있다. 
// 로그가 주어졌을 때, 현재 회사에 있는 모든 사람을 구하는 프로그램을 작성하시오.

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
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) { // 이름을 사전 순의 역순으로
		cout << *iter << '\n';
	}
	return 0;
}