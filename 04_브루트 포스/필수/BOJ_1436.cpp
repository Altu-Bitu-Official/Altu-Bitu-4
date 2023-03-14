#include <iostream>
#include <vector>
#include <string>

using namespace std;

//종말의 수를 구하는 함수
vector<int> findEndNum() {
    vector<int> num;    //종말의 수를 저장하는 벡터
    int t = 1666;
    num.push_back(666);

    while (num.size() < 10000) {
        int cnt = 0;
        string s = to_string(t);

        for (char c : s) {
            if (c == '6') {
                cnt++;
            }   //숫자가 6이면 카운트 증가.
            if (cnt == 3) {
                num.push_back(t);
                break;
            }   //카운트가 3이면 그 수를 벡터에 넣고 break.
            if (c != '6') {
                cnt = 0;
            }   //6 외의 수가 나올 시 카운트 초기화.
        }
        t++;
    }
    return num;
}

int main() {
    int n;
    vector<int> num = findEndNum(); //종말의 수가 들어있는 벡터

    //입력
    cin >> n;
    //출력
    cout << num[n-1];
}