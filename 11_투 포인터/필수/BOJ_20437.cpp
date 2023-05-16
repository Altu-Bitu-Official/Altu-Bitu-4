#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

ci calNum(string w, int k)
{
    int ans_max = 0;
    int ans_min = w.length();
    vector<vector<int>> alpha(26); // 각 알파벳의 인덱스를 저장할 이중 vector

    for (int i = 0; i < w.length(); i++)
    {
        alpha[w[i] - 'a'].push_back(i); // 각 알파벳이 사용되는 인덱스의 값을 이중벡터로 저장
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i].size() < k)
        {
            continue; // 만약 k보다 작으면 스루
        }

        int left = 0, right = k - 1;
        while (right < alpha[i].size())
        {
            int temp = alpha[i][right] - alpha[i][left] + 1;
            ans_min = min(ans_min, temp); // min갱신
            ans_max = max(ans_max, temp); // max갱신
            left++;
            right++;
        }
    }
    return {ans_min, ans_max};
}

int main()
{

    ios_base ::sync_with_stdio(0); // 시간단축
    cin.tie(0);
    cout.tie(0);

    int t;    // 문자열 게임의 수
    string w; // 문자열 w
    int k;    // w안에서 반복되야하는 알파벳 개수 k

    // 입력
    cin >> t;
    while (t--) // t번 반복
    {
        cin >> w;
        cin >> k;
        ci result = calNum(w, k);
        if (result.first == w.length() && result.second == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << calNum(w, k).first << " " << calNum(w, k).second << "\n";
        }
    }
}