#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 9, sum_height = 0, num;
	vector<int> v;
	//입력
	while (n--) {
		cin >> num;
		v.push_back(num);
		sum_height += num;
	}
	sort(v.begin(), v.end()); //정렬
	//연산 & 출력
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum_height - v[i] - v[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << v[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
}
