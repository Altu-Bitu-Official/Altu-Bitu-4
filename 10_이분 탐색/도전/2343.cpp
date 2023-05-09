#include<iostream>
#include<vector>

using namespace std;

void playtime(int n, int m, vector<int>&lecture) {
	int right = 0;
	int left = 0;
	for (int i = 0; i < lecture.size(); i++) {
		right += lecture[i];
		left = max(lecture[i], left);
	}
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int num = 0;//블루레이에 담길 재생시간
		for (int i = 0; i < n; i++) {
			if (num + lecture[i] > mid) {
				num = 0;
				cnt++;
			}
			num += lecture[i];
		}
		if (num != 0) {
			cnt++;//최대 재생시간을 채우지 못한 마지막 블루레이가 빠지므로 따로 더해줌
		}

		if (cnt > m) {//재생시간을 더 길게
			left = mid + 1;
		}
		else {//재생시간을 더 짧게
			right = mid - 1;
		}
	}
	cout << left;
	
}
int main() {
	int n, m;
	cin >> n >> m;

	vector<int>lecture(n);
	int total = 0;

	for (int i = 0; i < n; i++) {
		cin >> lecture[i];//강의 길이를 벡터에 저장
		total += lecture[i];
	}
	
	playtime(n, m, lecture);
	
	return 0;
}