#include <iostream>
#include <queue>
using namespace std;

// N번째로 큰 수 출력
// N*N의 수를 모두 pq에 넣어 계산하면 메모리초과 발생
// 상위 n개의 숫자에서 n번째 숫자는 가장 작은 숫자네요!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int, vector<int>,greater<int>> pq; // 오름차순 정렬 (가장 작은 수가 우선순위 높음)
	int N;
	cin >> N;

	// pq에 수를 넣으면서 pq의 크기가 N보다 커지면 가장 작은 수 버림
	for (int i = 0; i < N * N; i++) {
		int a;
		cin >> a;
		pq.push(a);
		if (pq.size() > N) {
			pq.pop(); // 가장 작은 수 버림
		}
	}
	cout << pq.top() << "\n"; 
	return 0;
}