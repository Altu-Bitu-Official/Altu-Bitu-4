#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> nums(11); //숫자 입력 받을 벡터 ( 갯수 최대 11개 )
int ops[4]; //연산자 입력받을 배열
int min_cost = 1.0e+9; //비교를 위해 최솟값으로 될 수 있는 가장 큰 값 넣어줌
int max_cost =-1.0e+9; //비교를 위해 최댓값으로 될 수 있는 가장 작은 값 넣어줌
const int ADD = 0;
const int SUB = 1;
const int MUL =2;
const int DIV =3;
void backTrack(int value,int cnt){

    if(cnt == n-1){ //cnt가 n-1일 때 == 끝까지 돌았을 때 탈출
      // 저장된 max_cost 값과 비교하여 더 크면 갱신
        max_cost = max(value,max_cost);
        //저장된 min_cost 값과 비교하여 더 작으면 갱신
        min_cost = min(value,min_cost);
        return;
    }
for( int i=0;i<4;i++) {
    if(ops[i]==0){
        continue;
    }
    ops[i]--;//연산자 사용했으므로 -1

    switch (i) {
        case ADD:
            backTrack(value + nums[cnt + 1], cnt + 1);
            break;
        case SUB:
            backTrack(value - nums[cnt + 1], cnt + 1);
            break;
        case MUL:
            backTrack(value * nums[cnt + 1], cnt + 1);
            break;
        case DIV:
            backTrack(value / nums[cnt + 1], cnt + 1);
            break;
    }
    ops[i]++; //다른 호출된 함수들에서 해당 연산자 사용할 수 있게 다시 +1
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


cout << max_cost <<"\n"<<min_cost;

    return 0;
}
