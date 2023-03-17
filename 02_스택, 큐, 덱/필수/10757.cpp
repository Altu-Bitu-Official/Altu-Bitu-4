#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//스택에 숫자 담기
void putNumber(stack<int>& s, string& a ) {
	for (int i = 0; i < a.length(); i++) {
		s.push((a[i] - '0'));
	}
}

//더한 값이 10이상인지 아닌지 확인해주는 함수
void cmpSize(int& n, int& top, stack<int>& result) {
	if (n < 10) {//만약 한 자릿수의 합이 10 이하면 그냥 더해주기
		top = 0;
		result.push(n);
	}
	else {//한 자릿수의 합이 10 이상이면 올림수를 설정하고 10을 뺀 나머지를 더해주기
		top = 1;
		result.push((n - 10));
	}
}

//나머지 스택에 반영 안된 자릿 수들 추가하기
void addTop(stack<int>& s, int& top) {
	while (!s.empty()) {
		if (top == 1) { // 마지막 올림수까지 반영
			n = s.top() + 1;
			cmpSize(n, top, result);
		}
		else {
			result.push(s.top());
		}

		s.pop(); // 계산한 자릿 수 지우기
	}
}

// 숫자 합 계산하기
void sumNumber(stack<int>& s1, stack<int>& s2, stack<int>& result) {
	int n, top = 0; // 한 자리씩 계산하는 변수, 올림하는 수

	while (!s1.empty() &&
		!s2.empty()) { // 둘 중 하나 빌 때까지
		n = s1.top() + s2.top() + top;

		// 계산한 자릿수는 비우기
		s1.pop();
		s2.pop();

		//연산해 저장
		cmpSize(n, top, result);
	}

	// 나머지 스택에 반영 안된 자릿 수들 추가하기 
	addTop(s1, top);
	addTop(s2, top);

	if (top == 1) { // 최종 올림 수 추가
		result.push(1);
	}
}

int main()
{
	string a, b;
	stack<int>s1; // a 담을 스택
	stack<int>s2; // b 담을 스택
	stack<int>result; // a+b를 담을 스택

	//입력
	cin >> a >> b;
	
	//스택에 숫자 넣기
	putNumber(s1, a);
	putNumber(s2, b);

	//연산
	sumNumber(s1, s2, result);

	//출력 
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}