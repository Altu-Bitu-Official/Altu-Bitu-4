#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	int alength = a.size();
	int blength = b.size();
	int asum = 0;
	int bsum = 0;//초기화

	if (alength != blength) //길이 순서대로 정렬
		return alength < blength;

	for (int i = 0; i < alength; i++) {
		if ('0' <= a[i] && a[i] <= '9') //숫자일때
			asum += int(a[i]) - 48;//합을 더함
	}
	for (int i = 0; i < blength; i++) {
		if ('0' <= b[i] && b[i]<= '9') //숫자일때
			bsum += int(b[i]) - 48;//합을 더함
	} 
	if (asum != bsum) 
		return asum < bsum;//길이가 같다면 숫자들의 합으로 정렬

	return a < b; //사전순으로 정렬

}

int main()
{
	int n;
	cin >> n;
	string s[50]; //시리얼 최대 길이가 50이므로

	for (int i = 0; i < n; i++) {
		cin >> s[i]; //시리얼을 입력받음
	}

	sort(s, s + n, cmp); //상단에서 정한 규칙대로 정렬
	
	for (int i = 0; i < n; i++)
		cout << s[i] << '\n'; //정렬한 것을 출력
}