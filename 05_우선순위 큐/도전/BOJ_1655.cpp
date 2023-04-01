#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void balance(priority_queue<int>& left_pq, priority_queue<int, vector<int>, greater<>>& right_pq) {
	if (left_pq.top() > right_pq.top()) {
		int M = left_pq.top();
		int m = right_pq.top();

		left_pq.pop();
		right_pq.pop();

		left_pq.push(m);
		right_pq.push(M);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x;
	cin >> n;

	priority_queue<int> left_pq; //최대 힙
	priority_queue<int, vector<int>, greater<>> right_pq; //최소 힙

	while (n--) {
		cin >> x;

		//연산
		//짝수번째 입력: 왼쪽 힙의 개수가 1만큼 크고 가운데수이므로 왼쪽 힙의 최댓값 출력
		//홀수번째 입력: 양쪽 힙의 개수가 같으므로 그 중 작은 값인 왼쪽 힙의 최댓값 출력

		//양쪽 힙의 사이즈를 같거나 왼쪽 힙이 1만큼 더 크도록 저장
		if (left_pq.size() > right_pq.size()) {
			right_pq.push(x);
		}
		else {
			left_pq.push(x);
		}

		if (!left_pq.empty() && !right_pq.empty()) {
			balance(left_pq, right_pq);
		}

		//출력
		cout << left_pq.top() << "\n";
	}
	return 0;
}
