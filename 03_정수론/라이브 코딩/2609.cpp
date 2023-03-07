#include <iostream>
#include <algorithm>

using namespace std;

// O(n)으로 최대공약수(gcd) 구하기
int getGcdBad(int a, int b){
    for (int i = min(a,b); i>0; i--){
        if (a%i == 0 && b%i == 0){
            return i;
        }
    }
    return 1;
}

// 재귀 이용하여 최대공약수(gcd) 구하기
int getGcdRecur(int a, int b){
    if (b == 0){
        return a;
    }
    return getGcdRecur(b,a%b);
}

// 반복문 이용하여 최대공약수(gcd) 구하기
int getGcdIter(int a, int b){
    while (b!=0){
        a = a%b;
        swap(a,b);
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    int gcd = getGcdIter(max(a,b), min(a,b));
    int lcm = a*b / gcd;
    
    cout << gcd << "\n" << lcm;
    return 0;
}