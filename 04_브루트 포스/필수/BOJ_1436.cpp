#include <iostream>
using namespace std;

//666이 들어가는지 판별
bool isApoNum(int i) {
	while (i != 0) {
		if (i % 1000 == 666) { //숫자 마지막에 666이 들어가면
			return true;
		}
		else { //숫자 마지막에 666이 안들어가면
			i /= 10; //일의 자리수를 없애고 한칸씩 당기기
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0, i = 666;

	//입력
	cin >> n;

	while (true) {
		if (isApoNum(i)) { //666이 들어가면
			cnt++; //카운트+1
			if (cnt == n) { //n번째 수이면 출력
				break;
			}
		}
		i++;
	}

	//출력
	cout << i;
	return 0;
}