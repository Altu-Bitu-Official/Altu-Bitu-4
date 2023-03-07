#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
 	if(a<b) swap(a,b); //a가 b보다 항상 커야 하므로 두개 바꿔줘야 함
    if(a%b==0) return b; //a%b가 0이 되는 순간 b가 최대 공약수(최대공약수 구해짐)
    else return gcd(b, a%b); //그 전까지는 계속 재귀함수 호출
 }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
  int a1, b1, a2, b2;
	cin >> a1 >> b1;
	cin >> a2 >> b2;
	
	//통분
	int res1 = (a1*b2)+(a2*b1);
	int res2 = b1*b2;
	int GCD = gcd(res1, res2); //tmp1, tmp2의 최대공약수 구하기
	
	res1/=GCD; res2/=GCD; //최대 공약수로 분모 분자를 각각 나누어주면 된다.
	cout << res1 << " " << res2;
}