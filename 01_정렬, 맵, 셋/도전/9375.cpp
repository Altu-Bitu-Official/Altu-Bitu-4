#include <iostream>
#include <map>

using namespace std;

void calc(map<string, int> clothes) {
    map<string, int>::iterator it;

    int sum = 1;

    for (it = clothes.begin(); it != clothes.end(); it++) {
        sum *= (it->second + 1);
    }

    cout << sum -1 <<  "\n";
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        map<string, int> clothes;

        // 입력 및 연산
        while (m--) {
            string name, type;
            cin >> name >> type;
            if (clothes.find(type) != clothes.end()) {
                clothes[type]++;
            } else {
                clothes[type] = 1;
            }
        }
        calc(clothes);
    }
}

