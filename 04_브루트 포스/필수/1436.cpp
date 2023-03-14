#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int cnt=0;
    cin >> n;

    int i=665;
    //cnt 변수 n과 같아질 때까지 루프 돌기
    while(cnt!=n) {
        i++;
        string str= to_string(i);
        //i 문자열로 반환한 후 666 문자열 찾을 수 있으면
        if(str.find("666")!=string::npos) {
            //cnt 변수 증가
            cnt++;
        }
    }

    cout << i;

    return 0;
}