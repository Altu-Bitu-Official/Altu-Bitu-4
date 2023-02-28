#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int W0, L0, T ,D, L1, A ;
	int L2; // 변화한 기초 대사량
	int W1,W2; // 변화한 기초 대사량 고려한 체중
	string message;

	cin >> W0 >> L0 >> T;
	// 다이어트 전 체중, 일일 섭취량 (기초대사량), 기초대사량 역치
	cin >> D >> L1 >> A;
	// 다이어트 기간, 다이어트 기간동안 섭취량, 다이어트 기간동안 활동량

	//기초 대사량 고려 X
	W1 = W0 + (L1 - L0 - A) * D;
	if (W1 <= 0 || L0<=0 ) cout <<"Danger Diet" << "\n";
	else cout << W1  << " " << L0 << "\n";

	// 기초 대사량 고려 O
	W2 = W0 + (L1 - L0 - A);
	if (abs(L1 - L0 - A) > T) L2 = L0 + floor((L1 - L0 - A) / 2.0);
	else L2 = L0;
	
	for (int i = 0; i < D - 1; i++) {
		W2 = W2 + (L1 - L2 - A);
		if (abs(L1 - L2 - A) > T) L2 = L2 + floor((L1 - L2 - A) / 2.0);
	}
	if ((L0 - L2) > 0)
		message = "YOYO";
	else message = "NO";

	if (W2 <= 0 || L2 <= 0 ) cout << "Danger Diet";
	else cout << W2 << " " << L2<< " " << message;

	return 0;
}
