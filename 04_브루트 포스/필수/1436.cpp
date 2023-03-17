#include <iostream>
#include <string>

using namespace std;

int findMovie(int &n) {
    int cnt, ans = 666;
    string six = "666";
    while(true) {
        string str = to_string(ans);
        for(int i = 0; i < str.length() - 2; i++) {
            if(str.substr(i, 3) == "666") { // 문자열에 666이 있으면
                if(++cnt == n) { // cnt 증가, 증가된 cnt가 찾던 수면
                    return ans;  // 결과 반환
                }
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