#include <iostream>
#include <limits.h>

using namespace std;

int main(){
    int x, y, b;

    cin >> x >> y >> b;

    int matrix[x][y];

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> matrix[i][j];
        }
    }

    int maxHeight = 0;
    int leastTime = INT_MAX;

    for(int k=0; k<257; k++){
        int time = 0;
        int add = 0; //추가해야할 블럭 수
        int sub = 0; //제거해야할 블럭 수 
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if (matrix[i][j] < k){ //추가
                    int addBlock = k - matrix[i][j];
                    time += addBlock;
                    add += addBlock;
                }
                if (matrix[i][j] > k){ //제거
                    int subBlock = matrix[i][j] - k;
                    time += 2 * subBlock;
                    sub += subBlock;
                }
            }
        }
        

        if (b + sub >= add){
            if(leastTime >= time){
                maxHeight = k;
                leastTime = time;
            }
        }
    }

    cout << leastTime << " " << maxHeight;



    return 0;
}
