#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
static constexpr uint32_t const_hash(const char *p)
{
    return *p ? static_cast<uint32_t>(*p) + 33 * const_hash(p + 1) : 5381;
}

char CheckRow(char row_init, vector<char> &row)
{
    char row_index;
    for (int i = 1; i < 9; i++)
    {
        if (row_init == row[i])
        {
            row_index = i + '0';
            // 이 i가 가로의 시작 위치가 되는 것
        }
    }
    return row_index;
}
int MoveRow(string move_cmd, int row, int column)
{
    uint32_t hash = const_hash(move_cmd.c_str());
    switch (hash)
    {
    case const_hash("R"):
        if (row < 8)
        {
            row++;
        }
        break;
    case const_hash("RT"):
        if (row < 8 && column < 8)
        {
            row++;
        }
        break;
    case const_hash("RB"):
        if (row < 8 && column > 1)
        {
            row++;
        }
        break;
    case const_hash("L"):
        if (row > 1)
        {
            row--;
        }
        break;
    case const_hash("LT"):
        if (row > 1 && column < 8)
        {
            row--;
        }
        break;
    case const_hash("LB"):
        if (row > 1 && column > 1)
        {
            row--;
        }
        break;

    default:
        break;
    }
    return row;
}
int MoveColumn(string move_cmd, int row, int column)
{
    uint32_t hash = const_hash(move_cmd.c_str());
    switch (hash)
    {
    case const_hash("B"):
        if (column > 1)
        {
            column--;
        }
        break;
    case const_hash("RB"):
        if (row < 8 && column > 1)
        {
            column--;
        }
        break;
    case const_hash("LB"):
        if (row > 1 && column > 1)
        {
            column--;
        }
        break;
    case const_hash("T"):
        if (column < 8)
        {
            column++;
        }
        break;
    case const_hash("RT"):
        if (row < 8 && column < 8)
        {
            column++;
        }
        break;
    case const_hash("LT"):
        if (row > 1 && column < 8)
        {
            column++;
        }
        break;

    default:
        break;
    }
    return column;
}
bool CheckMove(string move_cmd, int row_index, int column_index)
{

    int new_row = MoveRow(move_cmd, row_index, column_index);
    int new_column = MoveColumn(move_cmd, row_index, column_index);
    if (new_row == row_index && new_column == column_index)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char king_row_init, stone_row_init;
    string move_cmd;
    int king_column_init, stone_column_init;
    cin >> king_row_init >> king_column_init >> stone_row_init >> stone_column_init >> n;
    // row의 경우에는 char 벡터를 만들어서
    // i를 더하고 빼고하면서 최종 row는 해당 i로 하면 될 듯?
    vector<char> row = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int king_row_index = CheckRow(king_row_init, row) - '0';
    int stone_row_index = CheckRow(stone_row_init, row) - '0';
    int king_column_index = king_column_init;
    int stone_column_index = stone_column_init;

    while (n--)
    {
        cin >> move_cmd;
        // getline(cin, move_cmd);
        //  여기서 돌이 빠져나가는지 킹이 빠져 나가는지 확인해야함
        //  킹이 빠져나간다면 안함
        //  돌이 빠져나감 &&킹이 움직이면 돌이 겹침 이면 킹도 안움직임
        //  킹, 돌 모두 안움직일때 row,column 둘다 안움직여야함 (해결 완)

        int new_king_row = MoveRow(move_cmd, king_row_index, king_column_index);
        int new_king_column = MoveColumn(move_cmd, king_row_index, king_column_index);
        if ((new_king_row == stone_row_index) && (new_king_column == stone_column_index)) // 돌을 움직여야 할 경우(어차피 킹이 안움직이면 돌도 안움직임, 같을 일 없음)
        {
            if (CheckMove(move_cmd, stone_row_index, stone_column_index) == true) // 돌을 움직일 수 있는지 확인
            {
                int new_stone_row = MoveRow(move_cmd, stone_row_index, stone_column_index);
                int new_column_row = MoveColumn(move_cmd, stone_row_index, stone_column_index);
                king_row_index = new_king_row;
                king_column_index = new_king_column;
                stone_row_index = new_stone_row;
                stone_column_index = new_column_row;
            }
        }
        else
        {
            // 돌 움직일 필요 없음
            king_row_index = new_king_row;
            king_column_index = new_king_column;
        }
        cin.ignore();
    }
    cout << row[king_row_index] << king_column_index << '\n';
    cout << row[stone_row_index] << stone_column_index << '\n';
    return 0;
}