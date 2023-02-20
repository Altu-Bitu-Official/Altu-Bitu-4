#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, size, total;
    string name, part;
    map<string, int> arr;
    cin >> n;

    while (n--) {
        arr.clear();
        total = 1;
        cin >> m;
        while (m--) {
            cin >> name >> part;
            arr[part]++;
        }

        for (auto iter = arr.begin() ; iter != arr.end(); iter++) {
            total *= (iter->second+1);
        }
        cout << total -1 << "\n";
    }
}