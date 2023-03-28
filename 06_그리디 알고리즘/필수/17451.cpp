#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long minimum;

	//입력 
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//연산
	minimum = v[n - 1];
	for (int i = n - 2; i >= 0; i--) { //역방향으로 최소 속도를 추적
		if (minimum <= v[i]) { //필요 속도가 이미 이동한 속도보다 더 클 경우 
			minimum = v[i];
		}
		else { //필요 속도가 이미 이동한 속도보다 작을 경우 배수를 구해야 함 
			if (minimum % v[i] != 0) { // 둘이 나눴을 때 나머지가 0이 아니라면 배수가 아니므로 
				minimum = v[i] * (minimum / v[i] + 1);
			}
		}
	}

	//출력 
	cout << minimum;

	return 0;

}