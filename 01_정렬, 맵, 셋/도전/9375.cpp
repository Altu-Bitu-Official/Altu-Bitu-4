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

        while(n--){
            cin >> name >> cloth;
            // //map에 옷이 존재하면 +1, 존재하지 않으면 옷을 추가한 뒤 +1
            m[cloth]++;       
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