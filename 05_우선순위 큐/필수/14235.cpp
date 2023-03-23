#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int num;

	priority_queue<int> gift;
	while (n--) {
		cin >> num;
		if (!num) {
			if (gift.empty()) {
				cout << -1 << '\n';// 없으면 -1 출력
				continue; //선물이 없어도 바로 종료 되지 않도록
			}
			cout << gift.top() << '\n'; //아이들을 만나면 top의 선물(가장 큼) 출력
			gift.pop();//아이들에게 준 선물은 제거
		}

		else {
			while (num--) { //선물을 충전할때
				int a;
				cin >> a;
				gift.push(a); //큐에 저장
			}
		}
	}
	return 0;
}