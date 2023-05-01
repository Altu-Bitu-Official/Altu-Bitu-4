#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 집의 수 
	cin >> N;
	// 0열: R 1열: G 2열: B
	vector<vector <int>> cost(N, vector<int>(3,0)); // N개의 집 (행), RGB (3개 열)
	// 입력 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <N; i++) {
		// 이웃한 집끼리는 색 달라야 함
		cost[i][0]+= min(cost[i - 1][1], cost[i - 1][2]); // R -> G,B 중 최소 더함
		cost[i][1]+= min(cost[i - 1][0], cost[i - 1][2]); // G -> R,B 중 최소 더함
		cost[i][2]+= min(cost[i - 1][0], cost[i - 1][1]); // B -> R,G 중 최소 더함
	}
	// 열 별로 최솟값 저장 -> 이 중 최솟값 출력
	cout << min({ cost[N - 1][0], cost[N - 1][1], cost[N - 1][2] });
	return 0;
}