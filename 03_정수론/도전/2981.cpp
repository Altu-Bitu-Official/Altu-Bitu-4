#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//최대 공약수 구하는 함수
int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


set<int> cal(vector<int>& v) {
	vector<int> v2; //주어진 수 중 최솟값 구하기
	int n; // 최대공약수 구할 기준 수
	set<int> s; //결과를 구할 셋

	//차를 쉽게 구하기 위해 정렬
	sort(v.begin(), v.end());

	//이웃한 수들간의 차끼리 최대공약수 구하기
	n = v[1] - v[0];

	for (int i = 2; i < v.size(); i++) {
		n = gcdIter(n, v[i] - v[i - 1]);
	}

	//최대공약수의 약수 구하기
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			s.insert(i);
		}
	}
	
	
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	set<int> result; //결과를 저장할 셋

	//입력 
	cin >> n;

	vector<int> v;

	while (n--) {
		cin >> m;
		v.push_back(m);
	}

	//연산
	result = cal(v);

	//출력
	for (auto iter : result) {
		cout << iter << " ";
	}
	
	return 0;
}