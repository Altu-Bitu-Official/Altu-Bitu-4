// N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted; // ���� �������� ����� �κ������� ���ĵ� �迭

// �պ� ����(�պ�)
void merge(vector<int>& arr, int left, int mid, int right) {
	int pl = left, pr = mid + 1, idx = left;
	while (pl <= mid && pr <= right) { // ���� �Ǵ� ������ �迭�� ������ ���ҿ� ������ ������
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

// �պ� ����(����): O(nlog2n)
void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) { // ���Ұ� �ϳ� ���� ������ ����
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