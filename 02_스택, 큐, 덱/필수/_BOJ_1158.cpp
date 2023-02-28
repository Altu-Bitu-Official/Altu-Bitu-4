#include <iostream>
#include <deque>
using namespace std;

// 처음에 벡터 사용시 시간 초과
// -> 시간복잡도가 더 작은 덱 사용
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	deque <int> q;

	// 1 2 3 4 5 6 7
	for (int i = 0; i < N; i++) {
		q.push_back(i + 1);
	}
	cout << "<";
	// <3, 6, 2, 7, 5, 1, 4,>처럼 출력되는 것 방지
	while (q.size() > 1) {
		// 앞에서 k-1만큼 빼서 
		for (int i = 0; i < K - 1; i++) {
			int front = q.front();
			q.pop_front();
			q.push_back(front);
		}
		// 다시 뒤에 추가한 후, k번째 출력
		cout << q.front() << ", ";
		q.pop_front();
		// 출력 후 제거하여 중복되어 출력되지 않도록
	}
	// 원소 1개만 남았을 경우 , 출력하지 않고 >만 출력
	cout << q.front() << ">";
	return 0;
}

