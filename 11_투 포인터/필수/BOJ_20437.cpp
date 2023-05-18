#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int MAX_ALPHA = 26;

ci slidingWindow(string w, int k)
{
    vector<vector<int>> char_idx(MAX_ALPHA); // 26개의 빈 벡터를 갖는 2차원 벡터
    int min_len = w.size(); //일단 w사이즈로 놓기
    int max_len = -1; //일단 -1로 놓기

    for (int i = 0; i < w.size(); i++) // w 문자열의 크기만큼
    {
        char_idx[w[i] - 'a'].push_back(i); // 각 알파벳의 위치 인덱스를 char_idx에 저장
    }

    for (int i = 0; i < MAX_ALPHA; i++) //알파벳 개수만큼
    {
        if (char_idx[i].size() < k) // char_idx[i]의 크기가 k보다 작다면
        {
            continue; // 넘어가기
        }
        int left = 0;  // 왼쪽은 0으로 초기화
        int right = k-1; // 오른쪽은 k-1로 초기화

        while (right < char_idx[i].size()) // right가 각 알파벳의 위치 인덱스의 크기보다 작을 동안
        {
            int tmp_len = char_idx[i][right] - char_idx[i][left] + 1; // 문자열의 길이
            min_len = min(min_len, tmp_len); //min_len 업데이트
            max_len = max(max_len, tmp_len); //max_len 업데이트
            left++; //슬라이딩윈도우
            right++;//같은 방향으로 탐색
        }
    }

    return {min_len, max_len};
}

int main()
{
    int t, k;
    string w;
    cin >> t;
    while (t--)
    {
        cin >> w >> k;
        ci ans = slidingWindow(w, k);
        if (ans.second == -1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return 0;
}