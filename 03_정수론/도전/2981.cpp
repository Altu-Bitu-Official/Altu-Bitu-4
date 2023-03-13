#include <iostream>
#include <vector>
#include <algorithm>    // sort() 이용

using namespace std;

// 최대공약수(GCD) 계산 함수: 유클리드 호제법 이용
int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

// 가능한 M 검색 함수
vector<int> solution(int n, vector<int> &numbers) {
    vector<int> result; //가능한 M 저장

    // 1. 검문소 사이 간격의 최대공약수(최대 M) 계산
    int gcd = numbers[1] - numbers[0];
    for (int i = 2; i < n; i++) {
        gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
    }

    // 2. 가능한 모든 M 찾기: 최대공약수의 약수 찾기
    for (int i = 2; i * 2 <= gcd; i++) {
        if (gcd % i == 0) {
            result.push_back(i);
        }
    }
    result.push_back(gcd);

    return result;
}

/* [백준 2981: 검문]
 * A, B, C를 M으로 나눴을 때의 나머지가 모두 같을 때, 이 나머지 값을 K라 하면
 * A = M * a + K, B = M * b + K, C = M * c + K 이므로
 * B - A = (M * b + K) - (M * a + K) = M(b - a)
 * C - B = (M * c + K) - (M * b + K) = M(c - b)
 * 즉, 우리가 구해야 하는 M은 각 검문소 사이 간격 간의 모든 공약수!
 * 
 * 1. 검문소 사이 간격 간의 최대공약수 구하기
 * 2. 1에서 구한 최대공약수의 모든 약수 구하기
 *    (모든 약수를 구할 때 시간초과 주의!)
 */

int main() {
    // 입력
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // 연산
    sort(numbers.begin(), numbers.end());
    vector<int> result = solution(n, numbers);

    // 출력
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}