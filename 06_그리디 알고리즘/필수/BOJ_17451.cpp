#include <iostream>
#include <vector>
using namespace std;

// 평행우주 
// p는 10^9까지 입력받음 -> int 범위 벗어날 수 있음
// 나머지 연산 -> 정수형만 가능하므로 long long으로
// 뒤에서부터 진행 (0->n: 속도 계속 감소, n->0: 속도 계속 증가) 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// v: 지구에서 출발한 최소 속도, p: 행성 별 최소 속도 
	int n;
	unsigned long long p;
	unsigned long long v = 1;

	vector <int> planet;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		planet.push_back(p);
	}
	// v는 계속 증가해야 함
	for (int i = n - 1; i >=0; i--) {
		if (v <= planet[i]) v = planet[i]; 
		else { // 현재 속도가 행성 최소 속도보다 큰 경우 

			if ((v % planet[i]) != 0) { // v가 p의 배수가 아니라면 (v: 500, p:400)
				v = ((v / planet[i]) + 1) * planet[i]; 
			}
			else continue; // v가 p의 배수라면 v는 그대로 (v: 800, p:400)
		}
	}
	cout << v;
	return 0;
}