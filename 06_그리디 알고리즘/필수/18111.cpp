//테스트 케이스는 다 통과되는데, 문제 제출을 하면 틀렸다고 나옵니다. ㅠㅠ
//어디가 잘못된 건지 도통 모르겠습니다...
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int ans_time=987654321; //큰 값으로 초기화. 정답이 될 최소시간
    int ans_height=-987654321;  //정답이 될 높이

    int N, M, inven;
    cin >> N >> M >> inven;
    int ground[500][500];
    for(int i =0; i < N; i++){
        for(int j =0; j < M; j++){
            cin >> ground[i][j];
        }
    }
    for(int block_height=0; block_height<=256; block_height++){

        //block_height는 땅을 어떤 높이를 고를지 정하는 것
        //0<=block_height<=256

        int total_time=0; //작업 소요 시간
        int remove=0; //제거한 블럭 갯수
        int build=0; // 쌓은 블럭 갯수
        for(int i =0; i < N; i++){
            for(int j =0; j < M; j++){
                if(block_height-ground[i][j]>0) {
                    //1번 작업인 경우: 블럭 제거(인벤은 증가)
                    total_time+=abs(block_height-ground[i][j]); 
                    remove+=(block_height-ground[i][j]); 
                } else if(block_height-ground[i][j]<0) {
                    //2번 작업 수행: 블럭 쌓기(인벤은 감소)
                    total_time+=abs(2*(block_height-ground[i][j]));
                    build+=abs(block_height-ground[i][j]); 
                } 
            }
        }
        if(remove + inven >= build) { //해당 후보군 블럭 높이는 유효한 후보군
            if(total_time <= ans_time) { //<가 아니라 <=(중복되는 정답이면 가장 큰 후보군 정답을 출력해야 하므로)
                ans_time=total_time; 
                ans_height=block_height;
            }
        }

    }
    cout << ans_time << " " << ans_height;
}