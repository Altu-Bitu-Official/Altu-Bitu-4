#include <iostream>

using namespace std;
//이진검색트리를 전위 순회한 결과가 주어졌을 때 이를 후위 후위 순회한 결과로 변환
int v[10000];
void sol(int start, int end){//후위 순회
    if(start>=end){
        return;
    }
    

    int index;
    for(index=start+1;index<end;index++){
        if(v[start]<v[index]){
            break;
        }
       
    }
    sol(start+1, index);
    sol(index, end);
    cout << v[start]<<'\n';
}

int main(){
    

    int input;
    int index=0;
    while(cin >> input){
        v[index++]=input;
    }

    sol(0, index);

    return 0;
}