#include <iostream>
#include <vector>

using namespace std;
bool flag = false;
bool num[1000001]; //소수 여부 저장 - false일 때 소수
vector<int> prime; //소수 저장

void calculate(int n, vector<int>& prime) {
    for(int i=0; i<prime.size(); i++){
        if (!num[n - prime[i]]) {
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

void eratosthenes(void) {
    for (int i = 3; i <= 1000000; i += 2) {
        if (!num[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 1000000; j += i) {
                num[j] = true;
                //i로 만들어지는 모든 수 true로 저장
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입출력 속도 향상

    eratosthenes();


    //입력
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        else{
            calculate(n, prime);
        }
        
    }

    return 0;
}