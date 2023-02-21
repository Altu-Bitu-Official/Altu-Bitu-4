#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    int m;
    set<string> s;
    vector<string> v;
    //입력
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    for(int i=0; i<m; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    //검사
    int ans = 0;
    for(int i = 0; i<m; i++){
        if(s.find(v[i]) != s.end()){   //vector 내의 값이 집합에 있으면
            ans++;
        }
        //찾은 문자열의 개수가 집합 내 원소의 개수를 초과하면 (더 검사할 필요가 없으니) 멈추기
        if(ans > n)
            break;
    }
    cout << ans;
}