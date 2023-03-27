#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_index=0;
     for(int i=0;i<number.size()-k;i++){//목표문자열의 자릿수만큼 반복해 하나하나 찾기
        
         int max_index=start_index;
         char max=number[max_index];
         for(int j=max_index;j<=k+i;j++){//발견한 가장 큰 수로부터 다시 큰 수 찾기
             if(max<number[j]){
                 max=number[j];
                 max_index=j;
             }
         }
         start_index=max_index+1;
         answer+=max;
     }   
    
    return answer;
}