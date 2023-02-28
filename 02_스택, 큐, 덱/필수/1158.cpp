#include <iostream>
#include <queue>

using namespace std;

int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
  
  int n, k;
  queue<int> q; 

//숫자 입력 받아서 큐에 집어 넣기
cin >> n >>k;

for (int i=1; i<=n; i++){
  q.push(i);
}

cout << "<";

while(!q.empty()){
 for(int i = 0; i < k; i++){
			if(i!=k){ //k번쨰 숫자가 아니면 앞에서 빼서 뒤로 다시 넣기
q.pop();
q.push(i);

      }
    else{
      cout << q.front() << ",";
      q.pop();
      

    }
		}
	}
	cout<<">";	

return 0;
}