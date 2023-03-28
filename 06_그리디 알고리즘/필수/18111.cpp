#include "iostream"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;

void getAnswer(map<int, int> &house, vector<int> keys, int &time, int &height, int b, int top) {
    time = 2147483647;  // int 최대값으로 초기화

    for(int i=0; i<=top; i++){
        int temp_time=0;    // 임시 시간
        int temp_b= b;      // 인벤토리 블록수
        for(int j=0; j<keys.size(); j++){   // i = 땅을 고를 기준이 되는 높이 (0부터 블록 최대 높이까지 모든 경우의 수 고려)
            if(i > keys[j]){    // i가 key[j]보다 크다면 블록을 추가해야하므로,
                temp_time += (i - keys[j]) * 1 * house[keys[j]];    // 시간 += (높이 차) * (작업에 걸리는 시간) * (작업해야하는 자리 개수)
            }
            else if(i < keys[j]){   // i가 key[j]보다 작다면 땅을 제거해야하므로,
                temp_time += (keys[j] - i) * 2 * house[keys[j]];    // 위와 똑같다!
            }
        }
        if(temp_time == time && height < i){    // 작업 시간이 같을 경우 높이가 큰 방법을 채택
            time = temp_time;
            height = i;
        }
        else if(temp_time < time){  // 작업 시간이 적은 방법으로 갱신
            time = temp_time;
            height = i;
        }
    }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b;
    int time = 0, height = 0, top = 0; // 시간, 땅의 높이, 높이의 최댓값
    int tmp;

    cin >> n >> m >> b;
    map<int, int> house;    // key: 초기 집터 내에 존재하는 땅의 높이들 value: key의 빈도.  예를 들어 1 1 1 6인 집터가 있을 때, {1, 3} {6, 1} 값이 map에 저장된다.
    vector<int> keys;       // house에 접근하기 위한 key vector

    // top = (인벤토리의 있는 블록 수 + 집터에 있는 모든 블록 수) / (n * m)
    top += b;

    // 입력
    for (int i = 0; i < n * m; i++) {
        cin >> tmp;
        // 입력값이 house에 있다면, 입력값의 value 값을 1 더해준다.
        if (house.find(tmp) == house.end()) {
            house[tmp] = 1;
            keys.push_back(tmp);    // 나중에 house에 접근하기 위해 vector에 입력값을 넣어줌.
            top += tmp;
        }
        else {  // 입력값이 house에 있다면, 입력값의 value 값을 1 더해준다.
            house[tmp]++;
            top += tmp;
        }
    }
    top /= (n*m);   // top값 구해주기
    getAnswer(house, keys, time, height, b, top);   //연산

    cout << time << " " << height;  //출력
}