#include <iostream>
#include <queue>
using namespace std;
int main() {
	//오름차순으로 하면 temp벡터 채우고 비우고 연산을 안 해도 되게 된다-> 시간복잡도 문제 해결
	priority_queue<int, vector<int>, greater<int>> pq;//오름차순
	//시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int input;
		cin >> input;
		if (i < n) {
			pq.push(input);
		}
		else {
			//이 때부터는 상위 n개 안에 못 들어가면 안 넣어도 됨
			if (pq.top() < input) {
				pq.push(input);
				pq.pop();//하나 채웠으니까 n개로 다시 맞춰준다
				//즉, 꼭대기는 n번째 수임-> 하나 들어오면 n+1번째 수 됨-> 팝하기
			}
		}
	}
	//탑 출력: 상위 n번째
	cout << pq.top();
	return 0;
}