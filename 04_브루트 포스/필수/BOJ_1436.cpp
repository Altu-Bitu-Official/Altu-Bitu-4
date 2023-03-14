#include <iostream>
#include <string>
using namespace std;

// 0666, 1666, 2666, ... , 6660, 6661, 6662, 6663...
// 666부터 시작하여 연속된 3개의 6이 포함된 경우 cnt ++
// cnt가 n이 되는 경우 n번째로 작은 영화제목 출력

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N; 
	
	int cnt = 0;
	for (int i = 666; ; i++) {
		string a = to_string(i);
		if (a.find("666") !=-1) 	cnt++; // 3개의 연속된 6 발견 시, cnt 증가
	
		if (cnt == N) { 
			cout << i; // n번째 수 출력
			break;
		}
	}
	
	return 0;
}