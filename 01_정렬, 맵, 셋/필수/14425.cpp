#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    int m;
    int ans = 0;
    set<string> s; 
    vector<string> v;   
    //입력
    cin >> n >> m;
    for(int i=0; i<n; i++){      //집합
        string str;
        cin >> str;
        s.insert(str);
    }
    while(m--)      //검사해야하는 문자열
    {
        string str;
        cin >> str;
        if(s.find(str) != s.end()){     //입력받은 문자열이 set에 존재하는지 검사
            ans++;
        }
        //찾은 문자열의 개수가 집합 내 원소의 개수를 초과하면 (더 검사할 필요가 없으니) 멈추기
        if(ans > n)
            break;
    }
    cout << ans;
}