// 분해합

#include <iostream>
#include <string>

using namespace std;

int main()
{   
    int n, ans = 0;
    cin >> n;
    
    for (int i=1; i<n; i++){
        string s = to_string(i);
        int sum = i;
        for (int j = 0; j<s.size(); j++)
            sum += s[j] - '0';
        if (sum == n){
            ans = i;
            break;
        }
    }
    cout << ans;
}