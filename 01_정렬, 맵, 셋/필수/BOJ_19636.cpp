#include<iostream>
#include<cmath>

using namespace std;


void isYoyo(int first일에섭, int new일기대) {
    if ((first일에섭 - new일기대) > 0) cout << "YOYO";
    else cout << "NO";
}

int main() {
    int W, I, T;//다이어트전 체중, 일.에.섭 겸 일.기.초, 역치. 일.활.대 초기값은 0
    cin >> W >> I >> T;//다이어트기간동안 체중과 일.기.초는 변화
    //일일에너지섭취량과 활동대사량은 변하지 않음

    int d, i, a;//다이어트기간, 다이어트중 일.에.섭, 다이어트중 일.활.대
    cin >> d >> i >> a;

    int w1 = W;
    int w2 = W;
    int i1 = I;
    for (int k = 0; k < d; k++) {
        w1 += i - (I + a);
        w2 += i - (i1 + a);

        if (abs(i - (i1 + a)) > T) {
            i1 += floor((i - (i1 + a)) / 2.0);
        }
    }

    if (w1 <= 0) cout << "Danger Diet\n";
    else  cout << w1 << ' ' << I << endl;

    
    if (w2 <= 0 || i1 <= 0) cout << "Danger Diet" << endl;
    else cout << w2 << ' ' << i1 << ' ';
    isYoyo(I, i1);



}