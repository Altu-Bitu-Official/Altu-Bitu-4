#include "iostream"
#include "algorithm"

using namespace std;

int getTitle(int n) {
    int title = 665;        // 영화 제목 ( 666부터 첫번째 제목이 시작되므로 초기값을 665로 설정)
    int apocalypse = 0;     // n번째 제목인지 비교할 변수

    while (apocalypse != n) {   // n번째 영화의 제목이 나올 때까지 while문을 돌림
        int temp = ++title;     // 영화 제목 증가
        int count = 0;          // title에 666이 연속으로 들어있는지 체크하는 변수

        while (temp != 0) {
            int i = temp % 10;
            // 현재 확인하는 자리의 숫자가 6이라면 count 증가
            // 아니라면 count 초기화
            if (i == 6) {
                count++;
                // 만약 count가 3이라면, 중간에 다른 숫자 없이 6이 연속으로 3번 나온 것이므로
                // apocalyse를 1증가시키고 for문 빠져나가기
                if (count == 3) {
                    apocalypse++;
                    break;
                }
            }
            else {
                count = 0;
            }
            temp /= 10;
        }
    }
    return title;
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 연산과 출력
    cout << getTitle(n);
}