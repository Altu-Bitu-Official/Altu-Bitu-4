#include <iostream>
#include <queue>

using namespace std;
int top;
int back;
int cnt=0;

void printJosephus(queue<int>* que, int n, int k);

int main() {
	int n, k;
	//n, k입력받기
	cin >> n >> k;
	//큐에 넣기
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	//계산하기
	cout<<"<";//괄호 열기
	printJosephus(&que, n, k);
	cout<<">";//괄호 닫기

	return 0;
}

void printJosephus(queue<int>* que, int n, int k) {
	cnt++;
	// k-1번째는 팝만, 나머지는 뒤로 채워줌
	for (int i = 0; i < k - 1; i++) {
		que->push(que->front());
		que->pop();
		//디버그
		//top = que->front();
	}
	top = que->front();
	//맨앞에있는거 출력할거로 저장
	if (cnt == n) {//n번 다 돌면 빠져나가기
		cout << top; return;
	}
	else cout << top << ", ";
	//최상단 출력후 팝
	que->pop();
	//재귀
	printJosephus(que, n, k);
}
