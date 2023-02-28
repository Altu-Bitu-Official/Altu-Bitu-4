#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 10000;

//숫자를 1자리씩 배열에 넣는 함수
int* Array(string n, int arr[]) {
	for (int i = 0; i < n.size(); i++) {
		arr[i] = n[i] - 48;
		//arr[0]에 n의 가장 큰 자릿수
	}
	return arr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n1, n2;
	cin >> n1 >> n2;
	int arr1[MAX] = { 0 };
	int arr2[MAX] = { 0 };
	int res[MAX] = { 0 };
	//숫자를 1자리씩 배열에 넣는다
	Array(n1, arr1);
	Array(n2, arr2);
	string x;
	int dig; //자릿수
	if (n1.size() >= n2.size()) {
		x = n1;
		dig = n1.size();
	}
	else {
		x = n2;
		dig = n2.size();
	}
	//arr[0]에 n의 가장 작은 자릿수 오도록 reverse
	reverse(arr1, arr1 + n1.size());
	reverse(arr2, arr2 + n2.size());
	for (int i = 0; i < x.size() - 1; i++) {
		if (arr1[i] + arr2[i] + res[i] < 10) {
			res[i] += arr1[i] + arr2[i];
		}
		else {
			int temp = (res[i] + arr1[i] + arr2[i]) % 10;
			res[i + 1] = ((res[i] + arr1[i] + arr2[i]) / 10);
			res[i] = temp;
		}

	}
	if (arr1[x.size() - 1] + arr2[x.size() - 1] + res[x.size() - 1] >= 10) {
		dig += 1;
		int temp = (res[x.size() - 1] + arr1[x.size() - 1] + arr2[x.size() - 1]) % 10;
		res[x.size()] = (res[x.size() - 1] + arr1[x.size() - 1] + arr2[x.size() - 1]) / 10;
		res[x.size() - 1] = temp;
	}
	else {
		res[x.size() - 1] += arr1[x.size() - 1] + arr2[x.size() - 1];
	}
	for (int i = dig - 1; i >= 0; i--) {
		cout << res[i];
	}

}