#include <iostream>
#include <cmath>

using namespace std;

void diet(const int& i, int& d, const int& a, const int& t, int& k2, int& w2) {
	while (d--) {
		w2 += i - (k2 + a);

		if (abs(i - (k2 + a)) > t) {
			k2 += floor((i - (k2 + a)) / 2.0);
		}
	}
}

int main() {
	int w0, i0, t, d, i, a;

	//입력
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	int k1, k2, w1, w2;
	k1 = i0; //변화하지 않는 일일 기초 대사량
	k2 = i0; //변화하는 일일 기초 대사량

	w1 = w0; //일일 기초대사량 변화 X
	w2 = w0; //일일 기초대사량 변화 O

	//연산
	w1 += (i - k1 - a) * d;
	diet(i, d, a, t, k2, w2);

	//출력
	//첫번째줄 출력 (변화 X), k1은 항상 0보다 큼
	(w1 <= 0) ? cout << "Danger Diet\n" : cout << w1 << " " << k1 << "\n";

	//두번째줄 출력 (변화 O)
	if (w2 <= 0 || k2 <= 0) {
		cout << "Danger Diet";
		return 0;
	}
	cout << w2 << " " << k2 << " ";
	if (k2 >= k1) { //요요 발생 안함
		cout << "NO";
	}
	else {
		cout << "YOYO";
	}

	return 0;
}