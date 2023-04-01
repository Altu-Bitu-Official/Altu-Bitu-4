#include <iostream>
#include <queue>

using namespace std;

// 거점들을 세워 방문하며 선물 충전, 자신이 들고 있는 선물 중 가장 가치가 큰 선물을 줌
// 차례대로 방문한 아이들과 거점지의 정보 입력 -> 아이즐이 준 선물들의 가치 출력
// 줄 선물 없으면 -1 출력

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n,a;
	cin >> n; // 아이들과 거점지 방문한 횟수

	priority_queue<int> q;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a != 0) {
			for (int j = 0; j < a; j++) {
				int b;
				cin >> b;
				q.push(b);
			}
		}
		else { // a가 0이면 
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.top() << "\n"; // 가장 가치가 큰 수 출력
				q.pop();
			}
		}
	}
	
	return 0;
}