#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(void) {
    int num, k;
    cin >> num >> k;
    vector<char> adj(num);
    for (int i = 0; i < num; i++) adj[i] = '?';
    int now = 0;
    for (int i = 0; i < k; i++) {
        int cnt;
        char value;
        cin >> cnt >> value;
        cnt %= num;
        now -= cnt;
        if (now < 0) now += num;
        if (adj[now] != '?' && adj[now] != value) {
            cout << "!\n";
            return 0;
        }
        else adj[now] = value;
    }
    for (int i = 0; i < num-1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (adj[i] != '?' && adj[i] == adj[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }
    int rot = num;
    while (rot--) {
        cout << adj[now];
        now++;
        if (now == num) now = 0;
    }
    cout << '\n';
    return 0;
}