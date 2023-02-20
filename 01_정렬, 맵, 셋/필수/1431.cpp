#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string temp;
	//숫자 더한거 비교
	int A = 0;
	int B = 0;

	//0. 대입
	cin >> n;//갯수
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//1. 연산

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n - 1; j++) {
			//A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
			if (arr[j].length() > arr[j + 1].length()) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			//만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 
			//모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
			//(숫자인 것만 더한다)
			else if (arr[j].length() == arr[j + 1].length()) {
				A = 0, B = 0;//초기화하고 쓰기
				for (int k = 0; k < arr[j].length(); k++) {			
					if ('0' <= arr[j].at(k) && arr[j].at(k) <= '9') {
						A += arr[j].at(k) - '0';
					}
					if ('0' <= arr[j + 1].at(k) && arr[j + 1].at(k) <= '9') {
						B += arr[j + 1].at(k) - '0';
					}
				}
				if (A > B) {//작은거 앞으로
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
				//만약 1, 2번 둘 조건으로도 비교할 수 없으면, 
				//사전순으로 비교한다.숫자가 알파벳보다 사전순으로 작다.
				else if (A == B) {
					vector<string> temp_arr(2);
					temp_arr[0]=arr[j];
					temp_arr[1] = arr[j + 1];
					sort(temp_arr.begin(), temp_arr.end());//사전순정렬
					arr[j] = temp_arr[0];
					arr[j + 1] = temp_arr[1] ;
				}
			}	
		}
	}

	//2. 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}