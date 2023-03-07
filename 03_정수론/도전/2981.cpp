#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getGcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> getDiff(vector<int> &paper)
{
    vector<int> diff;
    for (int i = 1; i < paper.size(); i++)
    {
        diff.push_back(paper[i] - paper[i - 1]);
    }
    return diff;
}

vector<int> getFactorOfGcd(vector<int> &diff)
{

    // get gcd of all the differences
    int result = diff[0];
    for (int i = 1; i < diff.size(); i++)
    {
        result = getGcd(result, diff[i]);
    }

    vector<int> factors;
    // get factor of the gcd
    int i = 2;
    for (; i < sqrt(result); i++)
    {
        if (result % i == 0)
        {
            factors.push_back(i);
        }
    }

    if (result / i == i - 1)
    {
        i--;
    }

    for (; i >= 1; i--)
    {
        if (result % i == 0)
        {
            factors.push_back(result / i);
        }
    }

    return factors;
}

int main()
{
    int n;
    cin >> n;
    int r;
    vector<int> paper;   // 종이에 적은 수
    vector<int> factors; // 정답
    vector<int> diff;

    while (n--)
    {
        cin >> r;
        paper.push_back(r);
    }

    sort(paper.begin(), paper.end());

    // A is congruent to B modulo n iff n divides A-B
    // 고로 주어진 수들의 차를 저장한 array를 생성
    diff = getDiff(paper);

    // 주어진 diff들의 gcd를 구하고,
    // 해당 gcd의 (2를 제외한) 모든 약수들을 포함한 array를 받음
    factors = getFactorOfGcd(diff);

    // 출력
    for (int n : factors)
    {
        cout << n << ' ';
    }
}