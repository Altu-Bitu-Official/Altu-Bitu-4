#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int n, m;
    int ans = 0;
    string input;
    set<string> s;
    //입력
    cin >> n >> m;
    for (int i=0; i < n; i++){ //문자열 집합 S 입력
        cin >> input;
        s.insert(input);
    }
    //연산 및 출력
    for (int i=0; i<m; i++){ //m개의 문자열 중 몇개가 집합 S에 포함되어 있는지 연산
        cin >> input;
        ans += s.count(input);
    }
    cout << ans;

    return 0;
}