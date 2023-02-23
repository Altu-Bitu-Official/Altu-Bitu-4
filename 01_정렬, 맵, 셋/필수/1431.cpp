//시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNum(string serial_num) {
	int sum = 0;
	for (int i = 0; i < serial_num.size(); i++) {
		if (isdigit(serial_num[i])) { 
      	sum += serial_num[i] - '0'; 
		}
	}
	return sum;
}

bool compare (const string& s1, const string& s2)
{
  if(s1.length() != s2.length()){ //1) 길이 다르면 짧은 거 먼저
    return s1.length() < s2.length();
  }

  else{
    if (sumNum(s1) != sumNum(s2)) { //2) 자리수의 합 작은 거 먼저
		return sumNum(s1) < sumNum(s2);
    }
    else return s1 < s2; //3) 알파벳 사전 순
  }

}



int main()
{
	int n; //기타의 개수



	// 입력
	cin >> n;
  	vector<string> input(n, ""); //시리얼 번호
  for (int i=0;i<n;i++){
    cin >> input[i];
  }

 //연산
 sort(input.begin(), input.end(), compare);



//출력
for (int i = 0; i < n; i++) {
		cout << input[i] << '\n';
	}

	return 0;
}