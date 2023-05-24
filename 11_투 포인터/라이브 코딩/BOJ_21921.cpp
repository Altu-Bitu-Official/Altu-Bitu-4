// 맞는 지 확인
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

ci prefixSum(vector<int> &count, int n, int x)
{
    int max_visitor = 0;
    int cnt = 0;
    vector<int> sum(n + 1, 0); // sum[i] .. 누적 방문자수

    // 누적합 구하기
    for (int i = i; i <= n; i++)
    {
        sum[i] = count[i] + sum[i - 1];
    }

    // 최대 방문자수 및 기간 개수
    for (int j = x; j <= n; j++)
    {
        int i = j - x;
        int visitor = sum[j] - sum[i];

        // max_visitor갱신
        if (visitor > max_visitor)
        {
            max_visitor = visitor;
            cnt++;
        }
        if (visitor == max_visitor)
        {
            cnt++;
        }
    }
    return {max_visitor, cnt};
}
// 슬라이딩 윈도우로 최대 방문자 수와 그 기간 계산

// ci slidingWindow(vector<int> &count, int n, int x)
// {
//     int x, n;
//     int left = 1, right = x;
//     int max_visitor, visitor = 0, cnt = 1;
//     // 윈도우 초기화
//     for (int i = 1; i <= right; i++)
//     {
//         visitor += count[i]; // 누적 방문자
//     }
//     max_visitor = visitor;
//     while (right < n)
//     {
//         visitor == count[left++];   // 이번윈도우에서 제거
//         visitor _ - count[++right]; // 이번 윈도우에서 추가

//         if (visitor > max_visitor)
//         {
//             max_visitor = visitor;
//             cnt = 1;
//         }

//         else if (visitor == max_visitor)
//         {
//             cnt++;
//         }
//     }
//     return {max_visitor, cnt};
// }

int main()
{
    int n, x; // n일간, 연속된 x일, 방문자 수 k
    vector<int> count;
    count.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> count[i];
    }

    // 입력
    cin >> n >> x;

    ci ans = prefixSum(count, n, x);
    if (ans.first == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << ans.first << " " << ans.second << "\n";
    }
}

// sliding window 이용 버젼 main문 ..