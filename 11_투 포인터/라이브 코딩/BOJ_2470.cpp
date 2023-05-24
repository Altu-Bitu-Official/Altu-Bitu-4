// 투포인터Q - 답확인
#include <iostream>
#include <vector>
#include <cmath>     // 절댓값이용
#include <algorithm> // 정렬

using namespace std;
const int MAX = 2000000000; // 20억

typedef pair<int, int> ci;
ci mixliquid(vector<int> &liquid, int n)
{
    sort(liquid.begin(), liquid.end()); // 투포인터를 사용하기 위해서는 무조건 정렬!
    int left = 0, right = n - 1;
    int min = abs(liquid[left] + liquid[right]);
    ci ans = {liquid[left], liquid[right]};

    while (left != right)
    {
        int value = liquid[left] + liquid[right];
        if (abs(value) < min)
        {
            min = abs(value);
            ans = {liquid[left], liquid[right]};
        }

        // 현재 값이 0보다 작다면  => left를 오른쪽으로
        if (value < 0)
        {
            left++;
        }

        // 현재 값이 0보다 크다면
        if (value > 0)
        {
            right--;
        }
        if (value == 0)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio;
    int n; // 숫자를 키우려면 left를 오른쪽으로, 줄이려면 right를 왼쪽으로
    vector<int> liquid;

    // 입력
    cin >> n;
    liquid.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }
    // 연산

    // 출력
}