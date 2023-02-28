#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	deque<int>result;

	string a, b;
	cin >> a >> b;
	int carry, sum;

	// 자리 수가 맞지 않을 경우, 맞지 않는 만큼 앞에 0 추가
	if (a.size() < b.size()) {
		for (int i = 0; i < a.size() - b.size(); i++) {
			a.insert(i, "0");
		}
	}
	if (b.size() < a.size()) {
		for (int i = 0; i < b.size() - a.size(); i++) {
			b.insert(i, "0");
		}
	}
	// 연산을 쉽게 하기 위해 뒤집음
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());


		for (int i = 0; i < a.size(); i++) {
			sum = (a[i] - '0' + b[i] - '0') % 10;
			carry = (a[i] - '0' + b[i] - '0') / 10;
			result.push_back(sum);
			
			//10보다 크면 carry는 1이상으로 다음 자리에서 1 더해줌
			if (carry > 0) {
				int k;
				k = a[i + 1] + 1;
				a[i + 1] = k;
			}
	}
		// 덱을 사용해서 뒤에서부터 출력
	if ((a[a.size() - 1] - '0' + b[a.size() - 1] - '0') >=10) {
		result.push_back(1);
	}
	while (!result.empty()) {
		cout<<result.back();
		result.pop_back();
	}
	return 0;
}