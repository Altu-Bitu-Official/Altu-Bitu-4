#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000 // 입력 제한

vector<bool> isPrime(int n) { // n까지의 수들의 소수 여부가 저장된 벡터를 반환하는 함수
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2;  i*i <= n; i++) {
        if(is_prime[i]) { // i가 소수라면
            for(int j = i*i; j <= n; j += i) { // 처음 지워지는 수는 제곱수부터, i의 각 배수마다 반복
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector<int> findNum(vector<bool> &prime, int &target) {
    vector<int> result;

    for(int i = target - 3; i >= target / 2; i -= 2) {   // target으로부터 3 이상 차이나는 수부터 탐색 (다른 수가 3 이상이므로)
        int other = target - i;
        if(prime[i] && prime[other]) {      // 더해질 두 수가 모두 소수면
            result.push_back(i);            // 결과에 넣고 반복문을 빠져나감
            result.push_back(other);
            break;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> evens; // 입력으로 들어온 짝수들을 저장
    int input;

    vector<bool> prime = isPrime(MAX); // MAX까지의 소수 한 번에 저장
    
    while(true) {
        cin >> input; 
        if(input == 0) {
            break;
        }

        int target = input; 

        vector<int> result = findNum(prime, target); // 합으로 표현될 두 소수 찾기

        if(result.size() == 2) { // 두 소수가 모두 저장되었다면 결과 출력
            cout << target << " = " << result[1] << " + " << result[0] << "\n";
        }
        else {                   // 아니라면 오류 메세지 출력
            cout << "Goldbach's conjecture is wrong.";
        }
    }
    return 0;
}