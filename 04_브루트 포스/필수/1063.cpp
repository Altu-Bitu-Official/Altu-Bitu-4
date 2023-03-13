//1063 킹
//체스판을 각각 90도 회전하면 2차원 배열같이 사용할 수 있다는 점에 착안하여 구현을 진행하였습니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//R, L, B, T, RT, LT, RB, LB의 방향을 각각 좌표배열로 나타낸것
int dx[]={1, -1, 0, 0, 1, -1, 1, -1}; 
int dy[]={0, 0, -1, 1, 1, 1, -1, -1}; 
int king_x, king_y, dol_x, dol_y;
bool is_in_board(int i) {
	int Nking_x= king_x+dx[i];
	int Nking_y= king_y+dy[i];
	int Ndol_x= dol_x, Ndol_y = dol_y;
	
	if(Nking_x < 1 || 8 < Nking_x || Nking_y < 1 || 8 < Nking_y) {
	   return false;
    }
	if(Nking_x == Ndol_x && Nking_y == Ndol_y) {
		Ndol_x += dx[i], Ndol_y += dy[i];
		if(Ndol_x < 1 || 8 < Ndol_x || Ndol_y < 1 || 8 < Ndol_y) {
		    return false;
		}
  }
	king_x= Nking_x, king_y= Nking_y; //업데이트
	dol_x = Ndol_x, dol_y= Ndol_y;
	return true;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string king, dol; int n;
  cin>> king >> dol >> n;
  //king[0], dol[0]:= A1, A2에서 'A'에 해당하는 부분, king[1], dol[1]:= '1', '2'에 해당하는 부분
   king_x= king[0]-'A'+1, king_y= king[1]-'1'+1;
   dol_x= dol[0]-'A'+1, dol_y= dol[1]-'1'+1;

  while(n--) {
	 string command;
	 cin >> command;
	 //각 명령어마다 보드 범위에서 벗어나는지 아닌지부터 예외처리해줌
	 if(command == "R") {
		  if(!is_in_board(0)){
			 continue;
		  }
	  }
	 else if(command == "L") {
		if(!is_in_board(1)){
			continue;
		  }
	 }
	 else if(command == "B") {
		if(!is_in_board(2)){
			continue;
		  }
	 }
	else if(command == "T") {
		if(!is_in_board(3)){
			continue;
		  }
	 }
	else if(command == "RT") {
		if(!is_in_board(4)){
			continue;
		  }
	 }
	else if(command == "LT") {
		if(!is_in_board(5)){
			continue;
		  }
	 }
	else if(command == "RB") {
		if(!is_in_board(6)){
			continue;
		  }
	 }
	else if(command == "LB") {
		if(!is_in_board(7)){
			continue;
		}
	 }
  }
  
	cout << (char)(king_x + 'A' - 1) << king_y << "\n";
	cout << (char)(dol_x + 'A' - 1) << dol_y <<"\n";
}