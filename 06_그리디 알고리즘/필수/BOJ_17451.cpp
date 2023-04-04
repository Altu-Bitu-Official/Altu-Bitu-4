#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(300000);
	
	//벡터에 값 담기.
	for (int i = 0; i < n; i++) {
		cin >> v[i];		
	}

	//맨 끝에서부터 거꾸로 값을 구해나간다.
	long long velo = v[n-1];//맨 끝 값을 초기값으로 설정
	
	for (int i = n - 2; i >= 0; i--) {//벡터의 총 원소개수보다 하나 적게 실행
			
		
			if (v[i] >velo) {
				velo = v[i];
			}
			else {
				if (velo % v[i] != 0) {
					velo = (velo / v[i] + 1) * v[i];//일일이 더해나가지 않고, 관계를 이용한다
				}
				else {//v[i]==velo일 때는
					continue;
				}
				
			}
		
	}
	cout << velo;

}