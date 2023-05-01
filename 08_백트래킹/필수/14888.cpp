#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> nums(11); //숫자 입력 받을 벡터 ( 갯수 최대 11개 )
int ops[4]; //연산자 입력받을 배열
int MIN = 1.0e+9; //비교를 위해 최솟값으로 될 수 있는 가장 큰 값 넣어줌
int MAX =-1.0e+9; //비교를 위해 최댓값으로 될 수 있는 가장 작은 값 넣어줌

void backTrack(int value,int cnt){

    if(cnt == n-1){ //cnt가 n-1일 때 == 끝까지 돌았을 때 탈출
        if(value >MAX){ // 저장된 MAX값과 비교하여 더 크면 갱신
            MAX = value;
        }
        if(value <MIN){ //저장된 MIN값과 비교하여 더 작으면 갱신
            MIN = value;
        }
        return;
    }

        if (ops[0] != 0) {
            ops[0] -= 1; //연산자 사용했으므로 -1
            backTrack(value + nums[cnt + 1], cnt + 1);
            ops[0] += 1; //다른 호출된 함수들에서 해당 연산자 사용할 수 있게 다시 +1

        }
        if (ops[1] != 0) {
            ops[1] -= 1;
            backTrack(value - nums[cnt + 1], cnt + 1);
            ops[1] += 1;

        }
        if (ops[2] != 0) {
            ops[2] -= 1;
            backTrack(value * nums[cnt + 1], cnt + 1);
            ops[2] += 1;
        }
        if (ops[3] != 0) {
            ops[3] -= 1;
            backTrack(value / nums[cnt + 1], cnt + 1);
            ops[3] += 1;

        }

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
for(int i=0;i<4;i++){
    cin >>ops[i];
}

backTrack(nums[0],0);


cout << MAX <<"\n"<<MIN;


    return 0;
}
