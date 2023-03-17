#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int w, i, t; //다이어트 전 체중, 일일 에너지 섭취량 및 일일 기초 대사량, 기초 대사랑 변화 역치
	int d, w_d, i_d, a, i_d_b; //다이어트 기간, 다이어트 중 체중, 일일 에너지 섭취량, 일일 활동 대사량, 일일 기초 대사량 


	//입력
	cin >> w >> i >> t;
	cin >> d >> i_d >> a;

	w_d = w;
	i_d_b = i;

	//연산 (일일 기초 대사량의 변화를 고려하지 않았을 때)

	/*/for (int j = 0; j < d; j++) {

		w += (i_d - (i + a));
	}*/

	w += d * (i_d - (i + a));
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
		cout << w_d << " " << i_d_b << " ";
		if ((i - i_d_b) > 0) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}

	return 0;


}