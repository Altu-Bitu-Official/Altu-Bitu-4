#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int w0, w1, i0, i1, t, d, i, a, l0, l1;

	//입력
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	//연산
	w1 = w0;
	i1 = i0;
	for (int j = 0; j < d; j++) {
		//대사량 변화 X
		l0 = i - (i0 + a);
		w0 += l0;
		//대사량 변화 고려
		l1 = i - (i1 + a);
		w1 += l1;
		if (abs(l1) > t) {
			i1 += floor(l1 / 2.0);
		}
	}

	//출력
	if (w0 <= 0 || i0 <= 0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << w0 << ' ' << i0 << "\n";
	}

	if (w1 <= 0 || i1 <= 0) {
		cout << "Danger Diet";
	}
	else {
		cout << w1 << ' ' << i1 << ' ';
		if (i0 - i1 > 0) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}

	return 0;
}