#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> prime; //소수 저장
bool num[1000001]; //에라스토테네스의 체 이용
bool flag = false; //flag가 true이면 추측 성립


void eratosthenes(int n) {
    //에라스토테네스의 체
    for (int i = 3; i <= n; i += 2) {
        //2보다 큰 짝수 소수는 존재하지 않으므로
        if (num[i]) continue;
        prime.push_back(i);
        //소스를 저장하는 벡터 prime에 i 저장
        for (int j = i + i; j <= n; j += i) {
            num[j] = true;
            //i로 만들어지는 모든 수 true로 저장
        }
    }
}
void calculate(int n) {
    // n/2보다 작거나 같은 소수를 오름차순으로 탐색
    for (int i = 0; i < n / 2; i += 2) {
        if (!num[n - prime[i]]) {
            //num[n-prime[i]]가 true일 때 골드바흐의 추측 성립
            //n = prime[i] + n-prime[i]의 모양
            cout << n << " = " << prime[i] << " + " << n - prime[i] << endl;
            flag = true;
            break;
        }
        if (n - prime[i] <= prime[i]) break;
    }
    if (!flag) {
        cout << "Goldbach's conjecture is wrong." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입출력 속도 향상

    //입력
    vector<int> arr; //입력받은 값을 저장한 벡터
    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        arr.push_back(n);
        //0을 입력할 때까지 반복해서 arr에 입력값 저장
    }
    int max_num = *max_element(arr.begin(), arr.end());
    //arr의 모든 원소 중 가장 큰 원소를 max_num으로 저장
    eratosthenes(max_num);
    //에라토스테네스의 체 이용

    for (int i = 0; i < arr.size(); i++) {
        calculate(arr[i]);
    }

    return 0;
}