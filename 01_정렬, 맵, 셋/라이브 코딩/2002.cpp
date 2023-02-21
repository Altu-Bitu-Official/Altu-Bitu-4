#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 터널 안에서 추월한 차의 대수를 구하는 함수
int overtake(int n, vector<int> &order_out) {
	int ans = 0; // 추월한 차의 대수
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { // 현재 차보다 더 늦게 나온 차들을 확인
			if (order_out[i] > order_out[j]) { // 더 늦게 들어간 차가 더 먼저 나오는 경우 -> 추월
				ans++; 
				break;
			}
		}
	}
	return ans;
}

int main()
{
	int n;
	string car;
	map<string, int> order_in;
	vector<int> order_out;
	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) { // 들어가는 순서
		cin >> car;
		order_in[car] = i;
	}
	for (int i = 0; i < n; i++){ // 나가는 순서
		cin >> car;
		order_out.push_back(order_in[car]); 
	}
	// 연산 & 출력
	cout << overtake(n, order_out) << '\n';
	return 0;
}