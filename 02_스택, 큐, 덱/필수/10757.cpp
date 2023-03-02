#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	string A, B; //정수형이 받을 수 있는 범위를 초과하므로 문자열로 입력 받음

	cin >> A >> B; //입력받음

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end()); // 계산을 위해 문자열을 뒤집음(일의자리부터 계산함으로)

	vector <int> result; // 결과값을 저장할 공간

	if (A.size() < B.size()) {
		swap(A, B); // 편의상 A가 항상 더 크도록 함
	}

	if (A.size() != B.size()) {
		for (int i = B.size(); i < A.size(); i++) {
			B[i] = '0'; // 두 수 사이에 자릿수가 차이가 난다면 차이나는 만큼 끝에 '0'을 붙여줌
		}
	}

	int sum = 0; int plus = 0;
	for (int i = 0; i < A.size(); i++) {
		int a = A[i] - '0'; //아스키 코드 값으로 저장되어 있으므로 '0'을 빼줌
		int b = B[i] - '0';
		sum = a + b + plus; //a와 b와 직전 계산에서 올라온 자릿수를 더함
		plus = 0;
		if (sum >= 10) {
			plus = sum / 10;
			sum = sum % 10;
		}
		result.push_back(sum); // 결과값을 저장 
	}
	if (plus != 0) { //만약 두 수의 덧샘으로 자릿수가 하나 많아 지는 경우
		result.push_back(1); //끝에 1을 삽입
	}
	reverse(result.begin(), result.end()); //결과값도 뒤집어져 있으므로 다시 되돌려줌

	for (int i = 0; i < result.size(); i++) {
		cout << result[i]; //결과 출력
	}
}