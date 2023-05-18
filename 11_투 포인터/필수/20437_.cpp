#include <iostream>
#include <vector>
#include <algorithm>

// 추가제출
//  배울점 :
//  - 예외처리 if else로 깔끔하게 함
//  - 슬라이딩 윈도우 적용하여 2가지 요구사항을 한번에 해결함.
//  - 알파벳 별로 구현함.
//     알파벳별로 인덱스를 모아주고, 그 안에서 윈도우를 이동시킴!!!
//     꼭 주어진 STRING 내부에서 포인터를 사용할 필요가 없다. 필요에 따라 적절히 인풋을 재구성해야한다.

using namespace std;
typedef pair<int, int> ci;
const int MAX_ALPHA = 26; // 알파벳 개수

/**문자를 k개 포함하는 가장 짧은 문자열과 가장 긴 문자열의 쌍 구하기*/
ci solution(string w, int k)
{
    vector<vector<int>> char_idx(MAX_ALPHA); // 알파벳 빈도수를 인덱스로 저장.
    int min_len = w.size();                  // 가장 짧은 문자열 길이 초기화(최대한 큰값이 전체 문자열 길이)
    int max_len = -1;                        // 가장 긴 문자열 길이 초기화(이후 예외처리를 위해 -1로 해둠)

    for (int i = 0; i < w.size(); i++)
    {
        char_idx[w[i] - 'a'].push_back(i); // 문자의 인덱스 저장
    }

    for (int i = 0; i < MAX_ALPHA; i++) // 모든 종류의 알파벳에 관하여
    {                                   // 각 문자를 포함하는 문자열 확인
        if (char_idx[i].size() < k)     // 애초에 몇 개 없는 애들은 살펴보지도 않는다.
        {                               // 해당 알파벳이 k번 이상 등장하지 않으면 탐색 X
            continue;
        }
        int left = 0, right = k - 1;       // 포인터 초기화
        while (right < char_idx[i].size()) // K개 이상 있는 애들에 관하여.
        {
            int tmp_len = char_idx[i][right] - char_idx[i][left] + 1; //
            min_len = min(min_len, tmp_len);                          // 최소길이 갱신
            max_len = max(max_len, tmp_len);                          // 최대길이 갱신
            left++;                                                   // 해당 글자의 인덱스 내부에서
            right++;                                                  // 윈도우를 이동시킨다.
        }
    }
    return {min_len, max_len};
}
/**[백준 20437: 문자열 게임2]
 * 1. 각 알파벳의 위치 인덱스를 char_idx에 저장
 * 2. 윈도우의 크기를 k로 설정하고 윈도우를 오른쪽으로 이동시키며
 *    가장 짧은 문자열과 가장 긴 문자열 탐색
 *    이때 각 문자열의 길이는 char_idx[i][right] - char_idx[i][left] + 1
 */
int main()
{
    int t, k;
    string w;

    // 입력
    cin >> t;

    while (t--)
    {
        cin >> w >> k;

        // 연산
        ci ans = solution(w, k);

        // 출력
        if (ans.second == -1) // 두번째 경우가 없을 경우 예외처리해줌
        {
            cout << -1 << "\n";
        }
        else // 두 케이스 모두 존재하는 정상적인 경우
        {
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;
}