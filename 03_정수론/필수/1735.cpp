#include "iostream"
#include "vector"

using namespace std;

// 유클리드 호제법을 이용해 최대공약수 구하기
int getGcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

vector<int> getIrreducibleFraction(int a_numer, int a_denomin, int b_numer, int b_denomin) {
    vector<int> result(2);  // 반환값을 담을 int형 벡터 (결과를 반환할 때 더 좋은 방법이 있다면 조언 부탁드립니다!)
    result[0] = (a_denomin * b_numer) + (a_numer * b_denomin); // 두 분수 합의 분자
    result[1] =  a_denomin * b_denomin;  // 두 분수 합의 분모

    // 기약분수로 만들기 위해서는 분모와 분자의 최대공약수로 분수를 정리해줘야하므로
    // 분모, 분자의 최대공약수를 구해준다.
    int gcd = getGcd(max(result[0], result[1]), min(result[0], result[1]));

    // 구해진 최대공약수로 분모와 분자를 각각 나눠준다
    result[0] /= gcd;
    result[1] /= gcd;

    // result값 반환
    return result;
}

int main() {
    // 입력
    int a_numer, a_denomin, b_numer, b_denomin;
    cin >> a_numer >> a_denomin >> b_numer >> b_denomin;
    // 연산
    vector<int> result = getIrreducibleFraction(a_numer, a_denomin, b_numer, b_denomin);
    // 출력
    cout << result[0] << " " << result[1];
}