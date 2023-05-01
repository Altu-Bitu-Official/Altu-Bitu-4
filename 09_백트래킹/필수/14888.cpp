#include <iostream>
#include <vector>
using namespace std;
int n;
int num[12];
int op[4];
int mymin = 1000000001;
int mymax = -1000000001;
void backtrack(int result, int cnt){
    //종료 조건: 모두 count했을 때 
    if(cnt == n-1){
        if(result > mymax){
            mymax = result;
        } 
        if(result < mymin){
            mymin = result;
        }
        return;
    }
    
    //i: 연산자 
    for(int i=0; i<4; i++){
        if(op[i]==0){
            //이미 연산자 모두 사용했다면, 사용 불가
            continue;
        }
        //사용하기
        else{
            op[i]--;
            if(i==0){
                backtrack(result+num[cnt+1], cnt+1);
            }
            else if(i==1){
                backtrack(result-num[cnt+1], cnt+1);
            }
            else if(i==2){
                backtrack(result*num[cnt+1], cnt+1);
            }
            else if(i==3){
                backtrack(result/num[cnt+1], cnt+1);
            }
            //반납 
            op[i]++;
        }
    }
    
}

int main()
{
    //입력
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    
    //연산
    backtrack(num[0], 0);
    cout << mymax << endl;
    cout << mymin;
    
    return 0;
}