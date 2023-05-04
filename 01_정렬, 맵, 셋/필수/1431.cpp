#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct guitar{
    string serial;
    int num_add;
};

bool cmp(const guitar& g1, const guitar& g2){
    if (g1.serial.length() != g2.serial.length()) {
		return g1.serial.length() < g2.serial.length();
	}
	if (g1.num_add != g2.num_add) {
		return g1.num_add < g2.num_add;
	}
	return g1.serial < g2.serial;
}

int main(){
    int n; //기타의 개수
    vector<guitar> g_list;
    cin >> n;

    g_list.assign(n, {});

    for(int i=0; i<n; i++){
        cin >> g_list[i].serial;
        g_list[i].num_add = 0;
        for (int j=0; j< g_list[i].serial.length(); j++){
            if ((g_list[i].serial[j] - '0' <= 9) && (g_list[i].serial[j] - '0' >= 0)){
                g_list[i].num_add += g_list[i].serial[j] - '0';
            }
        }
    }
    sort(g_list.begin(), g_list.end(), cmp);

    for (int i = 0; i < g_list.size(); i++) {
		cout << g_list[i].serial << '\n';
	}
	return 0;
}

