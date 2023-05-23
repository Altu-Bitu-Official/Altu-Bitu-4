// 겹치는 건 싫어

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int n, k;
    cin >> n >> k;
    vector<int> a(n,0);
    vector<int> cnt(200001,0); // 원소 포함 개수 
    int start = 0, max_len = 0;
    
    for (int i = 0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++; // 개수 증가
        
        while (cnt[a[i]] > k){ // k개 초과하면
            cnt[a[start++]]--; // start를 옮김
        }
        max_len = max(max_len, i - start + 1); // 최장길이 갱신
    }
    cout << max_len;
    return 0;
}