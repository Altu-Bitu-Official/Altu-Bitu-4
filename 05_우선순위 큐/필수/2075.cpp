#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	priority_queue<int> pq; //큰 숫자에 우선순위.
	int n;//n번째
	cin >> n;
	vector<int> temp(n);//팝 담아두는 공간
	//숫자넣기
	//상위 n번째 수만 출력함-> 상위 N번째 미만이면 없어도됨
	int n_th_num = -1000000001;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < n; k++) {
			int input;
			cin >> input;
			if (pq.size() >= n && input > n_th_num) {
				for (int j = 1; j <= n; j++) {//n번째만 골라내서 그거보다 작은 인풋이면 넣지말기
					if (n == j) {
						n_th_num = pq.top();//n번째 수 겟
					}
					temp.push_back(pq.top());
					pq.pop();
				}
				//pq 복구
				if (!temp.empty()) {
					for (int j = temp.size() - 1; j >= 0; j--) {
						pq.push(temp[j]);
						temp.pop_back();
					}
				}
			}
			//벡터 비우기
			temp.clear();

			if (n_th_num < input) {//들어온 수가 n번째 수보다 작으면 넣을 필요가 없다. 
				//따라서 n번째 수보다 클 때에만 넣는다.
				pq.push(input);
			}
		}
	}

	//답안출력
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			cout << pq.top();//n번째 수 출력 후 탈출
			break;
		}
		pq.pop();
	}

	return 0;
}