#include <iostream> 
#include <cmath> 
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
  
  
 int main() { 
         int init_input, diet_input; //기존 일일 에너지 섭취량, 다이어트 중 일일 에너지 섭취량 
         int activity, thres; //다이어트 중 일일 활동 대사량, 기초 대사량 변화 역치 
         int init_w, dur; //기존 체중, 다이어트 기간 
          
         //입력 
         cin >> init_w >> init_input >> thres; 
         cin >> dur >> diet_input >> activity; 
  
         int basal = init_input; //일일 기초대사량 
         int weight = init_w;  
  
         //일일 기초대사량 변화 고려 안한 예상 체중, 일일 기초 대사량 출력 
         weight += (diet_input - basal - activity) * dur; 
         (weight<=0)? cout << "Danger Diet\n": cout << weight << ' ' << basal<<'\n'; 
  
  
         //일일 기초대사량 변화 고려한 연산 
         weight = init_w; 
         while (dur--) { 
                 //몸무게 변화 
                 weight += (diet_input - basal - activity); 
  
                 //일일 기초대사량 업데이트 
                 if (abs(diet_input - basal - activity) > thres) { 
                         basal += floor((double)(diet_input - basal - activity) / 2); 
                 } 
  
                 //죽으면 끝 
                 if (weight <=0 || basal<=0) { 
                         cout << "Danger Diet\n"; 
                         return 0; 
                 } 
         } 
  
         //일일 기초대사량 고려한 예상 체중, 일일 기초 대사량 출력 
         cout << weight << ' ' << basal << ' '; 
         //요요 여부 
         if(init_input-basal>0){
             cout << "YOYO";
         }else{
            cout << "NO";
         }
  
 }
