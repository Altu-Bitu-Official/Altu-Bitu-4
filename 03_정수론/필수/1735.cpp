//
// Created by LG on 2023-03-07.
//
#include <iostream>

using namespace std;

int getGCD(int A, int B){
    while(true){
        if(B==0)
            return A;
        A = A%B;
        swap(A, B);
    }
}

int main(){
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int A = a1*b2 + a2*b1;
    int B = b1*b2;

    int gcd = getGCD(A, B);
    cout << A/gcd << ' ' << B/gcd;
}
