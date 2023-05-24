#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int MAX = 2000000000;

ci mixLiquid(vector<int> &liquid, int left, int right)
{
    int min_value = abs(liquid[left] + liquid[right]);
    ci ans = {liquid[left], liquid[right]};

    while (left < right)
    {
        int value = liquid[left] + liquid[right];
        if (abs(value) < min_value)
        {
            min_value = abs(value);
            ans = {liquid[left], liquid[right]};
        }
        if (value < 0)
        { // 현재 값이 0보다 작다면 더 큰 값을 만들어야 함 -> lef++
            left++;
        }
        else if (value > 0)
        { // 현재 값이 0보다 크다면 더 작은 값을 만들어야 함 -> right--
            right--;
        }
        else
        { // 현재 값이 0이면 이보다 더 0보다 가까운 값은 존재하지 않으므로 탐색 종료
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> liquid;
    // 입력
    cin >> n;
    liquid.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }
    // 연산
    sort(liquid.begin(), liquid.end());
    ci ans = mixLiquid(liquid, 0, n - 1);

    // 출력
    cout << ans.first << " " << ans.second;
    return 0;
}
