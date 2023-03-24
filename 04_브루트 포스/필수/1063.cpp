#include <iostream>

using namespace std;



void movePosition(string &kPosition,string m){ //위치를 옮기는 함수
   if(m=="R"){ //if문을 통해 각 경우에 따라 동작하도록 함
        if(char(kPosition[0]+1) <='H') {
            string result="";
            result+=kPosition[0]+1; //질문: 두 char을 이어붙이는 더 쉬운 방법이 있을까요?
            result+=kPosition[1]; //질문 : 여기서 result=(kPosition[0]+1)+kPosition[1] 형태로 작성하면 결과값이 왜 제대로 안나오는 지 궁금합니다.
            kPosition = result;
        }
    }else if(m=="L"){
        if(char(kPosition[0]-1) >='A') {
            string result = "";
            result += kPosition[0] - 1;
            result += kPosition[1];
            kPosition = result;
        }

    }else if(m=="B"){

        if(int(kPosition[1]-1-'0')>=1){
            string result="";
            result+=kPosition[0];
            result+=kPosition[1]-1;
            kPosition = result;

        }

    }else if(m=="T"){

        if(int(kPosition[1]+1-'0')<=8){
            string result="";
            result+=kPosition[0];
            result+=kPosition[1]+1;
            kPosition = result;

        }

    }else if(m=="RT"){
       if(char(kPosition[0]+1) <='H'&&int(kPosition[1]+1-'0')<=8) {
           string result="";
           result+=kPosition[0]+1;
           result+=kPosition[1]+1;
           kPosition = result;
       }

    }else if(m=="LT"){
       if(char(kPosition[0]-1) >='A'&&int(kPosition[1]+1-'0')<=8) {
           string result="";
           result+=kPosition[0]-1;
           result+=kPosition[1]+1;
           kPosition = result;
       }

    }else if(m=="RB"){
       if(char(kPosition[0]+1) <='H'&&int(kPosition[1]-1-'0')>=1) {
           string result="";
           result+=kPosition[0]+1;
           result+=kPosition[1]-1;
           kPosition = result;
       }
    }else if(m=="LB"){
       if(char(kPosition[0]-1) >='A'&&int(kPosition[1]-1-'0')>=1) {
           string result="";
           result+=kPosition[0]-1;
           result+=kPosition[1]-1;
           kPosition = result;
       }
    }



}


int main(){
 string kPosition,sPosition,move,tmpS,tmpK;
 int n;
 cin >> kPosition >>sPosition >> n;

 for(int i=0;i<n;i++){
    cin >>move;
    tmpK= kPosition; //이동하기전 킹의 위치를 저장해두는 변수 tmpK
     movePosition(kPosition,move); //킹 이동시킴
     if(kPosition == sPosition){ //킹과 돌의 위치가 같다면
         tmpS =sPosition; //이동하기전 돌의 위치를 저장해두는 변수 tmpS
         movePosition(sPosition,move); //돌 이동시킴
         if(sPosition==tmpS){ //돌을 이동시켰지만 이전이랑 위치가 같음( 돌이 범위를 벗어나서 이동하지않음)
             kPosition = tmpK;//킹의 위치도 이전과 동일하게 돌려놓음
         }
     }

 }


 cout <<kPosition<<"\n"<<sPosition;


    return 0;
}