#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v, int i, int j) {
	for (int k = 0; k < 9; k++){
		if (k != i && k != j) {
			cout << v[k] << '\n';
		}
	}
}

int main() 
{
	int n = 9;
	int sumHeight = 0, num;
	vector<int> v;
	//입력
	while (n--) {
		cin >> num;
		v.push_back(num);
		sumHeight += num;
	}
	sort(v.begin(), v.end()); //정렬
	//연산 & 출력
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sumHeight - v[i] - v[j] == 100) {
				printVector(v, i, j);
				return 0;
			}
		}
	}
}
