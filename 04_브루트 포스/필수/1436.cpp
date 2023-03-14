#include <iostream>
using namespace std;

/* 
종말의 수: 어떤 수에 6이 적어도 3개 이상 연속으로 들어가는 수
*/
int main() {
	int n;
	int count = 0; //몇번째 종말의 수인지 count
	//입력
	cin >> n;

	//연산 
	for (int i = 666; ; i++) {
		int temp = i;
		while (temp != 0) {
			if (temp % 1000 == 666) {
				//종말의 숫자라면
				count++;
				break;
			}
			else {
				//종말의 숫자가 아니라면
				temp /= 10;
			}
		}
		//출력
		if (n == count) {
			cout << i;
			break;
		}
	}
}