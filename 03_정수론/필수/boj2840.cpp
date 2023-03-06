#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//바퀴의 칸 수, 바퀴 돌리는 횟수
	int n, k;
	int status = 0;
	cin >> n >> k;
	int no = 0;
	vector<char> w(n, '?');
	//화살표가 가리키는 글자가 몇번 바뀌었는지, 회전을 멈추었을때 가리키던 글자
	for (int i = 0; i < k; i++) {
		int s;
		char al;
		cin >> s >> al;
		s %= n;
		if (no - s < 0) {
			no = no - s + n;
		}
		else {
			no -= s;
		}
		if ((w[no] != '?') && (w[no] != al)) {
			status = 1;
			break;
		}
		w[no] = al;

	}
	/*출력
	  마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로 위치한 알파벳 출력
	  모르는 칸은 ? 출력
	  */
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((w[i] != '?') && (w[i] == w[j])) {
				status = 1;
				break;
			}
		}
	}
	if (status == 0) {
		for (int i = 0; i < n; i++) {
			cout << w[(i + no) % n];
		}
	}
	else {
		cout << "!" << "\n";
	}

}