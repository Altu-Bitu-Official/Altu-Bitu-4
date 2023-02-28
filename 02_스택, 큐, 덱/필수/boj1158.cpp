/*1~n 번까지 사람이 원형으로 앉아있음
양의 정수 k (k<=n)입력
순서대로 k번째 사람 제거(원형 큐?)
n명 모두 제거될 때까지 반복
사람이 제거되는 순서 = 요세푸스 순열*/

#include <iostream>
#include <queue>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	queue<int> q_c;
	queue<int> q_jo;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { //1~n까지 data추가가
		q_c.push(i);
	}

	while (q_c.size() > 0) { //queue가 비지 않으면 반복복
		for (int i = 1; i < k; i++) {
			int temp = q_c.front(); //맨 앞 data 저장
			q_c.pop();//맨 앞 data삭제
			q_c.push(temp);//맨 앞의 data가 new data이므로 기조의 삭제된 값 저장장
		}
		int old = q_c.front(); //맨 앞 data 저장
		q_c.pop();
		q_jo.push(old); //삭제된 k번째 data 새로운 queue에 저장장
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << q_jo.front() << ", ";
		q_jo.pop();
	}
	cout << q_jo.front() << "> \n";

}