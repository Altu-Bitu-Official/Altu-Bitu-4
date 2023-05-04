#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, s;
    char alp;
    cin >> n >> k;

    int correct = 0; //해당하는 회전판이 존재할 수 있는 지 확인하는 지표. 0이면 존재할 수 있는것
    int arrow = 0; //현재 가리키고있는 위치

    vector<char> spin(n);

    for(int i=0; i<n; i++){
        spin[i] = '?';
    }

    for(int i=0; i<k; i++){
        cin >> s >> alp;
        int point = arrow - s;

        //point가 0~n 에 해당하지 않을 경우
        while(point<0){
            point += n;
        }
        if(point>=n){
            point %= n;
        }

        //이미 알파벳이 들어있는 칸인지 점검
        if(spin[point] != '?'){
            if(spin[point] != alp){
                correct++;
                break;
            }   
        }
        spin[point] = alp;
        arrow = point;
    }

    //다른칸에 같은 알파벳 있는 경우 점검
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((spin[i] == spin[j])&&(spin[i]!='?')){
                correct++;
                break;
            }
        }
    }

    if(correct==0){
        for(int i=0; i<spin.size(); i++){
            int start = arrow + i;
            if(start >= n){
                start %= n;
            }
            cout << spin[start];
        }
        cout << '\n';
    }
    else{
        cout << '!' << '\n';
    }
    return 0;
}
