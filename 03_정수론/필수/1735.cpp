#include <iostream>
#include <string>
using namespace std;

int gcdIter(int a, int b);

int main() {
	//분모: 최소공배수
	//분자: (최소공배수/분모)*분자

	int A_top;
	int A_bottom;
	int B_top;
	int B_bottom;
	int bottom_gcd;
	int bottom_lcm;
	int result_top;
	int result_bottom;
	//입력받기
	cin >> A_top >> A_bottom;
	cin >> B_top >> B_bottom;

	//분모의 최소공배수 계산(최소공배수: 최대공약수*(A/최대공약수)*(B/최대공약수)
	bottom_gcd = gcdIter(A_bottom, B_bottom);
	bottom_lcm = bottom_gcd * (A_bottom / bottom_gcd) * (B_bottom / bottom_gcd);
	//분자저장
	result_top = (bottom_lcm / A_bottom) * A_top + (bottom_lcm / B_bottom) * B_top;
	//분모저장
	result_bottom = bottom_lcm;

	//기약분수로 나타내자
	
	int gcd;
	gcd = gcdIter(result_bottom, result_top);
				
	result_top = result_top/gcd;
	result_bottom = result_bottom / gcd;
	

	//출력
	//질문: 1 20 1 5 넣었을 때 디버그 하니 result_top안에 1이 들어있는데, 출력이 왜 안되는지 모르겠어요ㅠ_ㅠ
	cout << to_string(result_top) + " ";
	cout << result_bottom;

	return 0;
}

int gcdIter(int a, int b) {
	while (b) {//b==0, a가 최대공약수
		a %= b;
		swap(a, b);
	}
	return a;
}