#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//비교 함수 
int cmp(string &serial1,string &serial2 )
{
    int serial1_size = serial1.size();
    int serial2_size = serial2.size();
    
     if ( serial1_size != serial2_size ) // 길이가 다르면 
  {
        return serial1_size < serial2_size;
  }

   // 문자열 길이 같을때 숫자의 합으로 비교
    
    int serial1_sum = 0; 
    int serial2_sum = 0;
    for (int i=0; i<serial1.size(); i++)
    {
        if(serial1[i] >= '0' && serial1[i] <= '9')
        {
            serial1_sum += int(serial1[i]) - 48;
        }

        if(serial2[i] >= '0' && serial2[i] <= '9')
        {
            serial2_sum += int(serial2[i]) - 48;
        }
    }

    // 두 수의 합이 다르면 작은합을 가진 것 부터 먼저 
    if (serial1_sum != serial2_sum){
        return serial1_sum < serial2_sum;
    }
 

  // 1,2 두 조건으로 비교 할 수 없을 때 
  return serial1 < serial2; //사전순으로 정렬 
}



int main(void)
{
    int n;  // 기타 개수 
    string serial[50];   // 시리얼 저장 
    //입력 
    cin >> n; 
    for (int i=0; i<n; i++)
    {
        cin >> serial[i];
    }

    // 연산 
    sort(serial,serial + n ,cmp);  


    //출력 

    for(int i=0; i<n; i++)
    {
        cout << serial[i] << endl;
    }


    return 0;
}