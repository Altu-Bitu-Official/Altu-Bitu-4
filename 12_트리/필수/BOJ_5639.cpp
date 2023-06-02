#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void postOrder(int start, int end, vector<int> &v)
{
    if (start >= end) // start >= end이면 break
    {
        return;
    }
    int idx = start + 1; // start보다 커지면 좌측 자식노드로

    while (idx < end)
    {
        if (v[start] < v[idx])
        { // v[start] < v[idx] 될 때까지 idx값을 늘려준다.
            break;
        }
        idx++;
    }
    postOrder(start + 1, idx, v); // 좌측 자식노드에 대해 재귀적으로 함수 호출
    postOrder(idx, end, v);       // 우측 자식노드에 대해 재귀적으로 함수 호출
    cout << v[start] << "\n";
}

int main()
{
    int n;
    ios::sync_with_stdio(false); // 시간단축
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> n)
    {
        arr.push_back(n); // n을 사용자입력 받아서 arr배열에 push
    }
    postOrder(0, arr.size(), arr);

    return 0;
}
