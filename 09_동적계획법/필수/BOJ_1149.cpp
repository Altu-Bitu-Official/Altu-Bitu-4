#include <iostream>
using namespace std;

int house[1001][3]; // 0-red 1-green 2-blue

int main()
{
    ios_base::sync_with_stdio(false); // 시간단축
    cin.tie(NULL);
    cout.tie(NULL);

    // 집의 수 N
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int red, blue, green;
        cin >> red >> green >> blue; // 각각의 비용 사용자 정의

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + red;
        house[i][1] = min(house[i - 1][2], house[i - 1][0]) + green;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + blue;
    }

    cout << min(house[N][0], min(house[N][1], house[N][2]));

    return 0;
}