#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool fillPattern(int n, int k, stack<int>& num, stack<char>& alp, vector<char>& result) {
	result.assign(n, '?'); //칸 수 만큼 만들기
	int tip = 0; // pointer
	int j; // 같은 글자가 위치한 자리
	
	result[tip] = alp.top(); //마지막을 기준으로 시작
	alp.pop();

	for (int i = 1; i < k; i++) {
		tip = (tip + num.top()) % n ; // pointer 이동
		num.pop();


		if (find(result.begin(), result.end(), alp.top()) != result.end()) { //이미 해당 글자가 vector에 들어가 있는 상태라면 
			for (j = 0; j < n; j++) {
				if (result[j] == alp.top()) { //같은 글자가 위치한 자리를 파악
					break;
				}
			}
			if (j == tip) { //같은 자리에 위치한다면 넘어감
				alp.pop();
				continue;
			}
			else { // 같은 자리에 위치하지 않는다면 같은 글자가 두 번 이상 등장
				return false;
			}
		}

		if (result[tip] == '?') {
			//새로운 글자라면 넣음
			result[tip] = alp.top();
			alp.pop();
		}
		else { //이미 같은 위치에 다른 글자가 채워져 있는 것이므로 
			return false;
		}
	}

	return true;
}



int main()
{
	int n, k; //바퀴의 칸의 수, 상덕이가 바퀴를 돌리는 횟수
	int s; // 글자가 바뀐 횟수
	char c; // 회전을 멈추었을 때 가리키던 글자
	stack<int> num; //글자가 바뀐 횟수를 저장한 배열
	stack<char> alp; //회전을 멈추었을 때 가리키던 글자를 저장한 배열
	vector<char> result; // 결과를 저장

	//입력
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> s >> c;
		num.push(s);
		alp.push(c);
	}

	//연산 및 출력

	if (fillPattern(n, k, num, alp, result)) {
		for (int i = 0; i < n; i++) {
			cout << result[i];
		}
	}
	else {
		cout << "!";
	}

	return 0;
}