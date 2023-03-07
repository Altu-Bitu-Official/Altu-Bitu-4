#include <iostream>
#include <queue>

using namespace std;

vector<int> josephus( int n, int k);

int main() {
	int n, k;
	vector<int> answer;
	//n, k입력받기
	cin >> n >> k;
	
	//계산하기
	answer=josephus(n, k);
	
	//출력하기
	for (int i = 0; i < n; i++) {
		if (i == 0) cout << "<";
		if (i == n-1) {
			cout << answer[i] << ">";
		}else 	cout << answer[i] << ", ";
	}
	
	return 0;
}

vector<int> josephus(int n, int k) {
	int top;
	queue<int> que;
	vector<int> answer(n);
	//큐 초기화
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	//답 구하기
	for (int j = 0; j < n; j++) {
		// k번째는 팝만, k-1까지는 뒤로 채워줌
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		//k번째 저장
		top = que.front();
		//answer 배열에 저장
		answer[j] = top;
		//최상단 저장 후 k번째 요소 팝
		que.pop();
	}
	return answer;
}