#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



int main(){
    int chess[7][7];   //모든 배열을 0으로 초기화
    char rix;               //열
    int mat, num, N;           //행
    int rixNum = (int)rix-65;    // char을 정수로 바꿔줌

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chess[i][j] = i*8+j;
        }
    }
    
    cin >> mat >> rix;
    int kingMat = mat;
    int kingRixNum = rixNum;
    int king = kingMat*8+kingRixNum;

    cin >> mat >> rix;
    int stoneMat = mat;
    int stoneRixNum = rixNum;
    int stone = stoneMat*8+stoneRixNum;

    cin >> N;

    string str;
    for (int i=0; i<N; i++){
        cin >> str;
        if (str == "T") {
            kingMat-=1;
            if(kingMat !=-1 ){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneMat-=1;
                }    
            }
            else{
                continue;
            }
        }
        else if (str == "RT") {
            kingMat-=1; kingRixNum+=1;
            if(kingMat !=-1 && kingRixNum !=8){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneMat-=1; stoneRixNum+=1;
                }
            }
            else{
                continue;
            }
        }
        else if (str == "R") {
            kingRixNum+=1;
            if( kingRixNum != 8){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneRixNum+=1;
                }    
            }
            else{
                continue;
            }
        }        
        else if (str == "RB") {
            kingRixNum+=1; kingMat+=1;
            if( kingRixNum !=8 && kingMat !=8){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneMat +=1; stoneRixNum +=1;
                }
            }
            else{
                continue;
            }
        }
        else if (str == "B") {
            kingMat+=1;
            if( kingMat != 8){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneMat+=1;
                }    
            }
            else{
                continue;
            }
        }           
        else if (str == "LB") {
            kingMat+=1; kingRixNum-=1;
            if( kingRixNum != -1 && kingMat !=8){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneMat+=1; stoneRixNum-=1;
                }
            }
            else{
                continue;
            }
        }
        else if (str == "L") {
            kingRixNum-=1;
            if( kingRixNum != -1){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneRixNum-=1;
                }    
            }
            else{
                continue;
            }
        }   
        else if (str == "LT") {
            kingMat-=1; kingRixNum-=1;
            if(kingRixNum !=-1 && kingMat !=-1){
                king = kingMat*8+kingRixNum;
                if(king == stone){
                    stoneRixNum-=1; stoneMat -=1;
                }
            }
            else{
                continue;
            }
        }

    }
    
    int kingRix = kingRixNum+65;
    int stoneRix = stoneRixNum+65;
    
    cout << (char)kingRix << kingMat;
    cout << (char)stoneRix << stoneMat;
    return 0;
}