#include <iostream>
#include <vector>

using namespace std;

const int MAX_LEN = 19;

typedef pair<int, int> ci;
int dx[4] = {0, 1, 1, -1}; // 아래 오른쪽 오른쪽아래 오른쪽위
int dy[4] = {1, 0, 1, 1};

bool is_valid(ci s, vector<vector<int>> &baduk)
{
    int cnt, x, y, nx, ny;
    x = s.first;  // 받아온 s는 pair<int,int> 이므로 각각의 첫번째값을 x값에 넣기
    y = s.second; // 두번째값을 y값에 넣기

    for (int i = 0; i < 4; i++) // 방향은 오른쪽 아래 오른쪽아래 오른쪽위 총 4가지가 존재함
    {
        nx = x;
        ny = y;
        for (cnt = 0; cnt < 5; cnt++) // 같은 색은 돌이 5개가 일직선이 될 경우를 구하는 것이므로 5번 검사하기
        {
            nx += dx[i];
            ny += dy[i];
            if (nx > 0 && nx <= MAX_LEN && ny > 0 && ny <= MAX_LEN && baduk[x][y] == baduk[nx][ny]) // 갱신된 nx값이 범위내1~19에 존재하고, 그 돌이 같은 돌이경우
            {
                continue;
            }
            else
            {
                break; // 아니면 나가기
            }
        }

        if (cnt == 4) // 5개가 일직선이지만 추가조건(역방향에 같은돌이 다르거나 역방향이 범위를 벗어나면 바둑5개임을 확정)이 필요
        {
            nx = x - dx[i]; // 시작 위치에서 역방향 조건 탐색하기
            ny = y - dy[i];
            if (nx <= 0 || nx > MAX_LEN || ny <= 0 || ny > MAX_LEN)
            {
                return true;
            }
            else if (baduk[x][y] != baduk[nx][ny])
            {
                return true;
            }
        }
    }
    return false;
}

ci solution(vector<vector<int>> &baduk, vector<ci> stones)
{
    for (int i = 0; i < stones.size(); i++) // 검정돌의 배열사이즈나 흰돌의 배열사이즈
    {
        if (is_valid(stones[i], baduk))
        {
            return stones[i]; // ci s = stones[i];
        }
    }
    return {0, 0};
    /*  for (auto s : stones)
      {
          if (is_valid(s, baduk))
          {             // s를 시작점으로 오목이 가능하다면
              return s; // s 반환
          }
      }
      //{0, 0} 반환
      return {0, 0};*/
}

int main()
{
    vector<vector<int>> baduk(MAX_LEN + 1, vector<int>(MAX_LEN + 1)); // 인덱스 1~19를 사용할 것이기에 +1함

    vector<ci> black_stones, white_stones; // 검정바둑좌표들을 포함한 배열 선언 (흰바둑좌표도!)

    for (int i = 1; i <= MAX_LEN; i++)
    {
        for (int j = 1; j <= MAX_LEN; j++)
        {
            cin >> baduk[i][j]; // 입력받은 바둑넣기

            if (baduk[i][j] == 1) // 바둑이 검은돌이면
            {
                black_stones.push_back({i, j}); // 좌표를 푸쉬백하기
            }
            else if (baduk[i][j] == 2) // 바둑이 흰돌이면
            {
                white_stones.push_back({i, j}); // 좌표를 푸쉬백하기
            }
        }
    }

    ci black_win = solution(baduk, black_stones); // 블랙 돌이 이겼을때, 블랙 좌표 (맨 왼쪽, 세로일 경우 맨 위쪽)을 반환함 만약 이기지못하면 {0,0}을 반환하도록함
    ci white_win = solution(baduk, white_stones); // 흰 돌이 이겼을때, 흰 좌표 (맨 왼쪽, 세로일 경우 맨 위쪽)을 반환함

    if (black_win.first) // 0이 아닌 수일때, 검정돌 이 이겼을때
    {
        cout << 1 << "\n"
             << black_win.first << " " << black_win.second; // 검정이 이김, 검정의 x, 검정의 y좌표 출력
    }
    else if (white_win.first) // 0이 아닌 수일때, 흰 돌이 이겼을때
    {
        cout << 2 << "\n"
             << white_win.first << " " << white_win.second; // 흰돌이 이김, 희돌의 x, 흰돌의 y좌표 출력
    }
    else
    {
        cout << "0";
    }

    return 0;
}