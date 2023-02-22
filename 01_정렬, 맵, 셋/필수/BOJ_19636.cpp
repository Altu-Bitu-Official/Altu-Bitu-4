#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int initial_weight, initial_intake, initial_bmr, threshold,
		duration, intake, amr,
		weight, weight_f, bmr;

	// 입력
	cin >> initial_weight >> initial_intake >> threshold;
	cin >> duration >> intake >> amr;
	weight = initial_weight;
	weight_f = initial_weight;
	initial_bmr = initial_intake;
	bmr = initial_bmr;

	// 연산
	while (duration) {
		weight_f += intake - (initial_bmr + amr);
		weight += intake - (bmr + amr);
		if (abs(intake - (bmr + amr)) > threshold) {
			bmr += floor((intake - (bmr + amr)) / 2.0);
		}
		duration--;
	}

	// 출력
	if (weight_f <= 0 || initial_bmr <= 0) {
		cout << "Danger Diet" << '\n';
	}
	
	else cout << weight_f << " " << initial_bmr << '\n';

	if (weight <= 0 || bmr <= 0) {
		cout << "Danger Diet" << '\n';
	}
	else {
		cout << weight << " " << bmr << " ";
		if (initial_intake - bmr) {
			cout << "YOYO" << '\n';
		}
		else cout << "NO" << '\n';
	}
	
	return 0;
}