#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, start, end;
    int last = 0, cnt = 0;
    cin >> n;

    vector<pair<int, int> > times;

    for(int i=0; i<n; i++) {
        cin >> start >> end;
        times.push_back(make_pair(end, start));
    }

    sort(times.begin(), times.end());

    for(int i=0; i<n; i++) {
        if(times[i].second>=last) {
            cnt++;
            last=times[i].first;
        }
    }

    cout << cnt;

    return 0;
}