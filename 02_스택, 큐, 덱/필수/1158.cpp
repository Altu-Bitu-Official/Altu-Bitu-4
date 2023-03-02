#include<iostream>
#include<queue>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k; //입력 받음

	queue<int> arr; //자료구조 큐를 이용

	for (int i = 1; i <= n; i++) {
		arr.push(i);
	}//1~n까지의 원

	cout << '<';

	while (arr.size() > 1) {
		for (int i = 1; i < k; i++) {
			int tmp = arr.front();
			arr.pop();
			arr.push(tmp); //k번째가 될 때까지 숫자를 pop했다가 push하는 것을 반복함
		}
		cout << arr.front() << ", ";
		arr.pop(); //숫자를 출력하고 pop 함으로써 queue에서 삭제
	}

	cout << arr.front() << '>'; //마지막 숫자 뒤에는 ','이 붙지 않으므로 따로 출력
}