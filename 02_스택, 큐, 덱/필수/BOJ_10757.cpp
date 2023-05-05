// 벡터 사용
#include <iostream>
#include <vector>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
int charToint(char ch) {    // 문자를 숫자로 바꿔주는 함수
    return (ch - '0');  // 문자 '0'의 아스키 값 빼기
}

vector<int> calcPlus(string& a, string& b) {    // a와 b를 전달받아서 계산하는 함수 calcPlus
    int idx_a = a.size() - 1; // a의 일의 자리 인덱스
    int idx_b = b.size() - 1; // b의 일의 자리 인덱스
    bool carry = false; // 올림 저장할 변수
    vector<int> ans;    // 계산 결과 저장할 스택

    while (idx_a >= 0 && idx_b >= 0) {  // 일의 자리부터 시작, b의 최고 자리 수까지 계산
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 스택에 push
    }

    // a에서 남은 숫자 반영 (a의 길이 > b의 길이)
    while (idx_a >= 0) {    // a의 남은 숫자 끝날 때까지
        int num = charToint(a[idx_a--]);    // 문자를 숫자로 바꾸기

        num += carry;   // num에 carry 더해주기
        carry = num / 10;   // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10);    // 올림을 제외한 값만 스택에 push
    }

    // 남은 올림 확인
    if (carry) {    // 올림이 남아있으면
        ans.push_back(1);   // 1 push (올림)
    }

    return ans; // 최종 결과 리턴
}

int main() {
    ios::sync_with_stdio(0);    // 입출력 속도 향상
    cin.tie(0);

    string a, b;    // 두 정수 A와 B를 문자열로 저장할 변수 a, b 선언
    vector<int> ans;    // 결과 저장할 벡터 선언

    //입력
    cin >> a >> b;  // 계산할 두 정수 입력받아서 a, b에 저장

    //연산
    if (a.length() < b.length()) {       // b의 길이가 더 길다면
        swap(a, b); // a, b 값 바꾸기
    }

    ans = calcPlus(a, b);   // a와 b를 calcPlus 함수에 전달 후 리턴 결과를 ans에 저장

    //출력
    while (!ans.empty()) {  // 결과 저장된 스택이 빌 때까지 반복
        cout << ans.back(); // 스택의 마지막 요소 출력
        ans.pop_back(); // 마지막 요소 삭제
    }
}