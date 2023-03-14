#include <iostream>
#include <vector>

using namespace std;

// N을 받고 한수의 개수를 리턴하는 함수
int findNum(int n) {
    int cnt = 0;

    if (n <= 99) {
        cnt = n;
    }   // 한두자리수는 모든 수가 한수.
    else {
        if (n == 1000) n = 999; // 아래 식이 세자리수 기준으로 짜여 있고 애초에 1000은 한수가 아니기 때문에 1000은 검사에서 제외. 
        
        for (int i = 100; i <= n; i++) {
            int first_di = i / 100;
            int sec_di = i / 10 % 10;
            int third_di = i % 10;

            if (first_di - sec_di == sec_di - third_di) {
                cnt++;
            }
        }
        cnt += 99;  //세 자리수에서 구할 수 있는 한수를 모두 구한 뒤 한두자리수의 개수와 합침.
    }
    return cnt;
}

int main() {
    int n;
    //입력
    cin >> n;

    cout << findNum(n);
}