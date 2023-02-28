#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> circle;

    // 1번부터 n번까지 입력
    for (int i = 0; i < n; i++)
    {
        circle.push_back(i + 1);
    }

    // k번째에 도달하려면 k-1번 건너 뛰어야되므로 decrement해줌
    k--;

    // 시작 index
    int i = 0;
    cout << '<';

    // 출력용: 처음 원소 앞에는 comma가 없으므로 빈 string
    const char *padding = "";

    while (!circle.empty())
    {
        i = (i + k) % circle.size();
        cout << padding << circle[i];
        padding = ", "; // 출력용 comma
        circle.erase(remove(circle.begin(), circle.end(), circle[i]), circle.end());
    }
    cout << '>';
}