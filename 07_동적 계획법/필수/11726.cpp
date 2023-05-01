#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    for(int i =2; i<n; i++){
        int a = (v[i-1]+v[i-2])%10007;
        v.push_back(a);
    }

    cout<< v[n-1];

    return 0;
}