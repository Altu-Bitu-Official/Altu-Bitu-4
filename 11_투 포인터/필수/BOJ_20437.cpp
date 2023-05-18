#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

typedef pair<int,int> ci;
int  cnt[26];

ci slidingWindow(string w, int k)
{
    int left = 0, right = 0;
    int size = w.size();

    int short_length = 100001, long_length = 0;
    while (right < size)
    {
        cnt[w[right]-'a']++;
        while(cnt[w[right]-'a'] == k)
        {
            cnt[w[left]-'a']--;
            left++;
            short_length = min(short_length, right -left+1);
            long_length = max(long_length,right-left+1);
        }
        right++;
    }
    
    return {short_length, long_length};
}

int main()
{
    int t,k;
    string w;
    cin >> t;
    while (t--)
    {
        cin >> w >> k;
        
        ci ans = slidingWindow(w, k);
        if (ans.second == 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}