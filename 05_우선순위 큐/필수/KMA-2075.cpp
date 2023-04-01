#include<iostream>
#include<queue>

using namespace std;

/*
* HINT : 상위 n개의 숫자에서 n번째 숫자는 가장 작은 숫자네요!
*/

/*
* 입력되는 수 중 n번째로 큰 수를 찾자!
* -> 최종으로 상위 n개를 저장할 수 있는 구조 -> n개 이상일 때 가장 작은 값을 삭제할 수 있는 구조
* -> 최소힙을 이용하자
* -> 입력을 최소힙에 push하고 힙의 사이즈가 n보다 크다면 top값을 제거해주자
* -> 최종적으로 상위 n개의 숫자가 저장되고 top값이 n번째 큰수가 된다!
*/

int main() {

	ios_base::sync_with_stdio(false);	//입출력 속도 향상
	cin.tie(0);
	cout.tie(0);

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq;//최소힙 - 최소인 숫자가 맨 위에 정렬됨

	//입력
	cin >> n;	//n을 입력받는다
	
	//연산
	for (int i = 0; i < n*n; i++) {	//n square번 만큼
		cin >> num;
		pq.push(num);	//숫자를 num에 입력받아서 pq에 넣는다
		if (pq.size() > n) {//저장된 숫자의 개수가 n보다 많으면 
			pq.pop();	//가장 작은 값(top값)을 제거해서 pq에는 상위 n개의 숫자만 있도록 한다
		}
	}

	//출력
	cout << pq.top();	//최소힙 pq의 맨 위의 수 = 전체 숫자 중 n번째로 큰 수
	return 0;
}