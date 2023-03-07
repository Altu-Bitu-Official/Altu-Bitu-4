// 분수 합

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    while (b!=0){
        a %= b;
        swap(a,b);
    }
    return a;
}
int lcm(int a, int b){
    return (a*b/gcd(a, b));
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    
    int l = lcm(b,d);
    int u = a*(l/b) + c*(l/d);
    int f = gcd(l, u);
    if (f != 1){
        l /= f;
        u /= f;
    }
    cout << u << " " << l;
    return 0;
}
