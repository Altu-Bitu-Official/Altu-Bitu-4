#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> S;
int min_difference = numeric_limits<int>::max();

void calculate_difference(vector<int>& start_team, vector<int>& link_team) {
    int start_team_ability = 0;
    int link_team_ability = 0;
    for (int i = 0; i < start_team.size(); i++) {
        for (int j = i + 1; j < start_team.size(); j++) {
            start_team_ability += S[start_team[i]][start_team[j]] + S[start_team[j]][start_team[i]];
            link_team_ability += S[link_team[i]][link_team[j]] + S[link_team[j]][link_team[i]];
        }
    }
    min_difference = min(min_difference, abs(start_team_ability - link_team_ability));
}

void dfs(int index, vector<int>& start_team, vector<int>& link_team) {
    if (index == N) {
        if (start_team.size() == N / 2 && link_team.size() == N / 2) {
            calculate_difference(start_team, link_team);
        }
        return;
    }

    start_team.push_back(index);
    dfs(index + 1, start_team, link_team);
    start_team.pop_back();

    link_team.push_back(index);
    dfs(index + 1, start_team, link_team);
    link_team.pop_back();
}

int main() {
    cin >> N;
    S.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    vector<int> start_team, link_team;
    dfs(0, start_team, link_team);

    cout << min_difference << endl;

    return 0;
}
