#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> josephus(const int& n, const int& k) {
	queue<int> num;
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		num.push(i);
	}

	int index = 0;
	while (result.size() != n) { //result의 총 개수가 n이 될 때까지 반복
		int t = num.front(); //큐의 front 사람
		if (index < k - 1) { //해당 사람이 차례가 아닌 경우
			num.push(t); //다시 큐에 넣기
			num.pop(); //front에 있는 사람 삭제
			index++; //index 증가
		}
		else { //해당 사람이 차례인 경우
			index = 0; //index 초기화
			result.push_back(t); //결과 벡터에 넣기
			num.pop();
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//연산
	vector<int> result = josephus(n, k);

	//출력
	cout << "<";
	for (int i = 0; i < n - 1; i++) { //결과 벡터에 저장된 숫자 순서대로 하나씩 출력
		cout << result[i] << ", ";
	}
	cout << result[n - 1] << ">";

	return 0;
}