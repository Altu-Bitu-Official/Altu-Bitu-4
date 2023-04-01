#include <iostream>

using namespace std;


// 최대공약수(GCD) 계산 함수: 유클리드 호제법 이용
int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

/* [백준 1735: 분수 합]
 * a/b + c/d = (a*d)/(b*d) + (b*c)/(b*d) = (a*d + b*c)/(b*d)
 * 위 분수를 기약분수로 나타낸 것을 x/y라 하고,
 * gcd를 (a*d + b*c)와 (b*d)의 최대공약수라 하면
 * x = (a*d + b*c) / gcd
 * y = (b*d) / gcd
*/

int main() {
    // 입력 
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 연산
    int x = (a * d) + (b * c);  // 분자
    int y = b * d;              // 분모
    int gcd = getGCD(x, y);
    x = x / gcd;    // 기약분수의 분자
    y = y / gcd;    // 기약분수의 분모

    // 출력
    cout << x << " " << y;
    
=======
int getGcd(int a, int b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(){

    int up1, down1, up2, down2;
    cin >> up1 >> down1; 
    cin >> up2 >> down2;
    int gcd, lcm;

    gcd = getGcd(max(down1,down2), min(down1,down2));
    lcm = down1 * down2 / gcd; // 최소공배수로 분모 계산
    
    int up = up1 * (lcm/down1) + up2 * (lcm/down2); // 분자 계산

    int is_coprime = getGcd(max(up,lcm), min(up,lcm)); //분모와 분자가 기약분수인지 확인

    if(is_coprime != 1){
        up /= is_coprime;
        lcm /= is_coprime;
    }

    cout << up << ' ' << lcm << '\n';

    return 0;
}
