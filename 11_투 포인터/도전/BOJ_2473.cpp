#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

//세 용액의 특성값의 합이 0에 가깝게 되는 특성값 3개 반환
vector<ll> getValue(int n, vector<ll>& liquid) {
	//n이 3인 경우 그대로 반환
	if (n == 3) {
		return liquid;
	}

	vector<ll> result(3);

	ll min_value = 3 * 1e9; //최소 특성값의 합
	for (int i = 0; i < n - 2; i++) {
		int first = i; //첫 번째 용액 고정
		
		int left = i + 1, right = n - 1;
		while (left < right) {
			ll value = liquid[i] + liquid[left] + liquid[right]; //세 용액 특성값의 합

			//해당 값이 최솟값인 경우 최솟값 갱신
			if (abs(value) < min_value) {
				min_value = abs(value);
				result = { liquid[i], liquid[left], liquid[right] };
			}

			//value가 0인 경우 바로 종료
			if (value == 0) {
				return { liquid[i], liquid[left], liquid[right] };
			}
			//value가 0보다 큰 경우 right 감소 -> value 감소
			else if (value > 0) {
				right--;
			}
			//value가 0보다 작은 경우 left 증가 -> value 증가
			else {
				left++;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<ll> liquid(n);
	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}
	sort(liquid.begin(), liquid.end());
	
	//연산
	vector<ll> result = getValue(n, liquid);

	//출력
	for (int i = 0; i < 3; i++) {
		cout << result[i] << " ";
	}

	return 0;
}