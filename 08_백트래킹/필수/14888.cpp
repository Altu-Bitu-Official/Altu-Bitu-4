#include <iostream>

using namespace std;

int Max = -1000000000;
int Min = 1000000000;
int n;
int A[11];
int Operator[4];
int result_save;

void backtrack(int result, int cnt){
    if(cnt == n-1){ 
        if(result > Max){
            Max = result;
        }
        if(result < Min){
            Min = result;
        }
        return;
    }

    for(int i=0; i<4; i++){

        if (Operator[i] == 0){ //남은 연산자가 없으면 다른 연산자 사용
            continue;
        }
        Operator[i]--;

      int result_save;

        if(i==0){
            result_save = result+A[cnt+1];
        }
        else if (i==1){
            result_save = result-A[cnt+1];
          
        }
        else if (i==2){
            result_save = result*A[cnt+1];
          
        }
        else{
            result_save = result/A[cnt+1];
          
        }
        backtrack(result_save, cnt+1);

        Operator[i] ++;
    }
}

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<4; i++){
        cin >> Operator[i];
    }

    backtrack(A[0], 0);

    cout << Max << '\n' << Min << '\n';

    return 0;
}