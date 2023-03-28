#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    double velocity;
    cin >> n;
    vector<double> v(300000);
    for(int i =0; i < n; i++) {
        cin >> v[i];
    }
    velocity= v[n-1]; //오->왼 탐색
    for(int i = n-2; i >= 0; i--){
        velocity = ceil(velocity/v[i])*v[i];
    }
    cout << ll(velocity) << "\n";
}