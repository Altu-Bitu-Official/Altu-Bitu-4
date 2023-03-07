#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;

void setpan(vector<char> &pan) {
	for (int i = 0; i < n; i++) {
		pan[i] = '?';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	//입출력 속도 향상
	
	//입력
	cin >> n >> k;
	vector<char> pan(n);
	setpan(pan);
	int index;
	
	for (int i = 0; i < k; i++) {
		int count; 
		char tmpc;
		
		cin >> count >> tmpc;
		if (i == 0) {
		    pan[0] = tmpc; index = 0; 
            continue; 
		}
		index = (count + index) % n;
		if (pan[index] != '?'&& pan[index] != tmpc) {
		    cout << "!"; return 0; 
		}
		else {
			pan[index] = tmpc;
		}
	}
	//중복 체크해야 함
	
	return 0;
}