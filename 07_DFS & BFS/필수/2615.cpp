#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(){


    vector<vector<bool>> black;
    vector<vector<bool>> white;

    black.assign(21, vector<bool>(21, false));
    white.assign(21, vector<bool>(21, false));
    int a;

    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            cin >> a;
            
            if (a == 1){
                black[i][j] = true;
            }

            if (a == 2){
                white[i][j] = true;
                
            }
        }
    }

    int count = 0;
    int x, y;

    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            if(black[i][j]){
                if((j<16)&&black[i][j+1] && black[i][j+2] && black[i][j+3] && black[i][j+4]){
                    if(!black[i][j+5] && !black[i][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((i<16)&& black[i+1][j] && black[i+2][j] && black[i+3][j] && black[i+4][j]){
                    if(!black[i+5][j] && !black[i-1][j]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((j<16)&&(i<16)&&black[i+1][j+1] && black[i+2][j+2] && black[i+3][j+3] && black[i+4][j+4]){
                    if(!black[i+5][j+5] && !black[i-1][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((i>4)&&(j<16)&&black[i-1][j+1] && black[i-2][j+2] && black[i-3][j+3] && black[i-4][j+4]){
                    if(!black[i-5][j+5] && !black[i+1][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
            }
        }
    }
        
    if(count==5){
        cout << "1" << '\n' << x << " " << y;
        return 0;
    }

    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            if(white[i][j]){
                if((j<16)&& white[i][j+1] && white[i][j+2] && white[i][j+3] && white[i][j+4]){
                    if(!white[i][j+5] && !white[i][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((i<16)&&white[i+1][j] && white[i+2][j] && white[i+3][j] && white[i+4][j]){
                    if(!white[i+5][j] && !white[i-1][j]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((j<16)&&(i<16)&&white[i+1][j+1] && white[i+2][j+2] && white[i+3][j+3] && white[i+4][j+4]){
                    if(!white[i+5][j+5] && !white[i-1][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
                if((i>4)&&(j<16)&&white[i-1][j+1] && white[i-2][j+2] && white[i-3][j+3] && white[i-4][j+4]){
                    if(!white[i-5][j+5] && !white[i+1][j-1]){
                        count = 5;
                        x=i;
                        y=j;
                        i = 20;
                        j =20;
                    }
                }
            }
        }
    }

    if(count == 5){
        cout << "2" << '\n' << x << " " << y;
    }

    else{
        cout << "0";
    }

    return 0;
}

