#include <iostream>
#include <vector>

using namespace std;

//후위 순회한 결과를 출력하는 함수
void postOrder(int start, int end, vector<int>& v) {
	if (start >= end) {
		return;
	}

	int index; //v[start]보다 큰 값을 가진 첫 위치
	for (index = start + 1; index < end; index++) {
		if (v[index] > v[start]) {
			break;
		}
	}

	postOrder(start + 1, index, v); //left 서브 트리 탐색
	postOrder(index, end, v); //right 서브 트리 탐색
	cout << v[start] << "\n"; //root 출력
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int num;
	vector<int> v;
	while (cin >> num) {
		v.push_back(num);
	}
	
	//연산 & 출력
	postOrder(0, v.size(), v);

	return 0;
}