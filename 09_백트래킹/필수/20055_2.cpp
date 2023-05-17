// 컨베이어 벨트 위의 로봇
#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<pair<int, bool>> a;

// 로봇들을 앞으로 이동
void forward(){
    a[n-1].second = false; // 로봇을 내림
    
    for (int i = n-2; i>=0; i--){
        if (a[i].second && a[i+1].first && !(a[i+1].second)){ // 앞 칸의 내구도가 0이 아니고 로봇이 없으면
            a[i+1].second = true;
            a[i+1].first--;
            a[i].second = false;
            
            if (a[i+1].first == 0) // 내구도가 0이 되면
                cnt++;
        }
    }
    a[n-1].second = false; // 로봇을 내림
}
// 로봇을 올림
void put_robot(){
    if (a[0].first > 0){ // 올리는 위치에 내구도가 0보다 크면
        a[0].first--;
        a[0].second = true;
        
        if (a[0].first == 0){ // 내구도가 0이 되면
            cnt++;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k, x;
    cin >> n >> k;
    
    for (int i = 0; i < 2 * n; i++) {
        cin >> x;
        a.push_back(make_pair(x, false));
    }

    int num = 0;
    while (cnt < k){
        num++;
        // 컨베이너 벨트 회전
        a.insert(a.begin(), a[2*n-1]); 
        a.pop_back();
        
        forward();
        put_robot();
    }

    cout << num << "\n";

    return 0;
}
