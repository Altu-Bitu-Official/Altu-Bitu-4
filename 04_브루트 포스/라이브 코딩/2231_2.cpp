// 분해합

#include <iostream>
#include <string>

using namespace std;

int producer(int n){
    int n_len = to_string(n).size(); 
    for (int i = max(n-9*n_len,1); i<n; i++){
        int sum = i;
        string is = to_string(i);
        for (int j = 0; j<is.size(); j++){
            sum += (is[j] - '0');
        }
        if (sum == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

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