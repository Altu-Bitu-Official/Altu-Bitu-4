#include "iostream"
#include "vector"

using namespace std;

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
    vector<int> result(2);
    result[0] = (a_denomin * b_numer) + (a_numer * b_denomin);
    result[1] = b_denomin * a_denomin;

    int gcd = getGcd(result[0], result[1]);

    result[0] /= gcd;
    result[1] /= gcd;

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
