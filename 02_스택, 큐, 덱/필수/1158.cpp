#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void yosephus(int n, int k, queue<int>& q) {
	while (n != 1) { //큐에 원소가 하나 남을때까지 반복 
		for (int i = 1; i < k; i++) { //k 전까지는 큐의 back으로 순서 미루기 
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", "; //k번째 원소 출력 후 제거 
		q.pop();
		n--;
	}
}

int main()
{
	int n, k; // n개의 숫자와 제거할 k번째 숫자
	queue<int> q; // n번째까지의 원

	//입력
	cin >> n >> k;

	// 1~n까지의 원 구성

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}


	//연산 및 출력
	cout << "<";
	
	yosephus(n, k, q);

	cout << q.front() << ">"; // 마지막 원소 출력 
	q.pop();

	return 0;
}