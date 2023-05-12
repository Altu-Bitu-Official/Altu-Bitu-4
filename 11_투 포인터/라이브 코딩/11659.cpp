// 구간 합 구하기 4

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m, i, j;
    cin >> n >> m;
    vector<int> s(n+1, 0);
    
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] += s[i-1];
    }
    while (m--){
        cin >> i >> j;
        cout << (s[j] - s[i-1]) << '\n';
    }
    return 0;
}