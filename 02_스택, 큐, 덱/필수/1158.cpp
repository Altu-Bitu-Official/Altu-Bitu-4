 1914039-09
#include <iostream>
#include <queue>

using namespace std;

vector<int> josephus(int n, int k) { // 요세푸스 순열 반환
    vector<int> result; // 요세푸스 순열
    queue<int> q; // 원

    for(int i = 1; i <= n; i++) { // 원 초기화
        q.push(i);
    }

    while(!q.empty()) {
        for(int i = 0; i < k-1; i++) { // k-1번 pop & push
            q.push(q.front());
            q.pop();
        }

        // k번째 사람 pop 후 순열에 추가
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

/*
 * 원을 따라 k번째 사람을 제거한다.
 * 1. k번째 사람이 아닌 사람은 원의 맨 뒤로 보낸다.
 * 2. k번째 사람은 원에서 제거한다.
*/

int main() {
    int n, k;
    queue<int> q;

    // 입력
    cin >> n >> k;

    // 연산
    vector<int> result = josephus(n, k);

    // 출력
    cout << "<" << result[0];
    for(int i = 1; i < n; i++) {
        cout << ", " << result[i];
    }
    cout << ">";
    return 0;

#include<iostream>
#include<queue>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k; //입력 받음

	queue<int> arr; //자료구조 큐를 이용

	for (int i = 1; i <= n; i++) {
		arr.push(i);
	}//1~n까지의 원

	cout << '<';

	while (arr.size() > 1) {
		for (int i = 1; i < k; i++) {
			int tmp = arr.front();
			arr.pop();
			arr.push(tmp); //k번째가 될 때까지 숫자를 pop했다가 push하는 것을 반복함
		}
		cout << arr.front() << ", ";
		arr.pop(); //숫자를 출력하고 pop 함으로써 queue에서 삭제
	}

	cout << arr.front() << '>'; //마지막 숫자 뒤에는 ','이 붙지 않으므로 따로 출력
1914039-최유진
}