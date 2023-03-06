/*입력: 분자1, 분모1
		분자2, 분모2		*/

#include <iostream>
#include <algorithm>

using namespace std;

int gcdIter(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int getLCM(int a, int b) {
	int gcd = gcdIter(max(a, b), min(a, b));
	int lcm = (a * b) / gcd;
	return lcm;
}

void findIrr(int top, int bot) {
	if (gcdIter(max(top, bot), min(top, bot)) != 1) {
		int newtop = top / gcdIter(max(top, bot), min(top, bot));
		int newbot = bot / gcdIter(max(top, bot), min(top, bot));
		cout << newtop << " " << newbot << "\n";
	}
	else {
		cout << top << " " << bot << "\n";
	}
}

int main() {
	int t1, b1;
	int t2, b2;
	cin >> t1 >> b1;
	cin >> t2 >> b2;
	//b1, b2의 최소공배수 구하기
	int lcm = getLCM(b1, b2);
	//구한 최대공약수 배수로 분자 합 구하기
	int sum = 0;
	sum = (lcm / b1) * t1;
	sum += (lcm / b2) * t2;
	//기약분수 만들기
	findIrr(sum, lcm);
}