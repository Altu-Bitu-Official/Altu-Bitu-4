// 맞는지 확인하기
#include <iostream>
#include <vector>
using namespace std;

// 누적합을 계산하는 함수
void calSum(int n, vector<int> &sum)
{

    for (int i = 2; i <= n; i++)
    {
        sum[i] += sum[i - 1];
    }
}

// void calSum2(int n, vector<int> &a) => 또다른 누적합 방식
// {
//     vector<int> sum(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         sum[i] = a[i] + sum[i - 1];
//     }
// }

int sigma(int i, int j, vector<int> &sum)
{
    int result = 0;
    result = sum[j] - sum[i - 1];
    return result;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base ::sync_with_stdio;

    // 입력
    int n, m, i, j; // n개의 수, m번의 연산
    vector<int> sum;

    cin >> n >> m;
    sum.assign(n + 1, 0); // n이라는 인덱스에 접근 -> sum에는 n+1에 접근
    for (int k = 1; k < n + 1; k++)
    {
        cin >> sum[k];
    }

    // 연산
    calSum(n, sum);

    // 출력
    while (n--)
    {
        cin >> i >> j;
        cout << sigma(i, j, sum);
    }
}