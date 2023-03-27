#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, B;
	cin >> N >> M >> B;

	int v[500][500];
	

	//땅높이 배열 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			v[i][j] = input;
		}
		
	}


	int answer_time = 10000000000;//가장 빠른 시간을 기록할 변수
	int answer_height=0;//그때의 높이를 기록할 변수

	for (int h = 0; h <= 256; h++) {//0부터 맞춰가기. h은 기준이 되는 높이
		int plus=0;//블럭을 새로 쌓는 횟수
		int minus=0;//블럭을 제거하여 인벤토리에 담는 횟수
		int time = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] > h) {//만약 기준값보다 크면
					minus += v[i][j] - h;
				}
				else if(v[i][j]<h) {//만약 기준값보다 작으면
					plus += h - v[i][j];
				}
			}
		}

		
		if(B + minus - plus >= 0) {
			time = 2 * minus + plus;
			
			
				if (answer_time >= time) {//만약 더 빠른 시간이 생겨난다면
					answer_time = time;
					answer_height = h;
				}
			
		}
		

	}
	cout << answer_time << ' ' << answer_height;
}