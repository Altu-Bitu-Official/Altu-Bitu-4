/*
입력은 총 2N+1개의 줄로 이루어져 있다. 첫 줄에는 차의 대수 N(1 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 대근이가 적은 차량 번호 목록이 주어지고, N+2째 줄부터 N개의 줄에는 영식이가 적은 차량 번호 목록이 주어진다. 
각 차량 번호는 6글자 이상 8글자 이하의 문자열로, 영어 대문자('A'-'Z')와 숫자('0'-'9')로만 이루어져 있다.
같은 차량 번호가 두 번 이상 주어지는 경우는 없다.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// A보다 터널에서 늦게 나온 차 중에서 A보다 인덱스가 작은 차가 하나라도 있다면 먼저 들어왔는데 나올 땐 A보다 뒤에 있다는 것이므로 추월을 의미

// 터널 안에서 추월한 차의 대수를 구하는 함수
int overtake(int n, vector<int>& order_out) {
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

int main() {
	int n;
	string car;
	map<string, int> order_in; 
	vector<int> order_out; 
	cin >> n;
	for (int i = 1; i <= n; i++) { // 들어가는 순서
		cin >> car;
		order_in[car] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> car;
		order_out.push_back(order_in[car]);
	}
	cout << overtake(n, order_out) << '\n';
}