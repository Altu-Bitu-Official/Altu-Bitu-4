#include<iostream>
#include<queue>

using namespace std;

/*
* HINT : 아이들에게 주는 선물의 특징을 고려해 자료구조를 선택해봐요!
*/

/*
* 아이들에게 주는 선물 : 가치가 가장 큰 선물 -> 선물을 우선순위큐에 저장
* 1. 아이들을 만난 경ㅇ
*      1) 큐가 비어있으면 -1 출력
*      2) 큐의 top값 출력
* 2. 선물 충전 -> 큐에 삽입
*/
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n,input, gift;
	priority_queue<int> pq;

   //입력
	cin >> n;

    //연산 + 출력
	while (n--) {

        cin >> input;
        if (!input) { //아이들을 만난 경우
            if (pq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else { //선물을 충전하는 경우
            while (input--) {
                cin >> gift;
                pq.push(gift);
            }
        }
	}
    return 0;
}