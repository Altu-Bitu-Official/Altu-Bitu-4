#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string a, b, big, small;
	cin >> a >> b;
	stack<int> big_stack, small_stack;

	// 숫자를 비교해서 big, small에 각각 저장
	if (a.size() < b.size()) { // 우선 자릿수로 비교
		big = b;
		small = a;
	}
	else if (a.size() > b.size()) {
		big = a;
		small = b;
	}
	else { // 두 수의 자릿수가 같으면 맨 앞의 숫자로 비교
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) {
				big = a;
				small = b;
				break;
			}
			else if (a[i] < b[i]) {
				big = b;
				small = a;
				break;
			}
			else {
				if (i = a.size() - 1) { // 두 수가 완전히 같으면
					big = a;
					small = b;
				}
				continue;
			}
		}
	}

	// 큰 수, 작은 수 각각의 자릿수를 스택에 저장
	while(!big.empty()) {
		big_stack.push(big.front());
		big.erase(0);
	}
	while (!big_stack.empty()) {
		cout << big_stack.top();
		big_stack.pop();
	}
	while (!small.empty()) {
		small_stack.push(small.front());
		small.erase(0);
	}

	int smallDigit = small_stack.size();
	int bigDigit = big_stack.size();

	stack<int> result;
	int add;
	int before = 0; // 이전 자리에서 올라온 수

	// 작은 수 + 큰 수를 더해서 저장, 각 자릿수마다 반복
	for (int i = 0; i < smallDigit; i++) {
		add = big_stack.top() + small_stack.top() + before; // 현재 자리에 더해질 총 수
		before = add / 10; // 다음 자리로 올라갈 수

		if (add >= 10) {			
			add %= 10; // 현재 자리에 더해질 수
		}

		result.push(add);
		big_stack.pop();
		small_stack.pop();
	}
	// 큰 수를 저장
	for (int i = smallDigit; i < bigDigit; i++) {
		add = big_stack.top() + before;
		before = add / 10;

		if (add >= 10) {
			add %= 10;
		}

		result.push(add);
		big_stack.pop();
	}

	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	return 0;
}