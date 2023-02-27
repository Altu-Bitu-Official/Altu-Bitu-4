#include <iostream>

using namespace std;

int main() {
    int a[10001] = {0}, b[10001] = {0}, n[10001] = {0}, idx, t_len;
    string t;
    cin >> t;
    t_len = t.length() - 1;
    idx = 10001;
    // 입력받은 숫자의 자리수만큼 반복, 배열에 숫자 복사
    for (; t_len >= 0; t_len--) {
        a[idx] = t[t_len] - '0';
        idx--;
    }
    idx = 10001;

    cin >> t;
    t_len = t.length() - 1;
    idx = 10001;
    // 입력받은 숫자의 자리수만큼 반복, 배열에 숫자 복사
    for (; t_len >= 0; t_len--) {
        b[idx] = t[t_len] - '0';
        idx--;
    }

    for (int i = 10001; i > 0; i--) {
        n[i] += a[i] + b[i];
        // 한 자리의 숫자가 10 이상 -> 다음 자리 올림 후 자신에서 -10 
        if (n[i] >= 10) {
            n[i-1] ++;
            n[i] -= 10;
        }
    }

    idx = 0;

    // 숫자가 시작되는 구간 찾기
    while (1) {
        if (n[idx] != 0) break;
        idx++;
    } 

    for (int i = idx; i <= 10001; i++) {
        cout << n[i];
    }

}