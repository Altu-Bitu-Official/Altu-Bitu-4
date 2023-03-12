#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 소수 여부 반환 함수: 에라토스테네스의 체 이용
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true);//n+1: 인덱스랑 안 헷갈리려곤
    is_prime[0] = is_prime[1] = false;//얘네는 소수 아님
    for (int i = 2; i * i <= n; i++) {//돌려서 판단(범위 i*i: i의 배수로 판단하는 것이니 저 범위까지만 구해도 됨
        if (!is_prime[i]) {//이미 거짓인거 나왔으면 또 돌릴 필요가 없음->위로감->연산단축
            continue;
        }
        for (int j = i * i; j <= n; j += i) {//i*i부터 시작: 전 숫자 배수에서 이미 지워서 i*i부터 시작하게 되어있음.
            is_prime[j] = false;//배수들 false로 바꿈
        }
    }
    return is_prime;//소수목록 구한거 리턴
}

// n = a + b를 만족시키는 a 반환
// 두 홀수 소수의 합으로 나타낼 수 있다-> 
int goldbach(int n, vector<bool>& is_prime) {
    for (int a = 3; a <= n / 2; a += 2) {//소수부터시작: 3, 소수는 다 홀수임->+2, n/2: 더할거면은 반 쪼개서 저쪽수랑 이쪽 수 더하는거니까 당연
        // 2보다 큰 짝수 소수는 존재하지 않으므로
        // a = 3부터 탐색해도 a와 b 모두 홀수여야 한다는 조건 만족
        //여기서 더하기로 안 해도 자동판별됨
        //이유: 일단 왼쪽이 소수임-> 그럼 n-a도 소수인지 판별하는 순간 바로 소수의 합이 짝수인지도 증명됨(n-a가 b니까)
        if (is_prime[a] && is_prime[n - a]) {//두 개 소수면
            return a;//소수반환(하나만 리턴해도됨. 두 수 더할때 n이니까 빼면 구할 수 있어서)
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0 반환
    return 0;//0:  맞는지아닌지 판별조건
}

/* [백준 6588: 골드바흐의 추측]
 * 1. 3보다 크거나 같고 n / 2보다 작거나 같은 소수 a를 오름차순으로 탐색한다.
 * 2. 1에서 찾은 a에 대하여 n - a(=b)도 소수이면 골드바흐의 추측이 성립한다.
 * 3. 골드바흐의 추측이 성립하면 a를, 성립하지 않으면 0을 반환한다.
 */

int main() {
    // 입력
    vector<int> arr;//인풋넣는 어레이
    int input;//인풋
    while (1) {
        cin >> input;//입력받음
        if (input == 0) {//종료조건
            break;//빠져나감
        }
        arr.push_back(input);//어레이에 꼬박꼬박 넣음
    }

    // 연산
    int max_num = *max_element(arr.begin(), arr.end());//이 부분이 다르다. 필요갯수만큼만 연산함.(맥스만큼만 소수구한다(a+b에서 a.b가 max_num보다 커 질수가 없으니까)
    vector<bool> is_prime = getPrimes(max_num);//딱 이만큼만 구함.(속도 확 줄음)

    for (int i = 0; i < arr.size(); i++) {//들어온 숫자에 대해서 골드바흐의 추측 돌림
        int a = goldbach(arr[i], is_prime);//인풋 어레이랑 소수 판단 목록을 넘겨줌

        // 출력
        //0: 틀렸는지아닌지 판별조건
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";//골드바흐추측대로
        }
        else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n";//틀렸다고메세지
        }
    }
    return 0;
}
