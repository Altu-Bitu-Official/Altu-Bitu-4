#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//필요한 속력이 최고가 되기 위해서는 마지막 행성에서의 비행선 속도=vi 여야함
//따라서 효율적으로 계산하기 위해서는 입력받는 속도를 역산해서 지구에서의 최소 속도를 구하는게 유리

void veclocity(vector<long>&v, int n) {
	long speed = v[n-1];
	for (int i = n-1; i >=0; i--) {//speed가 vi보다 작으면 speed값을 vi로 갱신
		if (speed <= v[i] ) {
			speed = v[i];
		}//vi보다 크면서 정수배수인 speed는 문제가 되지 않으므로 생략
		else if (speed > v[i] && speed % v[i] != 0) {
			speed = v[i] - (speed % v[i]) + speed;//vi보다 크면서 정수배인 숫자로 speed를 갱신
		}
	}
	cout << speed;//최종 speed값을 출력
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<long> v(n); //최대 속력이 int 범위를 넘을 수 있으므로 long형으로 속력 저장
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	veclocity(v, n);

	return 0;
}
