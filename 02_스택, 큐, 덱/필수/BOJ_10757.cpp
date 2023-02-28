#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum;
int a_arr[10001], b_arr[10001];
string a, b;
vector<int> res;

int main()
{
    cin >> a >> b;

    if (a.size() < b.size()) // a와 b 중 b 크기가 더 클때 a와 b를 swap함수를 이용해 바꿔준다 (긴 수 + 짧은 수)로 생각하기위해
    {
        swap(a, b);
    }

    for (int i = 0; i < a.size(); i++)
        a_arr[i + 1] = a[i] - '0';

    for (int i = 0; i < b.size(); i++)
        b_arr[i + 1 + (a.size() - b.size())] = b[i] - '0'; // a_arr[1]과 b_arr[1]을 더했을때 10이 넘어서 a_arr[0]이 존재할 수 있으므로 a_arr[1]부터 시작하게 만든다.

    for (int i = a.size(); i > 0; i--)
    {
        sum = a_arr[i] + b_arr[i];
        if (sum >= 10)
        {
            a_arr[i - 1]++; // 인덱스를 하나 감소시킨 배열에 1을 증가시킨다.
            sum -= 10;
        }
        res.push_back(sum);
    }

    if (a_arr[0])  // a_arr[1]과 b_arr[1]을 더했을때 10이 넘을 경우
        cout << 1; // 1을 출력하도록 한다.

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    return 0;
}