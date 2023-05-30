// 드래곤 커브
#include <iostream>
#include <vector>
using namespace std;

// 0세대 : 0
// 1세대 : 0 1
// 2세대 : 0 1 2 1
// 3세대 : 0 1 2 1 2 3 2 1

// n세대 : (n-1세대) + ((n-1세대 거꾸로) + 1) % 4

void draw(int x, int y, int d, int g, vector<vector<bool>> &paper){
    vector<int> direction; // g세대 이동할 방향 저장 
    direction.push_back(d);
    while (g--){
        int n = direction.size();
        for (int j = n-1 ; j>=0 ; j--){
            direction.push_back((direction[j] + 1) % 4);
        }
    }
    for (auto dir: direction){
        if (!(dir % 2)){ // x가 짝수이면 - x축 방향 이동
            paper[x + 1-dir][y] = true;
            x += 1 - dir; // 시작점 이동
        }
        else{ // x가 홀수이면 - y축 방향 이동
            paper[x][y+dir-2] = true;
            y += dir - 2; // 시작점 이동
        }
    }
}
// 사각형 개수 세기
void countSquare(vector<vector<bool>> &paper){
    int cnt = 0;
    for (int x = 0; x < 100; x++){
        for (int y = 0; y < 100; y++){
            if (paper[x][y] and paper[x][y+1] and paper[x+1][y] and paper[x+1][y+1]){
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main()
{
    int n, x, y, d, g;
    cin >> n;
    vector<vector<bool>> paper(101, vector<bool>(101, false));
    while (n--){
        cin >> x >> y >> d >> g;
        paper[x][y] = true;
        draw(x, y, d, g, paper);
    }
    countSquare(paper);
    return 0;
}