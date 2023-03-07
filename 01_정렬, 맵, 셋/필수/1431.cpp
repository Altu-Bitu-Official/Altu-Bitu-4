#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2)
{
	// 시리얼 번호의 길이가 다를 경우 짧은 순으로
	if (s1.size() != s2.size())
		return s1.size() < s2.size();

	// 시리얼 번호의 숫자 합이 다르다면 적은 순으로
	int sum_s1 = 0, sum_s2 = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (48 <= s1[i] && s1[i] <= 57)
			sum_s1 += (int)s1[i] - 48;
		if (48 <= s2[i] && s2[i] <= 57)
			sum_s2 += (int)s2[i] - 48;
	}
	if(sum_s1 != sum_s2)
		return sum_s1 < sum_s2;

	// 그외에는 사전순으로 숫자 먼저 => 아스키코드 비교
	// 시리얼 번호는 중복되지 않으므로 중복을 고려하지 않음
	int i;
	for (i = 0; i < s1.size(); i++)
	{
		if(s1[i] != s2[i])
			return s1[i] < s2[i];
	}
}

int main()
{
	// 입력
	int n;
	cin >> n;

	vector<string> serials;
	serials.assign(n, {});
	for (int i = 0; i < n; i++)
	{
		cin >> serials[i];
	}

	// 정렬
	sort(serials.begin(), serials.end(), cmp);

	// 출력
	for (int i = 0; i < serials.size(); i++) {
		cout << serials[i] << '\n';
	}
}