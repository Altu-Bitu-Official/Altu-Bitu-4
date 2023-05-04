#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> planet (n);

    for(int i=0; i<n; i++){
        cin >> planet[i];
    }

    long long speed = planet[n-1]; 

    for(int i=n-1; i>0; i--){
        if(planet[i-1] >= speed){
            speed = planet[i-1];
        }
        else{ //이전 행성에 필요한 속도가 그 뒤 행성에서 필요한 속도보다 작을 경우
            if(speed%planet[i-1] == 0){
                continue;
            }
            long long a = speed/planet[i-1] + 1; 
            speed = planet[i-1] * a;
        }
    }

    cout << speed;

    return 0;
}