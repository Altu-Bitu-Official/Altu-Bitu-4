#include "iostream"
#include "vector"
#include "queue"
#include "set"
#include "algorithm"

using namespace std;

// 2번째줄부터의 입력값을 담는 구조체
struct Input {
    int change; // 문자가 바뀐 횟수
    char stop;  // 회전을 멈췄을 때 가리킨 글자
};

void getWheelOfFortune(queue<Input> inputs, int n) {
    vector<char> result(n, NULL);   // 행운의 바퀴 결과를 담을 vector
    Input input;                       // 현재 Input을 담을 Input
    int sum = 0;                       // 문자가 바뀐 총 횟수를 int
    set<char> check_char;              // 문자 중복 등록 체크를 위한 set

    // inputs이 빌 때까지
    while (!inputs.empty()) {
        // inputs의 맨 앞 Input값 가져오기
        input = inputs.front();
        inputs.pop();
        // 문자가 바뀐 총 횟수 업데이트
        sum += input.change;

        // sum%n => 원형칸을 빙글빙글 도는 것 구현(?)
        // 아무것도 없다면 result에 현재 문자 삽입
        if (result[sum % n] == NULL) {
            result[sum % n] = input.stop;
            // 중복 문자 체크 후에 check_char 업데이트
            if(check_char.find(input.stop) == check_char.end())
            {
                check_char.insert(input.stop);
                continue;
            }
            // continue에 걸리지 않았다면 => 중복된 문자가 다른 위치에 입력되었을 경우이므로 ! 반환
            cout << '!';
            return;
        }
        // 똑같은 문자가 이미 삽입되어 있다면 패스
        else if (result[sum % n] == input.stop) {
            continue;
        }
        // 삽입된 문자가 현재 문자와 다를 경우 ! 출력
        else {
            cout << '!';
            return;
        }

        /** 질문1
        바로 위에 두 else if와 else부분을
        else if(result[sum % n] != input.stop){
            cout << '!';
            return;
        }
        로도 대체할 수 있을 것 같은데, 어느쪽이 더 좋은 방법일까요? 별로 상관없을까요?
        **/

        /** 질문2
        while문 안의 첫번째 if문에 관한 질문입니다!
        if문이 이중으로 되어있는데 혹시 이부분을 개선할 수 있는 방법이 있을까요? 이정도의 이중 if문은 괜찮을까요?
        **/
    }
    // 현재는 반대 방향으로 문자들이 저장되어있으므로 reverse해준다
    reverse(result.begin(), result.end());

    int j;
    for (int i = n - sum % n - 1; i < result.size() + (n - sum % n - 1); i++) {
        j = i % n;
        cout << (result[j] = (result[j] == NULL) ? '?' : result[j]);
    }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // n: 돌림판 칸 수, k: 돌리는 횟수
    Input input; // 임시로 input값을 받을 변수
    queue<Input> inputs;

    // 입력
    cin >> n >> k;
    while (k--) {
        cin >> input.change >> input.stop;
        inputs.push(input);
    }
    // 연산, 출력
    getWheelOfFortune(inputs, n);
}
