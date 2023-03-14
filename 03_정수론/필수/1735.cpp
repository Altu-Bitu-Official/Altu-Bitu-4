#include <iostream>

using namespace std;

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
