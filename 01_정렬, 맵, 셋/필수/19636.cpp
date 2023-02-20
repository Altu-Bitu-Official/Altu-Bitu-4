#include <iostream>
#include <algorithm> 
#include <vector>
#include <math.h>

using namespace std;

int main(void) {

    int W0 = 0, I0 = 0, A0 = 0, T, day;
    int intake;
    int consumption;
    int BMRX = W0; //일일 기초 대사량 고려X
    int BMRO = W0; //일일 기초 대사량 고려O
    int A = A0;//일일 활동 대사량(다이어트 전 데시는 운동 안함)

    cin >> W0 >> I0 >> T;

    cin >> day >> intake >> consumption;
 

    //다이어트 중
    for (int i = 0; i < day; i++) {
        BMRX = BMRX + (intake - (A0 + consumption));
        BMRO = BMRO + (intake - (A + consumption));
        
        if (abs(intake - (A + consumption)) > T)
            A = A + (intake - (A + consumption) / 2);
    }

    if (BMRX <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << BMRX << A0 << "\n";
    }

    if (BMRO <= 0 || A <= 0) {
        cout << "Danger Diet\n";
    }

    else {
        cout << BMRO << A;
        if (A - A0 < 0) { //여기 뭔가 아닌 거 같은데 wO으로 비교하기에는 현재 몸무게를 몰라요...
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }
}