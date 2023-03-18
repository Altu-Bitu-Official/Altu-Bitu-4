#include <iostream>
#include <queue>
using namespace std;

//n번째 큰 수를 출력하는 함수
int nLarge(int n) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //모든 수에 대해 반복
			int input;
			cin >> input;
			if (pq.size() < n) { //pq에 n개 미만의 수가 들어있으면 push
				pq.push(input);
			}
			else { //pq에 n개 이상의 수가 들어있으면
				if (pq.top() < input) { //그 중 가장 작은 수와 비교해서 클 경우에만 push
					pq.pop(); //가장 작은 수는 제거
					pq.push(input);
				}
			}
		}
	}
	return pq.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	//입력
	cin >> n;
	//연산&출력
	cout << nLarge(n);
	return 0;
}