// 분해합

#include <iostream>
#include <string>
#include <algorithm>

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
    int n;
    cin >> n;
    producer(n);
}