#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void compLength(vector<string> arr, int index_A, int index_B) {
	//A와 B의 길이가 다르면, 짧은 것이 먼저 온다.arr[j]와 arr[j+1] 스왑
	if (arr[index_A].length() > arr[index_B].length()) {
		swap(arr[index_A], arr[index_B]);
	}
}
//만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 
//모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
//(숫자인 것만 더한다)
void compSum(vector<string> arr, int index_A, int index_B) {
			if (arr[index_A].length() == arr[index_B].length()) {
				int A = 0, B = 0;//숫자더한거 비교용, 초기화하고 쓰기
				for (int k = 0; k < arr[index_A].length(); k++) {
					if ('0' <= arr[index_A].at(k) && arr[index_A].at(k) <= '9') {
						A += arr[index_A].at(k) - '0';
					}
					if ('0' <= arr[index_B].at(k) && arr[index_B].at(k) <= '9') {
						B += arr[index_B].at(k) - '0';
					}
				}
				if (A > B) {//작은거 앞으로, swap: arr[j], arr[j+1]
					swap(arr[index_A], arr[index_B]);
				}
				//만약 1, 2번 둘 조건으로도 비교할 수 없으면, 
				//사전순으로 비교한다.숫자가 알파벳보다 사전순으로 작다.
				else if (A == B) {
					vector<string> temp_arr(2);
					temp_arr[0] = arr[index_A];
					temp_arr[1] = arr[index_B];
					sort(temp_arr.begin(), temp_arr.end());//사전순정렬
					arr[index_A] = temp_arr[0];
					arr[index_B] = temp_arr[1];
				}
			}
}
int main() {
	int n;


	//0. 대입
	cin >> n;//갯수
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//1. 연산

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n - 1; j++) {
			//A와 B의 길이가 다르면, 짧은 것이 먼저 온다.arr[j]와 arr[j+1] 스왑
			compLength(arr, j, j+1);
			//만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 
			//모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
			//(숫자인 것만 더한다)
			compSum(arr, j, j + 1);
		}
	}

	//2. 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	


	
	return 0;
}