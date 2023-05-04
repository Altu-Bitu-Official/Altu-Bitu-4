#include <iostream>
#include <deque>

using namespace std;

int count_k;
int n;

struct info {
int power; 
bool is_on = false; 
};

deque<info> belt(n*2);

void rotateBelt(){ //한칸씩 회전
    struct info tmp = belt.back();
    belt.pop_back();
    belt.push_front(tmp);

    if (belt[n-1].is_on){
        belt[n-1].is_on = false;
    }
}

void moveRobot(){ // 로봇 이동
    if(belt[n-2].is_on && belt[n-1].power>0){
        belt[n-2].is_on = false;
        belt[n-1].power--;
       if(belt[n-1].power == 0){
            count_k++;
            }
    }
    for(int i=n-3; i>=0; i--){
        if (belt[i].is_on && !belt[i+1].is_on && (belt[i+1].power>0)){
            belt[i].is_on = false;
            belt[i+1].is_on = true;
            belt[i+1].power--;
            if(belt[i+1].power == 0){
                count_k++;
            }
        }
    }
}

void putRobot(){ //로봇 올리기
    if (belt[0].power > 0){
        belt[0].power--;
        belt[0].is_on = true;
        if(belt[0].power == 0){
            count_k++;
        }
    }
}


int main(){

    int k;
    cin >> n >> k;

    for(int i=0; i<2*n; i++){
        struct info belt_info;
        cin >> belt_info.power;

        belt.push_back(belt_info);
    }

    for(int i=0; i<2*n; i++){
        if(belt[i].power == 0){
            count_k++;
        }
    }
    int count=0;

    while(true){
        count ++;
        rotateBelt();
        moveRobot();
        putRobot();

        if(count_k >=k){
            break;
        }
    }

    cout << count ;


    return 0;
}