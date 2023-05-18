#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int w0, i0, t;
	int d, i, a;
	
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a; //입력

	int m = i0;
	int m2 = i0;

	int w1 = w0; //기초대사량 변화 고려x 
	int w2 = w0; //기초대사량 변화 고려 o
	

	for (int j = 0; j < d; j++) {
		w1 += i - (m + a);
		w2 += i - (m2 + a);

		if (abs(i - (m2 + a)) > t)
			m2 += floor((i - (m2 + a)) / 2.0); 
		//절대값이 t보다 크다면 기초대사량 m2 변화
	}

	if (w1 <= 0)
		cout << "Danger Diet\n";
	else
		cout << w1 <<" "<< m << '\n'; //첫번째줄 출력

	if (w2 <= 0 || m2 <= 0)
		cout << "Danger Diet";
	else {
		cout << w2 << " " << m2 << " ";
		if (m > m2)
			cout << "YOYO";
		else
			cout << "NO";
	}
}