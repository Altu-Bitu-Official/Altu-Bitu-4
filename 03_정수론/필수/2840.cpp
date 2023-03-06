#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<char> findWords(N); // n만큼 벡터 생성후 0으로 초기화 상태
    int index=0;

    for (int i = 0; i < K; i++){
        int changeNumbers;
        char alphabet;

        cin >> changeNumbers >> alphabet;

        changeNumbers = (changeNumbers+index)%N;
        index=changeNumbers;

        if(findWords[index] !=0){
            cout <<"!\n";
        }

        else{
            findWords[index] = alphabet;
        }
    }

    for (int i=0; i<K;i++){
        if (findWords[i] == 0){
            findWords[i] = '?';
        }
    }
    for(int i=0; i<N; i++){
        cout << findWords[(i+index)%N];
    }
    return 0;
}