#include<iostream>
#include<math.h>

using namespace std;

int stats[20][20];
bool check[21];
int N;
int ans = 40000; // 100*20*20=40000

void start_link(int cnt, int num){
	if (cnt == N / 2){ //각 팀당 n/2명으로 나눔
		int start= 0;
		int link = 0;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (check[i] == true && check[j] == true) {
					start += stats[i][j];
				}
				if (check[i] == false && check[j] == false) {
					link += stats[i][j];
				}
			}
		}

		int temp = abs(start - link);
		if (ans > temp) {
			ans = temp; //더 작은 차를 구하면 갱신
		}
		return;
	}

	for (int i = num; i < N; i++){
		check[i] = true;//스타크 팀에 속하는 경우
		start_link(cnt + 1, i + 1);
		check[i] = false;//링크 팀에 속하는 경우
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> stats[i][j];
		}
	}

	start_link(0, 1);

	cout << ans;

	return 0;
}