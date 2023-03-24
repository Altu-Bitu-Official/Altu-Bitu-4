#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, num;
	priority_queue<int> pq;

	//입력
	cin >> n;

	//연산 및 출력
	while (n--) {
		cin >> num;
		if (!num) { //0이 입력으로 들어오면 선물의 가치 출력
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else { //0이 아니면 선물 충전
			int cnt;
			for (int i = 0; i < num; i++) {
				cin >> cnt;
				pq.push(cnt);
			}
		}
	}

	return 0;

}