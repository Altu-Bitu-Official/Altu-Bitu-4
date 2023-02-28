#include <iostream>
#include <deque>
using namespace std;

deque<char> dq;


int add(string a, string b){
int carry=0;
  for (int i=a.size()-1;i>=0;i--){

  //자릿수 하나씩 접근. 문자를 정수로 변환
  int digit_a=a[i]='0';
  int digit_b=b[i]='0';
  int sum=digit_a+digit_b+carry;


  //합이 10보다 크면 일의 자리만 저장
  if (sum>9){
    sum-=10;
    carry+=1; //올림
  }
  else{
    carry=0;
  }

  //덱의 앞에 삽입
  dq.push_front(sum);

  }
return 0;
}

int main(){

//입력
string num1, num2;

cin >> num1 >> num2;

//num1의 자릿수 더 크도록 고정
if(num1.length()<num2.length()){
swap(num1, num2);
}

//더하기 연산
add(num1, num2);

//더해진 자릿수 하나씩 출력
for(int i=0; i<dq.size(); i++){
cout <<dq.front();

dq.pop_front();
}

return 0;
}