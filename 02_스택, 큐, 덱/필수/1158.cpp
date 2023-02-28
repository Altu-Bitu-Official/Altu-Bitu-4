#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void removeNum(int n, int k, vector<int>& arr, queue<int>& q) {

	int tip = 0; // 가리키는 위치

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {

			if (tip >= n) { //가리키는 위치가 arr 길이를 넘어버리면 다시 첫번째 자리로 이동
				tip = 0;
			}

			tip++; // 위치 이동

			while (arr[tip] == -1) { //이미 지운 숫자는 넘어감
				if (tip >= n) { //가리키는 위치가 arr 길이를 넘어버리면 다시 첫번째 자리로 이동
					tip = 0;
				}
				tip++; // 위치 이동
			}
		}
		q.push(arr[tip]); // 해당하는 위치의 숫자를 q에 넣음
		arr[tip] = -1; //큐에 넣은 숫자는 지움
	}
}

int main()
{
	int n, k; // n개의 숫자와 제거할 k번째 숫자
	vector<int> arr; // n번째까지의 원
	queue<int> q; // 출력에 쓰일 큐

	//입력
	cin >> n >> k;

	// 1~n까지의 원 구성
	arr.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	//연산

	removeNum(n, k, arr, q);

	//출력
	cout << "<";
	for (int i = 1; i < n; i++) {
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front() << ">";
	q.pop();

	return 0;
}