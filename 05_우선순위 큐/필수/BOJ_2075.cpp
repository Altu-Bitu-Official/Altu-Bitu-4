#include <iostream>
#include <vector>

using namespace std;

//첫 n개의 값을 heap에 push하는 함수
void init(vector<int>& heap, int x, int n, int i) {
	//주어진 인덱스에 입력받은 x 넣기
	heap[i] = x;

	//다음 노드가 이전 노드보다 크면 swap (내림차순 정렬)
	int idx = i;
	while (idx > 0 && heap[idx] > heap[idx - 1]) {
		swap(heap[idx], heap[idx - 1]);
		idx--;
	}
}

//나머지 값을 heap에 push하는 함수
void push(vector<int>& heap, int x, int n) {
	//힙의 마지막에 입력받은 x 넣기
	heap[n] = x;

	//다음 노드가 이전 노드보다 크면 swap (내림차순 정렬)
	int idx = n;
	while (idx > 0 && heap[idx] > heap[idx - 1]) {
		swap(heap[idx], heap[idx - 1]);
		idx--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x;
	cin >> n;

	//heap 초기화
	vector<int> heap(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> x; //n개의 값 넣어주기
		init(heap, x, n, i);
	}

	int cnt = n * n - n; //입력받을 숫자의 개수
	while (cnt--) {
		cin >> x;
		//연산
		push(heap, x, n);
	}

	//출력
	cout << heap[n - 1];

	return 0;
}