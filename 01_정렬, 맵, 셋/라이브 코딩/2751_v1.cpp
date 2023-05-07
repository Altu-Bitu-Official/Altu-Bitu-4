#include<iostream>
#include <vector>

using namespace std;

vector<int> sorted; // 정렬 과정에서 사용한 부분적으로 정렬된 배열

// 합병 정렬(합병)
void merge(vector<int>& arr, int left, int mid, int right) {
	int pl = left, pr = mid + 1, idx = left;
	while (pl <= mid && pr <= right) { // 왼쪽 또는 오른쪽 배열의 마지막 원소에 도달할 때까지
		if (arr[pl] < arr[pr]) { // 왼쪽 배열의 원소가 오른쪽 배열의 원소보다 작은 경우
			sorted[idx++] = arr[pl++]; // 왼쪽 배열의 원소를 sorted에 추가하고 인덱스 증가
		}
		else { // 오른쪽 배열의 원소가 왼쪽 배열의 원소보다 크거나 같은 경우
			sorted[idx++] = arr[pr++]; // 오른쪽 배열의 원소를 sorted에 추가하고 인덱스 증가
		}
	}
	while (pl <= mid) { // 왼쪽 배열에 원소가 남아 있는 경우
		sorted[idx++] = arr[pl++]; // sorted에 왼쪽 배열에 남아 있는 원소 추가
	}
	while (pr <= right) { // 오른쪽 배열에 원소가 남아 있는 경우
		sorted[idx++] = arr[pr++]; // sorted에 오른쪽 배열에 남아 있는 원소 추가
	}
	for (int i = left; i <= right; i++) { // sorted를 이용하여 원래 배열 업데이트
		arr[i] = sorted[i];
	}
}

// 합병 정렬(분할): O(nlog2n)
void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) { // 원소가 하나 남을 때까지 분할
		int mid = (left + right) / 2; // 절반 지점 계산
		mergeSort(arr, left, mid); // 왼쪽 배열
		mergeSort(arr, mid + 1, right); // 오른쪽 배열
		merge(arr, left, mid, right); // 왼쪽 배열과 오른쪽 배열 정렬하여 병합
	}
}

int main()
{
	int n;
	// 입력
	cin >> n;
	vector<int> arr(n);
	sorted.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 연산
	mergeSort(arr, 0, n - 1);
	// 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}