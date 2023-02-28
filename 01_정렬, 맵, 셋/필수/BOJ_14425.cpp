#include <iostream>
#include <set>

using namespace std;

int main() {
    string temp;
    set<string> arr;
    int n, m, cnt = 0;

    cin >> n >> m;

    while (n--) {
        cin >> temp;
        arr.insert(temp);
    }

    while (m--) {
        cin >> temp;
        if (arr.find(temp) != arr.end()) cnt++;
    }

    cout << cnt;
}