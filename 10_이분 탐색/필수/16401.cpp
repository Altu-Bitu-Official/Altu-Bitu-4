#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(long long left, long long right, int  m, vector<int>&snack) {

	while (left <= right) {
		long long  mid = (left + right) / 2; //mid=과자길이
		int cnt = 0;

		for (int i = 0; i < snack.size(); i++) {
			if (snack[i] >= mid) {
				cnt += (snack[i] / mid); //과자가 길다면 2조각 이상을 낼 수 있으므로 -mid가 아니라 /mid
			}
		}

		if (cnt >= m){//과자를 더 길게 줄 수 있음
			left = mid + 1;
		}
		else {//과자를 더 짧게 주어야한다는 뜻
			right = mid - 1;
		}
	}
	return left - 1;//upper bound
}

void snackShare(int m, vector<int>& snack) {
	long long total = 0;
	for (int i = 0; i < snack.size(); i++) {
		total += snack[i];
	}

	long long right = total / m;//조카들이 가질 수 있는 최대한의 과자 길이
	long long left = 1; // 아이들이 가질 수 있는 최소한의 과자 길이

	if (total < m) {//과자 길이=1로도 나눠주지 못하는 상황
		cout << 0;
	}
	else {
		 cout << binarySearch(left, right, m, snack);
	}
}

int main() {
	int m, n;//m:조카수, n:과자개수
	cin >> m >> n;
	vector<int>snack(n);
	for (int i = 0; i < n; i++) {
		cin >> snack[i];
	}

	snackShare(m, snack);
	
	return 0;
}