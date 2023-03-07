#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> yosephus(int n, int k) {
	queue<int> q; // n번째까지의 원
	vector<int> arr;

	// 1~n까지의 원 구성
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (n) { //큐에 원소가 없을 때까지 반복 
		for (int i = 1; i < k; i++) { //k 전까지는 큐의 back으로 순서 미루기 
			q.push(q.front());
			q.pop();
		}
		arr.push_back(q.front()); // k번째 원소 넣고 제거
		q.pop();
		n--;
	}

	return arr;
}

int main()
{
	int n, k; // n개의 숫자와 제거할 k번째 숫자
	vector<int> result; // 출력할 결과를 담을 벡터

	//입력
	cin >> n >> k;

	//연산
	result = yosephus(n, k);

	//출력
	cout << "<";
	
	for (int i = 0; i < n - 1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[n-1] << ">"; // 마지막 원소 출력 

	return 0;
}