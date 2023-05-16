#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> solution(const string& str, int k) {

    vector<int> alphabet(26, 0);

    for (int j = 0; j < str.length(); j++) {
        alphabet[str[j] - 'a']++; // 알파벳 수 세기
    }

    int minlen = INT_MAX, maxlen = -1;

    for (int j = 0; j < str.length(); j++) {

        if (alphabet[str[j] - 'a'] < k) continue; // k 미만에 대해서는 패스

        int count = 1;
        for (int l = j + 1; l < str.length(); l++) {
            if (str[j] == str[l]) {
                count++;
            }
            if (count == k) { // 업데이트
                minlen = min(minlen, l - j + 1);
                maxlen = max(maxlen, l - j + 1);
                break;
            }
        }
    }
    return make_pair(minlen, maxlen);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        int k;
        cin >> str >> k;

        if (k == 1) {
            cout << "1 1\n";
            continue;
        }

        pair<int, int> result = solution(str, k);
        if (result.first == INT_MAX || result.second == -1) {
            cout << "-1\n";
        }
        else {
            cout << result.first << " " << result.second << "\n";
        }
    }
    return 0;
}
