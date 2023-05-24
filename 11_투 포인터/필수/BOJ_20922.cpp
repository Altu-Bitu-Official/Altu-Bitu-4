#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int cnt[100001]; // 수의 개수를 세어주는 cnt배열
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // 사용자 입력
        cnt[arr[i]]++; // 배열 업데이트
        // arr[i]의 빈도수가 k보다 큰 경우 인덱스 증가
        while (cnt[arr[i]] > k)
        {
            cnt[arr[start++]]--;
        }
        ans = max(ans, i - start + 1);
    }
    cout << ans;

    return 0;
}