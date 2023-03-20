#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, a, gift;
	cin >> n;
	priority_queue<int> pq;

	//연산 & 출력
	while (n--) {
		cin >> a;
		//아이들 만남
		if (a == 0) {
			//아이들한테 줄 선물이 없는 경우
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				//가장 가치가 높은 선물을 주고 제거
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		//선물 충전
		else {
			while (a--) {
				cin >> gift;
				pq.push(gift);
			}
		}
	}
	
	return 0;
}