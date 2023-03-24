#include <iostream>
#include <string>
using namespace std;

//위치를 저장하는 구조체
struct Loca 
{
    int col;    //열(A부터 H를 각각 0부터 7까지의 정수로 바꿔서 저장)
    int row;    //행(맨아래줄1 ~ 맨위줄8)
};

//열의 알파벳을 정수로 바꿈(A부터 H를 각각 0부터 7까지의 정수에 대응)
int toInt(char st){
    string alphabets = "ABCDEFGH";
    for (int i=0; i<8; i++){
        if (st == alphabets[i]){
            return i;}
    }
}

//정수를 열의 알파벳으로 바꿈(0부터 7까지의 정수를 각각 A부터 H에 대응)
char toAlpha(int j){
    string alphabets = "ABCDEFGH";
    return alphabets[j];
}

//이동 명령어에 따라 이동시킨다 
//(체스판 안 정상이동이면 true 값, 체스판을 벗어나면 false값 가짐)
bool changeLocation(Loca& l, string m){
    Loca original =  l; //이동 전의 위치

    if (m=="R") {l.col++;}  // ->
    else if (m=="L") {l.col--;}  // <-
    else if (m=="T") {l.row++;}  // 위로
    else if (m=="B") {l.row--;}  // 아래로
    else if (m=="RT") {l.col++; l.row++;}   //대각선 오른쪽 위로
    else if (m=="LT") {l.col--; l.row++;}   //대각선 왼쪽 위로
    else if (m=="RB") {l.col++; l.row--;}   //대각선 오른쪽 아래로
    else if (m=="LB") {l.col--; l.row--;}   //대각선 왼쪽 아래로

    if (l.col<0 || l.col>7 || l.row<1 || l.row>8 ){ 
        //이동한 위치가 체스판 밖을 벗어날 경우 그 이동은 건너뜀
        l = original;
        return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string king, stone, moveto;
    int n;
    Loca king_loca, stone_loca;

    //왕과 돌의 위치를 문자열 형태로 입력받아서 Loca의 형태로 저장
    cin >> king >> stone >> n;
    king_loca = {toInt(king[0]) , king[1] -'0'};
    stone_loca = {toInt(stone[0]) , stone[1] -'0'};

    //n만큼 이동명령어 받아서 킹과 돌 이동
    while (n--){
        cin >> moveto;

        Loca temp_loca = king_loca; //이동 전의 킹의 위치 저장
        bool k_movement = changeLocation(king_loca, moveto);
        bool s_movement;

        if (k_movement && king_loca.col == stone_loca.col && king_loca.row == stone_loca.row ){
            //킹이 이동후에도 체스판을 안벗어나고, 돌과 위치가 일치할 때
            s_movement = changeLocation(stone_loca, moveto);
            //킹이 이동해서 돌을 체스판 밖으로 밀어낼 때, 킹과 돌 모두의 이동 무효
            if (s_movement == false) {king_loca = temp_loca;}
        }
    }

    //킹과 돌의 위치 출력
    cout << toAlpha(king_loca.col) << king_loca.row << '\n';
    cout << toAlpha(stone_loca.col) << stone_loca.row;
   
    return 0;
}