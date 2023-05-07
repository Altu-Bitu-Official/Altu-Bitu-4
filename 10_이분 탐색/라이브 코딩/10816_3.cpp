// 숫자 카드 2

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n;
    vector<int> an(20000001,0);
    for (int i=0; i<n; i++){
        cin >> x;
        an[x+10000000]++;
    }
    cin >> m;
    while (m--){
        cin >> x;
        cout << an[x+10000000] << ' ';
    }
    return 0;
}