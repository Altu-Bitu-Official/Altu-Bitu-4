//벡터 사용
#include <iostream>
#include <vector>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
int charToint(char ch){     //char 형태를 받아서 int 형으로 변환하는 함수
    return (ch - '0');
}

vector<int> calcPlus(string &a, string &b) {
    int idx_a = a.size() - 1; // 일의 자리 인덱스
    int idx_b = b.size() - 1;
    bool carry = false;      // carry는 어차피 1 아니면 0
    vector<int> ans;

    while (idx_a >= 0 && idx_b >= 0) {      //인덱스 b의 자릿수만큼 연산
        int num = charToint(a[idx_a--]) + charToint(b[idx_b--]); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 벡터에 push
    }

    // a에서 남은 숫자 반영
    while (idx_a >= 0) {
        int num = charToint(a[idx_a--]);    // 문자를 숫자로 바꾸기, 인덱스 변경

        num += carry;               
        carry = num / 10;           
        ans.push_back(num % 10);    
    }

    // 남은 올림 확인 - carry 가 1이어서 최종 자릿수가 늘어났으면 ans에 1을 push
    if (carry){
        ans.push_back(1);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    vector<int> ans;

    //입력
    cin >> a >> b;

    //연산
    if (a.length() < b.length()) {       // b의 길이가 더 길다면
        swap(a, b);                      // 둘의 값을 바꿔서 항상 a가 b보다 짧지 않도록 함
    }

    ans = calcPlus(a, b);       

    //출력
    while (!ans.empty()) {      // ans 벡터가 빌때까지 ans의 마지막 원소를 출력하고 제거
        cout << ans.back();     
        ans.pop_back();
    }
}