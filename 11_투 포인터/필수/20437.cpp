#include<iostream>
#include<vector>
#include<string>

using namespace std;

//모든 경우의 수를 탐색할 경우 시간 초과가 뜸
//->시간단축을 위해 str의 알파벳 빈도수를 저장하고 그중 k개 이상인 것들만 연산

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string w;
        int k;
        cin >> w;
        cin >> k;

        // str 의 알파벳 문자별로 등장 빈도수 저장
        vector<int> count(26);
        for (int i = 0; i < w.length(); i++) {
            ++count[w[i] - 'a'];
        }

        int min_length = 10000;
        int max_length = -1;
        for (int i = 0; i < w.length(); ++i) {
           
            if (count[w[i] - 'a'] < k) { // k개 이하인 문자는 패스
                continue;
            }

            int cnt = 0;
            for (int j = i; j < w.length(); ++j) {  
                if (w[i] == w[j]) { // 같은 문자열을 찾으면 cnt++
                    ++cnt;
                }
                if (cnt == k) { //동일 문자를 k개 찾으면 업데이트
                    min_length = min(min_length, j - i + 1);
                    max_length = max(max_length, j - i + 1);
                    break; //찾았으니 for문 탈출 후 k개 이상 등장하는 다른 문자를 탐색
                }
            }
        }

        if (min_length == 10000 || max_length == -1) {//문자열을 찾지 못하는 경우->-1
            cout << -1 << "\n";
        }
        else {
            cout << min_length << " " << max_length << "\n"; //문자열을 찾은 경우->출력
        }
    }
    return 0;
}