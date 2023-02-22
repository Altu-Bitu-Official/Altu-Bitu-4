#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;

    string name, cloth;

    while(t--){
        cin >> n;   //해빈이가 가진 의상 수
        map<string, int> m;     //map 초기화
        for(int i=0; i<n; i++){
            cin >> name >> cloth;
            if(m.find(cloth) != m.end())    //map에 옷이 존재하면
                m[cloth]++;
            else   
                m.insert({cloth, 1});
        }
        //계산
        int ans = 1;
        for(auto i : m){
            ans *= i.second + 1;        //옷을 안 입는 경우까지 포함해서 +1
        }
        ans--;
        cout << ans << '\n';
    }
}