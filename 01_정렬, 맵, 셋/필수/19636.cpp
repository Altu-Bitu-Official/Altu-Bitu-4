#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int w, i, t;
	int d, w_d, i_d, a, i_d_b;
	string result;


	//입력
	cin >> w >> i >> t;
	cin >> d >> i_d >> a;

	w_d = w;
	i_d_b = i;

	//연산 (일일 기초 대사량의 변화를 고려하지 않았을 때)

	for (int j = 0; j < d; j++) {

		w += (i_d - (i + a));
	}
	// 출력 (일일 기초 대사량의 변화를 고려하지 않았을 때)
	if (w <= 0 || i <= 0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << w << " " << i << "\n";
	}

	//연산 (일일 기초 대사량의 변화를 고려하는 경우)

	for (int j = 0; j < d; j++) {

		w_d += (i_d - (i_d_b + a));

		if (abs(i_d - (i_d_b + a)) > t) {
			i_d_b += floor((i_d - (i_d_b + a)) / 2.0);
		}
	}

	//출력 (일일 기초 대사량의 변화를 고려하는 경우)
	if (w_d <= 0 || i_d_b <= 0) {
		cout << "Danger Diet";
	}
	else {
		if ((i - i_d_b) > 0) {
			result = "YOYO";
		}
		else {
			result = "NO";
		}
		cout << w_d << " " << i_d_b << " " << result;
	}

	return 0;


}