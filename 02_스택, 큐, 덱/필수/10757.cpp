//벡터 사용
#include <iostream>
#include <vector>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
int charToint(char ch){ // 문자를 숫자로 변경해주는 함수
    return (ch - '0'); // 문자 -> 숫자 연산식
}

vector<int> calcPlus(string &a, string &b) { // 매개변수로 전달받은 a, b의 원본 참조
    int idx_a = a.size() - 1; // a의 일의 자리 인덱스
    int idx_b = b.size() - 1; // b의 일의 자리 인덱스
    bool carry = false; // 올림수 있으면 1, 없으면 0
    vector<int> ans; // 결과를 저장할 벡터

    while (idx_a >= 0 && idx_b >= 0) { // 두 수의 각 자리 수를 모두 더했을 때까지
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry(올림수)를 더함
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 벡터에 push
    }

    // a(큰 수)에서 남은 숫자 반영
    while (idx_a >= 0) { // 큰 수의 모든 자리 수에 대해 연산을 수행했을 때까지
        int num = charToint(a[idx_a--]); // 문자를 숫자로 바꾸고 인덱스 변경

        num += carry;            // num에 carry(올림수)를 더함 
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 벡터에 push
    }

    // 남은 올림 확인
    if (carry){ // 올림수가 있으면
        ans.push_back(1); // 가장 큰 자리 수에 1을 올림
    }

    return ans; // 결과 반환
}

int main() { // 메인 함수
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; // 두 수 a, b를 문자열 형태로 저장
    vector<int> ans; // 결과를 저장할 벡터

    //입력
    cin >> a >> b; // 두 수 a, b를 차례대로 입력 받음

    //연산
    if (a.length() < b.length()) {       // b의 길이가 더 길다면
        swap(a, b); // 따로 큰 수, 작은 수에 저장하지 않고 두 수의 순서를 바꿔줌
    }

    ans = calcPlus(a, b); // 큰 수의 덧셈 연산 수행해서 ans 벡터에 저장

    //출력
    while (!ans.empty()) { // ans가 empty일 때까지
        cout << ans.back(); // 벡터의 맨 뒤 요소를 출력하고 (가장 큰 자리부터)
        ans.pop_back(); // 맨 뒤 요소를 삭제
    }
}