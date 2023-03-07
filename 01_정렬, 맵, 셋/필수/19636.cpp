#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//1. 입력
	//첫째줄
	int weight_bef_diet, daily_engy_intake_and_BMR_bef_diet, BMR_change_minimun;
	cin >> weight_bef_diet >> daily_engy_intake_and_BMR_bef_diet >> BMR_change_minimun;
	//둘째줄
	int diet_day, daily_engy_intake_dur_diet, daily_act_met_dur_diet;
	cin >> diet_day >> daily_engy_intake_dur_diet >> daily_act_met_dur_diet;

	//2. 연산
	int pred_weight_aft_diet = weight_bef_diet;
	int daily_engy_cons;
	int daily_BMR = daily_engy_intake_and_BMR_bef_diet;
	bool is_danger = false;
	string yoyo;
	//첫째줄
	for (int i = 0; i < diet_day; i++) {
		daily_engy_cons = daily_engy_intake_and_BMR_bef_diet + daily_act_met_dur_diet;
		pred_weight_aft_diet += daily_engy_intake_dur_diet - daily_engy_cons;
		if (pred_weight_aft_diet <= 0 || daily_engy_intake_and_BMR_bef_diet <= 0) {
			is_danger = true;
			break;
		}
	}
	//3. 출력
	if (is_danger) {
		cout << "Danger Diet" << endl;
	}
	else	cout << pred_weight_aft_diet << " " << daily_engy_intake_and_BMR_bef_diet << endl;
	//2. 연산
	//둘째줄 
	pred_weight_aft_diet = weight_bef_diet;//초기화
	is_danger = false;//초기화
	for (int i = 0; i < diet_day; i++) {
		daily_engy_cons = daily_BMR + daily_act_met_dur_diet;
		pred_weight_aft_diet += daily_engy_intake_dur_diet - daily_engy_cons;
		if (abs(daily_engy_intake_dur_diet - daily_engy_cons) > BMR_change_minimun) {
			daily_BMR += (daily_engy_intake_dur_diet - daily_engy_cons) / 2.0;//floor작용
		}
		if (pred_weight_aft_diet <= 0 || daily_BMR <= 0) {
			is_danger = true;
			break;
		}
	}
	if (0 < daily_engy_intake_and_BMR_bef_diet - (daily_BMR + 0)) {
		yoyo = "YOYO";
	}
	else yoyo = "NO";
	//3. 출력
	if (is_danger) {
		cout << "Danger Diet" << endl;
	}
	else	cout << pred_weight_aft_diet << " " << daily_BMR << " " << yoyo << endl;


	return 0;
}