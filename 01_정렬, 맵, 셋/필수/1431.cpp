#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numbers(string str) {
    int sum = 0;
    for(int i = 0; i < str.size(); i++) {
        if(isdigit(str[i])) {
            sum += (str[i] - '0');
        }
    }
    return sum;
}

bool cmp(const string& s1, const string& s2) {

    // A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }

    // 길이가 같다면, 숫자인 것만 더해서 작은 합을 가지는 것이 먼저 온다. 
    if(s1.size() == s2.size() && numbers(s1) != numbers(s2)) {
        return numbers(s1) < numbers(s2);
    }

    // 사전순으로 비교
    return s1 < s2;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
    string str;
    vector<string> serial;

	while(n--) {
		cin >> str;
		serial.push_back(str);
	}
	
	sort(serial.begin(), serial.end(), cmp);

    for(int i = 0; i < serial.size(); i++) {
        cout << serial[i] << "\n";
    }

	return 0;
}