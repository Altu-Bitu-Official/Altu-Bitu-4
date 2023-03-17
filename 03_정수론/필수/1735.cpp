#include <iostream>
#include <vector>

using namespace std;

int gcdIter(int a, int b) {//최대 공약수 구하는 함수
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

vector<int> addFountain(vector<int>& n1, vector<int>& n2) {
	vector<int> result; //두 분수를 더한 값
	int gcd;
	result.assign(2, 0);
	//분모의 최소 공배수 구하기
	gcd = gcdIter(max(n1[1], n2[1]), min(n1[1], n2[1]));
	result[1] = n1[1] * n2[1] / gcd; //공통 분모 구하기

	//두 분수를 더한 분수의 분자 구하기
	n1[0] *= result[1] / n1[1];
	n2[0] *= result[1] / n2[1];
	result[0] = n1[0] + n2[0];

	//기약 분수인지 확인 
	int i = gcdIter(max(result[0], result[1]), min(result[0], result[1]));
	if (i != 1) { //기약 분수가 아니면
		result[0] /= i;
		result[1] /= i;
	}

	return result;
}

int main()
{
	vector<int> n1; // 첫번째 분수
	vector<int> n2; // 두번째 분수
	vector<int> result; //두 분수를 더한 분수
	n1.assign(2, 0);
	n2.assign(2, 0);

	//입력
	cin >> n1[0] >> n1[1];
	cin >> n2[0] >> n2[1];

	//연산
	result = addFountain(n1, n2);
	
	//출력
	cout << result[0] << " " << result[1];

	return 0;

}
