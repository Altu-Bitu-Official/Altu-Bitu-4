#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int  n, s;
    string input, p1, p2; 
    map<string, string> m;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s; j++) // 입력
        {
            cin >> p1 >> p2;
            m.insert(make_pair(p1, p2));
        }
        map<string, int> count_num;
        for (auto iter = m.begin(); iter != m.end(); iter
            ++) // 종류별 맵 생성하기
        {
            string key = (*iter).second;
            count_num.insert(make_pair(key, 0));
        }
        for (auto iter = m.begin(); iter != m.end(); iter
            ++) // 맵에 원소의 숫자 삽입하기
        {
            string key = (*iter).second;
            count_num[key]++;
        }
        int sum = 1;
        for (auto iter = count_num.begin(); iter != count_num.end(); iter
            ++)
            sum *= ((*iter).second + 1);
        sum--;
        cout << sum << "\n";
        m.clear();
    }

    return 0;
}