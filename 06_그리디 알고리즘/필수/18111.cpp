#include<iostream>
#include<vector>

using namespace std;

int block_time(int height, int n, int m, vector<int>&land) {//높이를 인자로 받고 땅고르는 시간을 리턴하는 함수
	int time = 0;
	for (int i = 0; i < n * m; i++) {
		if (land[i] > height) {
			time += (land[i] - height) * 2;//블록제거 횟수*2초 만큼의 시간 플러스
		}
		else if (land[i] < height) {
			time += (height - land[i]);//블록 쌓는 횟수 만큼의 시간 플러스
		}
		else
			continue;
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	int total_block = 0;
	vector<int>land(n*m);
	for (int i = 0; i < n * m; i++) {
		cin >> land[i]; //땅의 높이를 vector값 land에 
		total_block += land[i];
	}
	total_block += b;//만들 수 있는 최대 높이를 알기 위해 쓸 수 있는 블록수를 모두 더함
	int height = total_block / (n * m);// 최대높이에서 시작
	int time = 0;

	while (height >= 0) {//높이가 h일때 시간과 h-1일떄 드는 시간을 비교
		if (block_time(height, n, m, land) > block_time(height - 1, n, m, land)) {
			height--;
		}
		else {//더이상 h-1보다 시간이 적게 걸리지 않을 때=시간의 최소값
			time = block_time(height, n, m, land);
			break;
		}
	}

	cout << time << " " << height;
	return 0;
}