#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";

	int index = 0;
	stack<int> s;
	for (int i = 0; i < number.size(); i++) {
		//스택의 top에 있는 숫자보다 더 크거나 같은 숫자들만 추가될 수 있으므로
		//작은 숫자들은 제거하고 해당 숫자 스택에 넣기
		while (!s.empty() && number[i] - '0' > s.top() && k > 0) {
			s.pop();
			k--;
		}
		s.push(number[i] - '0');
	}

	//더 지워져야한다면, 마지막에 그만큼 숫자 제거하기
	while (k > 0) {
		s.pop();
		k--;
	}
	
	//스택에서 숫자 꺼내서 정답 구하기
	while (!s.empty()) {
		answer = to_string(s.top()) + answer;
		s.pop();
	}
    return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string number;
	int k;
	cin >> number >> k;

	//연산 & 출력
	cout << solution(number, k);

	return 0;
}