#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> tile;
	tile.push_back(1); //2*1 타일 채우는 방법=1가지
	tile.push_back(2);//2*2 차일 채우는 방법=2가지

	for (int i = 2; i < n; i++) {
		//n개의 타일을 채우는 방법은 n-1개의 타일 채우는 방법+n-2타일 채우는 방법
		tile.push_back((tile[i - 1] + tile[i - 2]) % 10007); 
	}
	cout << tile[n - 1];//한개씩 밀려서 저장됐으므로 n-1번째를 출력

	return 0;
}