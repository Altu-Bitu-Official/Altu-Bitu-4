#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
string solution(string number, int k) {
    string answer = "";
    string tmp = number;

    // p개의 숫자를 뽑기
    int p = number.length() - k;
    for (int i = 1; i <= p; i++) {
        // 남은 tmp의 문자열에서 가장 큰 수를 뽑기
        // 단, 뒤에 최소 p-i개의 수가 남아있어야함
        int idx = 0;
        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] > tmp[idx] && (j + (p - i) < tmp.length())) { // <- 이 부분이 문제였음
                idx = j;
            }
        }
        // 뽑은 수를 더해준다
        answer += tmp[idx];
        // tmp 업데이트
        tmp = tmp.substr(idx + 1);
    }
    

    return answer;
} 9, 10 번 시간초과
*/

string solution(string number, int k) {
    string answer = "";

    // p개의 숫자를 뽑기
    int p = number.length() - k;
    int startidx = 0;

    for (int i = 1; i <= p; i++) {
        int maxidx = startidx;
        char maxint = number[startidx];
        for (int j = startidx; j < k+i; j++) { // && 연산말고 남겨둘 문자의 개수 범위를 미리 지정해주면 시간초과가 나지 않음
            if (number[j] > number[maxidx]) {
                maxidx = j;
                maxint = number[j];
            }
        }
        // 뽑은 수를 더해준다
        answer += maxint;
        startidx = maxidx + 1;
    }


    return answer;
}
int main() {
    
    string n; int k;
    cin >> n >> k;

    cout << solution(n, k);
    return 0;
}