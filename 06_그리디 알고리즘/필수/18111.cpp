#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//땅고르기 작업
int sameHigh(vector<int> v, int h, int n , int m, int b) {
	int cnt = 0;

	for (int i = 0; i < n * m; i++) {
		//땅을 깎아내기
		if (v[i] > h) {
			b += v[i] - h;
			cnt += 2 * (v[i]- h);
		}
		else if (v[i] < h) { //인벤토리에서 블록 꺼내기
			if (b >= 0) {
				b -= h - v[i];
				cnt += h - v[i];
			}
		}

		//계산 결과 이후 블록이 0보다 작다면 구조 불가
		if (b < 0) {
			return -1;
		}

		//땅 높이 맞춰주기
		v[i] = h;

	}
	return cnt;
}

vector<int> findMin(vector<int>& h) {
	vector<int> min_number(2); //시간, 땅의 높이
	// 높이 0으로 기준 값 설정
	min_number[0] = h[0];
	min_number[1] = 0;

	for (int i = 1; i <= 256; i++) {
		if (h[i] < 0 ) { // 시간이 0보다 작다면 구조 불가
			continue;
		}
		if (min_number[0] >= h[i]) { // min_number에 있는 시간보다 작으면 min_number 교체
			min_number[0] = h[i];
			min_number[1] = i;
		}
	}

	return min_number;
}


int main()
{
	int n, m, b;
	vector<int> min_num(2); //출력할 결과 - 시간, 땅의 높이
	vector<int> high(257, 0); //높이에 따른 시간을 저장할 벡터

	//입력
	cin >> n >> m >> b;

	vector<int> v(n*m);

	for (int i = 0; i < n * m; i++) {
		cin >> v[i];
	}

	//연산
	
	//내림차순으로 정렬
	sort(v.begin(), v.end(), greater<>());

	for (int h = 0; h <= 256; h++) {
		high[h] = sameHigh(v, h, n, m, b);
	}

	min_num = findMin(high);
	

	cout << min_num[0]<<" "<<min_num[1];

	return 0;

}