#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int CheckHeightTime(int &height_get, int b, int n, int m, vector<int> &height)
{
    int b_copy = b;
    int time_ground = 0;
    for (int i = 0; i < m * n; i++)
    {
        b = b - (height_get - height[i]);
        if (height[i] <= height_get)
        {

            time_ground = time_ground + height_get - height[i];
        }
        else
        {
            time_ground = time_ground + (height[i] - height_get) * 2;
        }
    }
    if (b < 0)
    {
        int k = (-b) / (m * n);
        height_get -= (k + 1);
        time_ground = CheckHeightTime(height_get, b_copy, n, m, height);
    }
    return time_ground;
}
int main()
{
    int n, m, b;
    cin >> n >> m >> b;
    vector<int> height(m * n);

    for (int i = 0; i < n * m; i++)
    {
        cin >> height[i];
    }
    int max_height = height[0], min_height = height[0];

    for (int i = 0; i < m * n; i++)
    {
        if (max_height < height[i])
        {
            max_height = height[i];
        }
        if (min_height > height[i])
        {
            min_height = height[i];
        }
    }
    // 블럭을 뺴는데는 2초, 더하는 데는 1초
    // 가장 적게 하려면 더하는 것 위주로 해야함

    // 여기에서 단순히 따질 수 없으므로 그냥 벡터에 time 저장해주고 갱신하도록 할 것
    int time_check;
    vector<pair<int, int>> v;
    for (int i = min_height; i <= max_height; i++)
    {
        int height_get = i;
        int time_ground = CheckHeightTime(height_get, b, n, m, height);

        // 여기부터는 그냥 pair벡터로 저장해서 최소시간 최대 높이 for문 돌리기

        v.push_back({time_ground, height_get});
    }
    sort(v.begin(), v.end());
    int height_maximum = v[0].second, time_minimum = v[0].first;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == time_minimum && v[i].second >= height_maximum)
        {
            height_maximum = v[i].second;
        }
    }

    // 최종적으로 b가 음수값이 나오면 그냥 빼주는 걸로 다시 계산할 것
    cout << time_minimum << " " << height_maximum;
    return 0;
}