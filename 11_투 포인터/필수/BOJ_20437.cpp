#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;  //
const int MAX_ALPHA = 26; // 알파벳 개수

/**문자를 k개 포함하는 가장 짧은 문자열과 가장 긴 문자열의 쌍 구하기*/
ci solution(string w, int k) {
    vector<vector<int>> char_idx(MAX_ALPHA);    //알파벳별 인덱스를 저장하는 벡터
    int min_len = w.size(); // 가장 짧은 문자열 길이 초기화
    int max_len = -1;       // 가장 긴 문자열 길이 초기화

    for (int i = 0; i < w.size(); i++) {    //w 전체를 순회
        char_idx[w[i] - 'a'].push_back(i);  // 문자의 인덱스 저장
    }
    
    for (int i = 0; i < MAX_ALPHA; i++) {   // 각 문자를 포함하는 문자열 확인
        if (char_idx[i].size() < k) { // 해당 알파벳이 k번 이상 등장하지 않으면 탐색 X
            continue;
        }
        int left = 0, right = k - 1; // 포인터 초기화 : 알파벳이 등장하는 첫번째 인덱스와 k-1번째 인덱스를 저장.
        while (right < char_idx[i].size()) {    //right이 등장 인덱스의 범위를 넘어서지 않는 선에서 탐색
            int tmp_len = char_idx[i][right] - char_idx[i][left] + 1;   //첫 문자와 끝 문자가 같은 알파벳이고, 문자열에 그 알파벳이 k번 등장하는 문자열의 길이 계산 -> 인덱스 간 거리 구하기
            min_len = min(min_len, tmp_len);    //최소 길이 갱신
            max_len = max(max_len, tmp_len);    //최대 길이 갱신
            left++; // 윈도우 이동
            right++;
        }
    }
    return {min_len, max_len};  //최소 길이와 최대 길이를 pair<int, int> 형태로 리턴
}
/**[백준 20437: 문자열 게임2]
 * 1. 각 알파벳의 위치 인덱스를 char_idx에 저장
 * 2. 윈도우의 크기를 k로 설정하고 윈도우를 오른쪽으로 이동시키며
 *    가장 짧은 문자열과 가장 긴 문자열 탐색
 *    이때 각 문자열의 길이는 char_idx[i][right] - char_idx[i][left] + 1
*/
int main() {
    int t, k;   //게임 수 t, 알파벳의 등장 횟수 k
    string w;   //문자열 w
    
    // 입력
    cin >> t;

    while (t--) {
        cin >> w >> k;

        // 연산
        ci ans = solution(w, k);

        // 출력
        if (ans.second == -1) {     //가장 긴 연속 문자열이 -1 -> 연속 문자열이 존재하지 않을 때
            cout << -1 << "\n"; //-1 출력
        } else {
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;
}