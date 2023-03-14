#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
void judgeHansu(vector<bool>& Hansu) {
	//1~99->한수. 따라서 스킵
	if (Hansu.size() > 100) {
		for (int i = 100; i < Hansu.size(); i++) {
			string number = to_string(i);
			vector<string> minuses(number.length() - 1,"0");//3자리수면 2개의 차가 나오니까
			for (int j = 0; j < number.length()-1; j++) {
				if (number[j]-'0' >(number[j + 1] - '0')) {
					minuses[j] = to_string((number[j]-'0') - (number[j + 1] - '0'));
				}
				else {//작은거에서 큰 거를 뺌 : 마이너스 붙이기
					minuses[j] = "-" + to_string((number[j + 1] - '0') - (number[j] - '0'));
				}
				
			}
			//비교
			string minus = minuses[0];
			for (int j = 1; j < minuses.size(); j++) {
				if (minus != minuses[j])
					Hansu[i] = false;
			}
		}
	}
}
int main() {
	int n;
	int answer_count=0;
	cin >> n;
	vector<bool> Hansu(n+1, true);
	judgeHansu(Hansu);
	//답안다른문제
	for (int i = 1; i <Hansu.size(); i++) {
		if (Hansu[i] == true)
			answer_count++;
	}
	cout << answer_count;

	return 0;
}