#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> getPrimes(int n) {
    vector<bool> primes(n + 1, true);  
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i] !=0 ) {
            continue;     //소수가 아니면 탐색을 하지 않는다.
        }
        for (int j = i * i; j <= n; j += i) {
            primes[j] = false;
        }
    }
    return primes;
}


int goldbach(int n, vector<bool> &primes) {
    for (int a = 3; a <= n / 2; a+= 2) {
        if (primes[a] && primes[n - a]) {
            return a;
        }
    }
    return 0;
}

int main() {
    vector<int> vec;
    int input;
    while(1) {
        cin >> input;
        if (input == 0) {
            break;
        }
        vec.push_back(input);
    }


    int max_num = *max_element(vec.begin(), vec.end()); //*연산자를 통해 최대값 구해보기
    vector<bool> primes = getPrimes(max_num);

    for (int i = 0; i < vec.size(); i++) {
        int a = goldbach(vec[i], primes);


        if (a != 0) { 
            cout << vec[i] << " = " << a << " + " << vec[i] - a << "\n";
        } else {      
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}