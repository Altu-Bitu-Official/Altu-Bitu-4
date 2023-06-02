#include <iostream>
#define MAX 501
#define INF 1e9

using namespace std;

int h[MAX][MAX]; // 키 비교완료 시  1, 아니면 INF

void init()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            h[i][j] = INF; // INF로 초기화
        }
    }
}

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    { // k : 거쳐가는 정점
        for (int i = 1; i <= n; i++)
        { // i : 행(출발 정점)
            for (int j = 1; j <= n; j++)
            { // j : 열(도착 정점)
                h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 시간단축

    int n, m; // n : 학생의 수, m : 비교한 횟수
    cin >> n >> m;

    init();

    for (int i = 0; i < m; i++)
    {
        int a, b;      // 학생의 키를 비교한 결과
        cin >> a >> b; // a번 학생이 b번 학생보다 작음
        h[a][b] = 1;   // 키 비교 체크
    }

    floyd(n);
    int ans = 0; // 자신의 키가 몇 번째인지 알 수 있는 학생 ( = 자기말고 모두와 비교완료된 경우 )

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (h[i][j] != INF || h[j][i] != INF)
            { // i번, j번 학생 키의 대소관계를 아는 경우
                cnt++;
            }
        }
        if (cnt == n - 1) // 자기를 제외한 모든 사람과의 비교가 완료된 경우
            ans++;        // ans ++
    }
    cout << ans;
    return 0;
}