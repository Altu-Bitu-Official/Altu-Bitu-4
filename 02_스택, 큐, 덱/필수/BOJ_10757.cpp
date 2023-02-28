#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAX_LENGTH = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, ans = "";
    int ans_arr[MAX_LENGTH] = {};

    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();

    // 덧셈 결과의 최대 자릿수 길이
    int len = max(a_len, b_len) + 1;
    
    // 뒤집어서 각 자릿수끼리 더한 후 다시 뒤집어준다.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i = 0;
    while(a_len>0 || b_len>0) {
        ans_arr[i] += (a[i]-'0') + (b[i]-'0');
        if (ans_arr[i] >= 10) {
            ans_arr[i + 1] += 1;
            ans_arr[i] = ans_arr[i] - 10;
        }
        a_len--;
        b_len--;
        i++;
    }

    // 최대 자릿수 계산
    if (ans_arr[len - 1] == 0) {
        len--;
    }

    // 결과를 string으로 변환 후 뒤집기
    for (int i = 0; i < len; i++) {
        ans += to_string(ans_arr[i]);
    }
    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}