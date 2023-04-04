#include <iostream>
#include <vector>

using namespace std;

//세로 계산
int countS( int i, int j, int num, vector<vector<int>> &vec){
    for(int k=0; k<5; k++){
        if(vec[i][j+k] != num){ // 여기서 5개 연속임을 이미 확인함
            return -1;
        }
    }

    if(vec[i][j-1] == num || vec[i][j+5]==num){ //6개일때 확인 -> 이미 6개 이상에서 답이 아니므로 6개까지만 고려해준다.
        return -1;
    }
    else{
        return 1;
    }
}

//가로 계산
int countK( int i, int j, int num, vector<vector<int>> &vec){
    for(int k=0; k<5; k++){
        if(vec[i+k][j] != num){
            return -1;
        }
    }

    if(vec[i-1][j] == num || vec[i+5][j]==num){
        return -1;
    }
    else{
        return 1;
    }
}

//우하향 대각선 계산
int countUD( int i, int j, int num, vector<vector<int>> &vec){
    for(int k=0; k<5; k++){
        if(vec[i+k][j+k] != num){
            return -1;
        }
    }

    if(vec[i-1][j-1] == num || vec[i+5][j+5]==num){
        return -1;
    }
    else{
        return 1;
    }
}

//좌하향 대각선 계산
int countSD( int i, int j, int num, vector<vector<int>> &vec){
    for(int k=0; k<5; k++){
        if(vec[i-k][j+k] != num){
            return -1;
        }
    }

    if(vec[i+1][j-1] == num || vec[i-5][j+5]==num){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    int num=0,count=0;
    int s, t, k, d =0;
    vector<vector<int>> vec;
    vec.assign(19,vector<int> (19));

    for( int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin>>vec[i][j];
        }
    }

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            num = vec[i][j];
            if( num != 0){
                if(countS(i,j,num,vec) == 1){
                    cout<<vec[i][j]<< endl<< i+1<< " "<< j+1;
                }
                else if( countK(i,j,num,vec) == 1){
                    cout<<vec[i][j]<< endl<< i+1<< " "<< j+1;
                }
                else if( countUD(i,j,num,vec) == 1){
                    cout<<vec[i][j]<< endl<< i+1<< " "<< j+1;
                }
                else if( countSD(i,j,num,vec) == 1){
                    cout<<vec[i][j]<< endl<< i+1<< " "<< j+1;
                }                                
            }
        }
    }
    return 0;
}