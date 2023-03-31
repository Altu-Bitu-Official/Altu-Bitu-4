#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> pq;
	int n;

	cin >> n;

	while(n--) {
		int a;
		cin >> a;
		if (a == 0) { //아이들을 만났을 때
			if (pq.empty()) { //선물이 없으면
				cout << "-1\n";
			}
			else { //선물이 있으면 가치 출력
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else { //거점지일때
			while (a--) {
				int input;
				cin >> input;
				pq.push(input);
			}
		}
	}

	return 0;
}