// 사과나무
#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    int n, sum = 0, cnt = 0;
    
    cin >> n;
    vector<int> tree(n);
    
    for (int i=0; i<n; i++){
        cin >> tree[i];
        sum += tree[i]; // 나무 높이의 총합
        cnt += (tree[i] / 2); // 2만큼 성장시키는 물뿌리개 횟수
    }
    
    if (sum % 3) // 총합이 3의 배수가 아니면
        cout << "NO";
    else if (cnt >= sum-2*cnt) // 물뿌리개 2가 필요한 횟수가 1보다 많으면
        cout << "YES";
    else
        cout << "NO";
    return 0;
}