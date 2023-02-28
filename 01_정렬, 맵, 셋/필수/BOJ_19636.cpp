#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int w0, i0, t, d, i, a, after_w, after_i;
    cin >> w0 >> i0 >> t >> d >> i >> a;
    after_w = w0;
    after_i = i0;

    // 기초 대사량 변화 전 체중 계산
        after_w += (i - (i0 + a)) * d;
    // 출력

    if (after_w <= 0) {cout << "Danger Diet" << '\n';}
    else {
        cout << after_w << " " << after_i << '\n';
    }
    after_w = w0;

    while (d--) {
        after_w += (i - (after_i + a));
        if (after_w <= 0) {break;}
        if (abs(i-(after_i+a)) > t) {
            // 음수 홀수일 때 -> -1 더해줌.
            if (i-(after_i+a) < 0 && abs(i-after_i-a) %2 == 1) {after_i += (i-(after_i+a))/2 -1;}
            else {after_i += (i-(after_i+a))/2;}
        }
        if (after_i <= 0) {break;}
    }

    if (after_w <= 0 || after_i <= 0) {cout << "Danger Diet";}
    else {
        cout << after_w << " " << after_i << " ";
        if (i0 - after_i >0) {cout << "YOYO";} // 전섭취 - 변화 일일 기초 대사량 (활동은 0)
        else {cout << "NO";}
    }

}