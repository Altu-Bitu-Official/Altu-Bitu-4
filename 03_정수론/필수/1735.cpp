// BOJ 1735번 분수합
#include <iostream>
using namespace std;

/* 두 개의 분수가 주어졌을 때 그 합을 기약분수의 형태로 구하기
 * 입력의 첫째 줄 : 첫 번째 분수의 분자(a), 분모(b)를 뜻하는 두 개의 자연수가 주어짐
 * 입력의 둘째 줄 : 두 번째 분수의 분자(c), 분모(d)를 뜻하는 두 개의 자연수가 주어짐
 * 네 자연수는 모두 30,000 이하
 */

//최대공약수를 계산하는 함수 (유클리드 호제법 이용)
int getGcd(int a, int b){
    if(b==0){ //마지막으로 b가 0이 되면
        return a; //a를 리턴함 = a가 우리가 찾는 최대공약수이다!
    }
    return getGcd(b, a%b); //b가 0이 아닐 때는 재귀적으로 getGcd함수를 호출
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력 받기
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    //연산
    int x = a*d + b*c; // 결과값의 분자
    int y = b*d; //결과값의 분모
    int gcd = getGcd(x,y); //getGcd함수를 통해서 최대공약수 구하기
    x = x/gcd; //기약분수의 분자
    y = y/gcd; //기약분수의 분모

    //출력
    cout << x << " " << y;
    return 0;
}