//시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare

int sumNum(string serial_num) {
	int sum = 0;
	for (int i = 0; i < serial_num.size(); i++) {
		if (isdigit(serial_num[i])) { 
      	sum += serial_num[i] - '0'; 
		}
	}
	return sum;
}

int main()
{
	int n; //기타의 개수



	// 입력
	cin >> n;
  	vector<string> guitar(n, ""); //시리얼 번호
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