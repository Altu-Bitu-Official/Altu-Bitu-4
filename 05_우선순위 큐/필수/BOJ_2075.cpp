#include <iostream>
#include <queue>

using namespace std;

// Min heap으로 만들기
struct cmp {
	bool operator()(const int& x, const int& y) {
		return x > y;
	}
};

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, square;
	priority_queue<int, vector<int>, cmp> pq;

	// 입력 및 연산
	cin >> n;
	square = n * n;

	while (square--) {
		cin >> x;
		if (pq.size() < n) {	// 입력받은 수를 큐에 저장하다가 요소의 개수가 n개보다 커지면 가장 작은 요소부터 지우기
			pq.push(x);
		}
		pq.push(x);
		pq.pop();					
	}
	
	// 출력
	cout << pq.top() << '\n';	// 입력이 끝난 후 큐에 최종적으로 남아있는 요소 중 가장 작은 것 출력
	
	return 0;
}