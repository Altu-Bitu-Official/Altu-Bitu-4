// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted; // 정렬 과정에서 사용한 부분적으로 정렬된 배열

// 합병 정렬(합병)
void merge(vector<int>& arr, int left, int mid, int right) {
	int pl = left, pr = mid + 1, idx = left;
	while (pl <= mid && pr <= right) { // 왼쪽 또는 오른쪽 배열의 마지막 원소에 도달할 때까지
		if (arr[pl] < arr[pr]) {
			sorted[idx++] = arr[pl++];
		}
		else {
			sorted[idx++] = arr[pr++]
		}
	}
	while (pl <= mid) {
		sorted[idx++] = arr[pl++];
	}
	while(pr <= right) {
		sorted[idx++] = arr[pr++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = sorted[i];
	}
}

// 합병 정렬(분할): O(nlog2n)
void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) { // 원소가 하나 남을 때까지 분할
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	sorted.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr,0,n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}