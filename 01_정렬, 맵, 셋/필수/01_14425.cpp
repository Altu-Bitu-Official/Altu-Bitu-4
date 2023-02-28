#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m, rslt=0;
    string s, t;
    map<string, int> map;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> s;
        map[s]=1;
    }
    for(int i=0; i<m; i++){
        cin >> t;
        if(map[t]) rslt += 1;
    }

    cout << rslt;

    return 0;
}