#include<iostream>
#include <vector>

using namespace std;

// 선택 정렬: O(n^2)
void selectionSort(vector<int>& arr) {
	int least;
	for (int i = 0; i < arr.size() - 1; i++) {
		least = i; // 가장 작은 원소의 인덱스
		// 1 ~ n까지 정렬 -> 2 ~ n까지 정렬 -> ... -> n-1 ~ n까지 정렬
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[least]) { // 더 작은 원소가 있는 경우
				least = j; // 가장 작은 원소의 인덱스 업데이트
			}
		}
		swap(arr[i], arr[least]); // 두 원소의 위치 바꾸기(작은 원소가 왼쪽으로 이동)
	}
}

// 삽입 정렬: O(n^2)
void insertionSort(vector<int>& arr) {
	int curr, j;
	for (int i = 1; i < arr.size(); i++) {
		curr = arr[i]; // 위치를 찾으려는 원소
		// 삽입하려는 원소보다 큰 원소는 한 칸씩 뒤로 이동
		for (j = i - 1; j >= 0 && arr[j] > curr; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = curr; // 빈 자리에 원소 삽입
	}
}

// 버블 정렬: O(n^2)
void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		// 0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { // 왼쪽 원소가 큰 경우
				// int tmp = arr[j - 1];
				// arr[j - 1] = arr[j];
				// arr[j] = tmp;
				swap(arr[j], arr[j + 1]); // 두 원소의 위치 바꾸기
			}
		}
	}
}

// 향상된 버블 정렬: O(n^2)
void advBubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		bool is_swap = false; // swap 여부를 표시
		// 0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { // 왼쪽 원소가 큰 경우
				swap(arr[j], arr[j + 1]); // 두 원소의 위치 바꾸기
				is_swap = true;
			}
		}
		if (!is_swap) { // swap이 한 번도 일어나지 않는다면
			return; // 이미 모든 원소가 정렬되어 있으므로 바로 리턴
		}
	}
}

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 연산
	// selectionSort(arr);
	// insertionSort(arr);
	// bubbleSort(arr);
	advBubbleSort(arr);
	// 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}