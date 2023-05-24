#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int m, vector<int> &snack)
{
    int left = 1, right = snack[n - 1]; // snack의 인덱스
    int mid;
    int result = 0;

    while (left <= right)
    {
        int cnt = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < n; i++)
        {
            cnt += snack[i] / mid; // mid과자 길이로 나눠줄 수 있는 양
        }
        if (cnt < m) // cnt가 조카의 수보다 적을때
        {
            right = mid - 1; // 과자를 나눠줄 수 없음
        }
        else
        { // 과자를 나눠줄 수 있을 때
            left = mid + 1;
            result = mid;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;                // m명의 조카,  n개의 과자
    cin >> m >> n;           // 사용자 정의
    vector<int> snack(n, 0); // n개의 과자의 길이 (0으로 초기화)

    for (int i = 0; i < n; i++)
    {
        cin >> snack[i];
    }

    sort(snack.begin(), snack.end()); // 정렬

    cout << binarySearch(n, m, snack) << endl;

    return 0;
}