// 소수상근수

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void sosu(vector<int> &s, int n){
    for (int i=2; i*i<=n; i++)
        if (s[i])
            for (int j=i*i; j<=n; j++)
                if (j%i == 0)
                    s[j] = 0;
}
int square_sum(int n){
    int ssum = 0;
    while (n>0){
        ssum += (n%10)*(n%10);
        n /= 10;
    }
    return ssum;
}
int sanggeunsu(int n){
    set<int> s;
    int final = -1;
    while (square_sum(n) != 1){
        if (s.find(square_sum(n)) != s.end())
            return 0;
        else
            s.insert(square_sum(n));
        n = square_sum(n);
    }
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> s(n+1, 1);
    sosu(s, n);
    
    for (int i=2; i<=n; i++)
        if (s[i] && sanggeunsu(i))
            cout << i << '\n';
    return 0;
}
