//
// Created by LG on 2023-02-21.
//
#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m, cnt;
    set<string> s;
    cin >> n >> m;

    string a;
    for(int i=0; i<n; i++){
        cin >> a;
        s.insert(a);
    }

    for(int i=0; i<m; i++){
        cin >> a;
        if(s.find(a) != s.end())
            cnt++;
    }

    cout << cnt;

}
