#include <iostream>
#include <cstring>
using namespace std;
const int ALPHA_MAX=26;
int main() {
    char input[51];//string: 동적할당->메모리잡아먹음->배열하자
    //벡터쓰니까 시간초과->배열로바꿈
    int alphabet[26] = { 0 };  // 각 알파벳 개수를 저장할 배열 초기화
    //입력
    cin >> input;

    //길이세기(input)
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        alphabet[input[i] - 'A']++;  // 해당 알파벳 개수 증가
    }

    int oddCnt = 0;  // 홀수인 알파벳 개수 카운트
    char oddChar;  // 홀수인 알파벳 저장
    
    for (int i = 0; i < ALPHA_MAX; i++) {
        if (alphabet[i] % 2 == 1) {  // 해당 알파벳 개수가 홀수인 경우
            oddCnt++;  // 홀수인 알파벳 개수 증가
            oddChar = 'A' + i;  // 홀수인 알파벳 저장
        }
    }

    // 홀수인 알파벳이 2개 이상인 경우 팰린드롬을 만들 수 없음
    // 홀수인 알파벳은 하나만 있어야한다.
    if (oddCnt >= 2) {
        cout << "I'm Sorry Hansoo";
        return 0;//끝
    }

    //아무튼 위에서 걸러짐->홀수인거 고려안해도됨
    // 문자열 생성
    char ans[51];
    int left = 0, right = length - 1;//마지막은 '\0'이니까
    for (int i = 0; i < ALPHA_MAX; i++) {
        while (alphabet[i] > 1) {  // 해당 알파벳 개수가 2 이상인 경우
            ans[left] = ans[right] = 'A' + i;  // 좌우 대칭으로 해당 알파벳 추가
            left++;
            right--;
            alphabet[i] -= 2;
        }
    }

    // 홀수인 알파벳이 1개인 경우 가운데에 추가
    if (oddCnt == 1) {
        int index = length / 2;
        ans[index] = oddChar;
    }

    // 결과 출력
    for (int i = 0; i < length; i++) {
        cout << ans[i];
    }

    return 0;
}
