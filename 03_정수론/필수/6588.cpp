//6588 골드바흐의 추측
//에라토스테네스의 체를 이용하여 풉니다. 
#include <iostream>
using namespace std;
bool is_not_prime[1000004];
//소수인 배열 골라내기:= is_not_prime[n]=true이면 소수가 아니고, false이면 소수임.
void fast() {
  ios_base::sync_with_stdio(false); cin.tie(0);
}
void erathos(){
  is_not_prime[0]=true; is_not_prime[1]=true; //0과 1은 소수가 아니므로 true처리.
  for(int i =2; i <= 1000000; i++){
    for(int j = 2*i; j<= 1000000; j+=i) { //그 수의 배수들은 다 소수가 아니다 처리를 해준다.
      is_not_prime[j]= true;
    }    
  }
}
void solve(int n){
  bool found =false; 
  for(int i=3; i<=n; i+=2) { //어차피 짝수는 골라낼 수 없다. 탐색 시간 줄이려고 이렇게 코드를 짰습니다.
    if(!is_not_prime[i]&&!is_not_prime[n-i]) { //두 홀수 소수의 합으로 나타낼 수 있으면
      found =true; 
      cout << n << " = " << i << " + " << n-i << "\n"; break;
    }
  }
  if(!found){
    cout << "Goldbach's conjecture is wrong.\n";
  }
}
int main() {
  fast();
  erathos();
  while(true){
    int n;
    cin >> n;
    if(n==0) break; //종료조건 명시
    solve(n);
  }
}