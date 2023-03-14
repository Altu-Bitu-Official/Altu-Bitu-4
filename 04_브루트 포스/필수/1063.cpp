#include <iostream>

using namespace std;



void movePosition(string &kPosition,string m){
   if(m=="R"){
        if(char(kPosition[0]+1) <='H') {
            string result="";
            result+=kPosition[0]+1;
            result+=kPosition[1];
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
    tmpK= kPosition;
     movePosition(kPosition,move);
     if(kPosition == sPosition){
         tmpS =sPosition;
         movePosition(sPosition,move);
         if(sPosition==tmpS){
             kPosition = tmpK;
         }
     }

 }


 cout <<kPosition<<"\n"<<sPosition;


    return 0;
}