#include <iostream>
#include <algorithm> 

using namespace std;

//O(n)으로 최대공약수(gcd) 구하기
int getGcdBad(int a, int b) {
    for (int i = min(a, b); i > 0; i--) {
        //i가 a의 약수이자 b의 약수이면 -> i는 공약수
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

//재귀 이용하여 최대공약수(gcd) 구하기
int getGcdRecur(int a, int b)  {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a%b);
}

//반복문 이용하여 최대공약수(gcd) 구하기
int getGcdIter(int a, int b)  {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    //입력
    int a, b;
    cin >> a >> b;

    //최대공약수
    int gcd = getGcdRecur(max(a, b), min(a, b));
    //최소공배수
    int lcm = a * b / gcd;

    //출력
    cout << gcd << "\n" << lcm;
    return 0;
}