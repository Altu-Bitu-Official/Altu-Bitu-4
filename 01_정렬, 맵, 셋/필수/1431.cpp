#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
	if (a.size() != b.size()){
		return a.size() < b.size();
	}

	else {   // 사이즈가 같을때
		int suma = 0;
		for (int i = 0; i < a.size(); ++i){
			if (a[i] - '0' <= 9 && a[i] - '0' >= 0){
				suma += a[i] - '0';
			}
		}
		int sumb = 0;
		for (int i = 0; i < b.size(); ++i){
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0){
				sumb += b[i] - '0';
			}
		}

		if (suma != sumb) {
			return suma < sumb;
		}
		
		else {
			return a < b; // 알파벳 순
		}
	}
}

int main(){
    int n;
	vector<string> v;
    // 입력
	cin >> n;

	while (n--){
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
	return 0;

}