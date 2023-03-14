#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX 1000000

vector<bool> is_prime(MAX+1, true);

void checkPrime() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i*i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

int addNumber(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

void checkAnswer(int n) {
    set<int> used_num;
    int sum;

    for (int i = 2; i <=n; i++) {
        if (!is_prime[i]) {
            continue;
        }
        used_num.insert(0);
        sum = addNumber(i);
        while (1) {
            if (used_num.find(sum) != used_num.end() || sum == 1) {
                break;
            }
            used_num.insert(sum);
            sum = addNumber(sum);
        }
        if (sum == 1) {
            cout << i << '\n';
        }
        used_num.clear();
    }
}

int main() {
    int n;
    cin >> n;

    checkPrime();

    checkAnswer(n);

}