#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K, S;
	int sum = 0;
	char C;
	cin >> N >> K; // 바퀴 칸수, 바퀴 돌리는 횟수
	vector <char> wheel(N, '?'); // 바퀴 모든 칸 ?로 초기화

	for (int i = 0; i < K; i++) {
		cin >> S >> C; // 화살표가 가리키는 글자 변경 횟수, 회전 멈췄을 때 가리키는 글자

		// 회전 멈춘 글자에서부터 S칸 이동하면 나오는 글자 C
		sum = (sum + S) % N;

		// 이미 해당 칸에 다른 알파벳이 있거나
		// 하나의 칸에 2개 이상의 알파벳이 들어가는 경우
		if (wheel[sum] != '?' && wheel [sum]!=C) {
			cout << "!" << "\n"; // ! 출력
			return 0;
		}	
		wheel[sum] = C; 
	}
	// 반례 (4칸 wheel 안에 AAAA 들어간 경우)
	// 바퀴 안의 칸들 중 중복되는 알파벳이 있는 경우
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (wheel[i] == wheel[j] && wheel[i]!='?') {
				cout << "!" << "\n"; // ! 출력
				return 0;
			}
		}
	}
	// 마지막으로 멈춘 곳에서부터 시계방향으로 출력
	for (int i = sum; i >=0 ; i--) {
		cout << wheel[i];
	}
	for (int i = N - 1; i > sum; i--) {
		cout << wheel[i];
	}
	return 0;
}
