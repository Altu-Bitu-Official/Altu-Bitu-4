#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int input_num;
	cin >> input_num;
	int count = 0;
	int number = 665;
	int tmp;
	while (count != input_num) {
		number++;
		tmp = number; //while문 안에서 tmp 선언하면 tmp선언이 while문만큼 반복되므로 시간초과
		while (tmp > 100) {
			if (tmp % 1000 == 666) {
				count++;
				break;
			}
			else {
				tmp /= 10;
			}
		}
	}
	cout << number << "\n";

}