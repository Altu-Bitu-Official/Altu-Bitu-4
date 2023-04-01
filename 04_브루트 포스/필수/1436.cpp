#include <iostream>
#include <string>

using namespace std;

int findMovie(int n) {
    int cnt, ans = 666;
    string six = "666";
    while(true) {
        if(to_string(ans).find(six) != string::npos) { // 문자열에 666이 있으면
            if(++cnt == n) { // cnt 증가, 증가된 cnt가 찾던 수면
                return ans;  // 결과 반환
            }
        }
        ans++; // 다음 수로 넘어감
    }
}

int main() {
    int n;
    cin >> n;

    cout << findMovie(n);

    return 0;
}