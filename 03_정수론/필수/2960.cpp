#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int EratosthenesNth(int n, vector<bool>& is_prime, int k);//주소에의한전달

int main() {
	//입력
	int n, k;
	cin >> n >> k;
	vector<bool> is_prime(n+1);//n+1개 생성(인덱스맞추기)
	for (int i = 0; i <= n; i++) {
		is_prime[i] = true;
	}
	//계산&출력
	int Eratosthenes_Nth=EratosthenesNth(n, is_prime, k);
	cout << Eratosthenes_Nth;
	
	return 0;
}

int EratosthenesNth(int n, vector<bool>& is_prime, int k) {//&: 주소에의한전달
	int count = 0;
	//0과 1은 소수가 아니므로 먼저 제거
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {//i가 소수라면
			is_prime[i] = false;//소수지우기
			count++;
			for (int j = i; j <= n; j+=i) {
				if (is_prime[j] != false) 
				{
					count++;
				}
				if (count == k)
				{
					return j;
				}
				is_prime[j] = false;//소수의 배수들 다 false로 만든다.
			}
		}
	}
}