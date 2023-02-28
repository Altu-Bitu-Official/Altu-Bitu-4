#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void josephus(vector<int>& num, queue<int>& result, const int& n, const int& k) {
	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
	}

	int index = -1;
	while (result.size() != n) { //result의 총 개수가 n이 될 때까지 반복
		int t = 1; //t: 다음 k번째에 숫자가 있는 곳까지 이동해야 할 거리
		int check = 0; //check: k번째까지 갔는지 확인하기 위한 변수
		while (check < k) {
			if (num[(index + t) % n] != 0) { //없어진 숫자가 아니라면 check 1 증가
				check++;
			}
			t++; //이동 거리 증가
		}
		index = (index + t - 1) % n; //다음에 없애야 하는 숫자의 index
		result.push(num[index]); //해당 숫자 result 큐에 넣기
		num[index] = 0; //벡터에서 해당 숫자를 0으로 바꿔줌으로써 숫자 삭제
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//연산
	vector<int> num(n); //1부터 n까지의 숫자가 있는 벡터 생성
	queue<int> result; //최종 결과를 저장할 큐 생성
	josephus(num, result, n, k);
	
	//출력
	cout << "<";
	for (int i = 0; i < n - 1; i++) { //큐에 저장된 숫자 순서대로 하나씩 출력
		cout << result.front() << ", ";
		result.pop();
	}
	cout << result.front() << ">";
	
	return 0;
}