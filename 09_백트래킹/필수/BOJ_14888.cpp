#include <iostream>
#include <vector>

using namespace std;
vector<int> num(11);
vector<int> oper(4);
int minn = 1000000001;//https://cryptosalamander.tistory.com/60에서 min과 max를 각각 최대값과 최소값으로 설정해 두고, 점차 비교해 나가는 방법을 참고하였습니다.
int maxx = -1000000001;

void sol(int val, int count, int n){
    if(count==n){
        if(val>maxx){
            maxx=val;
        }
        if(val<minn){
            minn=val;
        }
        return;
    }
    else{
        for(int i=0;i<4;i++){
            if(oper[i]>0){
                oper[i]--;
                if(i==0){
                    sol(val+num[count],count+1,n);
                }
                else if(i==1){
                    sol(val-num[count],count+1,n);
                }
                
                else if(i==2){
                    sol(val*num[count],count+1,n);
                }
                
                else{
                    sol(val/num[count],count+1,n);
                }
                oper[i]++;
                }
    }
            }
            return;
        }
    
    

int main(){
    int n;
    cin >> n;
    
    
    //연산할 수 입력
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    //연산자 개수 입력
    for(int i=0;i<4;i++){
        cin >> oper[i];
    }
    sol(num[0],1,n);
    cout<<maxx<<'\n';
    cout << minn;
    return 0;

}