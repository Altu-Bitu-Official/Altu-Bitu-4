#include <iostream>     //입출력을 위한 헤더
#include <cmath>        //절댓값, 내림연산 등을 사용하기 위해 선언 
using namespace std;    

 /* 
 *  
 * 1) 일일 기초 대사량 변화를 고려하지 않는 경우: 매일 체중이 (I - init_input - activity_metabolism)만큼 증가 
 * 2) 일일 기초 대사량 변화를 고려하는 경우 
 *      일일 기초 대사량(basal): |I - b_prev - activity_metabolism| >= T 인 경우, floor((I - b_prev - activity_metabolism)/2)만큼 증가 
 *      일일 체중 증가량: (I - basal - activity_metabolism) 
 *  
 * 사망 조건: (체중 <= 0) OR (basal <= 0) 
 *  
 * 요요 조건: (init_input - basal > 0) 
 */ 


 int main() {   //메인함수 실행 
         int init_input, diet_input; //기존 일일 에너지 섭취량, 다이어트 중 일일 에너지 섭취량 
         int activity, thres; //다이어트 중 일일 활동 대사량, 기초 대사량 변화 역치 
         int init_w, dur; //기존 체중, 다이어트 기간 

         //입력 
         cin >> init_w >> init_input >> thres;  // 문제에서 나온 입력순서대로 기존체중, 기존 일일 에너지 섭취량, 기초 대사량 변화 역치 입력받기
         cin >> dur >> diet_input >> activity; // 다이어트 기간, 다이어트 중 일일 에너지 섭취량, 다이어트 중 일일 활동 대사량을 앞에서 선언한 변수에 입력 받음 

         int basal = init_input; //일일 기초대사량을 basal 변수에 입력 받음 
         int weight = init_w;  // 기존 체중을 weight 라는 변수에 입력 받음 

         //일일 기초대사량 변화 고려 안한 예상 체중, 일일 기초 대사량 출력 
         //일일 기초대사량 변화를 고려하지 않으면 날짜에 따라서 변화하는 값이 없어서 예상 체중과 일일 기초대사량은 수식으로 바로 처리 가능 
         // for문 필요 없음 
         weight += (diet_input - basal - activity) * dur;   // 다이어트 후 체중  = (다이어트 중 일일 에너지 섭취량 - 일일 기초 대사량 - 다이어트 중 일일 활동 대사량 ) * 다이어트 기간 
         // 몸무게가 0이하이면 다이어트 후 예상 체중,일일 기초 대사량 출력하지 않고 'Danger Diet' 출력 그게 아니면 다이어트 후 예상 체중과 일일 기초 대사량을 출력 
         (weight<=0)? cout << "Danger Diet\n": cout << weight << ' ' << basal<<'\n'; 

         


         //일일 기초대사량 변화 고려한 연산 
         weight = init_w;     //  기초대사량 변화를 고려하지 않은 연산에서 weight 변수를 사용했으니까 weight를 기존 체중으로 다시 초기화 
         while (dur--) {  //다이어트 기간이 끝날 때 까지
                 //몸무게 변화 
                 weight += (diet_input - basal - activity); // 첫날 체중 변화는 (다이어트 중 일일 에너지 섭취량 - 일일 기초 대사량 - 다이어트 중 일일 활동 대사량 )

                 //일일 기초대사량 업데이트 
                 if (abs(diet_input - basal - activity) > thres) {  //(일일 에너지 섭취량 - 일일 에너지 소비량)의 절댓값이 기초 대사량 변화 역치 Thres 초과면 
                         basal += floor((double)(diet_input - basal - activity) / 2);  // 일일 기초 대사량 변화는 (일일 에너지 섭취량 − 일일 에너지 소비량) / 2 만큼 더해진다. 
                         // 이때 내림 연산이 제대로 계산이 되게 하기 위해서 double형으로 바꾼 뒤 나눗셈 연산을 하고 내림 연산을 해준다. 
                 } 

                 //죽으면 끝 
                 if (weight <=0 || basal<=0) {  // 문제에서 데시는 체중이 0이하 일일 기초 대사량이 0 이하인경우 사망한다고 했으니까 
                         cout << "Danger Diet\n"; // 데시의 사망이 예상되는 경우 체중과 일일 기초대사량, 요요발생 여부 출력 x, 'Danger Diet' 출력 
                         return 0;  // 데시 사망 예상되는 경우에 더 이상 연산하지 않고 함수 종료 
                 } 
         } 

         //일일 기초대사량 고려한 예상 체중, 일일 기초 대사량 출력 
         cout << weight << ' ' << basal << ' ';  
         //다이어트가 끝난 뒤에 요요 여부를 체크해줘야 함 
         if(init_input-basal>0){ //변화한 일일 기초 대사량=basal 을 가지고 기존 일일 에너지 섭취량으로 돌아갔을때  0보다 크면 체중이 증가함
             cout << "YOYO";     // 요요 발생 
         }else{                  // 체중이 증가하지 않는 경우 
            cout << "NO";        //'NO' 출력 
         }

         return 0;     // 메인 함수 종료 

 }



