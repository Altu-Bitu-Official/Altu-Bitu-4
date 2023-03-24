#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 지금 반영해야하는 것: 안바뀌면 안됨
// 40개 짜리에 한 개 더 세지는 이유..?
int CheckRowSerialNum(int n, int i, vector<vector<char>> &candy_color)
{
    vector<int> counts;
    int count = 0;
    char color = candy_color[i][0];
    for (int j = 0; j < n; j++)
    {
        if (candy_color[i][j] == color)
        {
            count++;
        }
        else
        {
            counts.push_back(count);
            color = candy_color[i][j];
            count = 1;
        }
    }
    counts.push_back(count);
    int maximum_count = 0;
    for (int j = 0; j < counts.size(); j++)
    {
        if (maximum_count < counts[j])
        {
            maximum_count = counts[j];
        }
    }
    // maximum_count:각 행의 최대 개수
    // 연속되는 개수 세는 함수-가로

    return maximum_count;
}
int CheckColumnSerialNum(int n, int j, vector<vector<char>> &candy_color)
{
    // 연속되는 개수 세는 함수-세로
    vector<int> counts_column;
    int count = 0;
    char color = candy_color[0][j];
    for (int i = 0; i < n; i++)
    {
        if (candy_color[i][j] == color)
        {
            count++;
        }
        else
        {
            counts_column.push_back(count);
            color = candy_color[i][j];
            count = 1;
        }
    }
    counts_column.push_back(count);
    int maximum_count = 0;
    for (int i = 0; i < counts_column.size(); i++)
    {
        if (maximum_count < counts_column[i])
        {
            maximum_count = counts_column[i];
        }
    }
    // maximum_count:각 행의 최대 개수
    // 연속되는 개수 세는 함수-가로

    return maximum_count;
}
int CheckMaximum(int n, vector<vector<char>> &candy_color)
{
    // 만약 열이나 행에 같은 것의 개수가 n이면 바로 return n
    // 그렇지 않다면 개수를 각각 세고 벡터에 넣어줌
    // 벡터에 넣어준 후

    // 가장 많은 연속된 색의 수를 세는 함수
    int maximum_num = 0;
    for (int i = 0; i < n; i++)
    {
        int maximum_row = CheckRowSerialNum(n, i, candy_color);
        if (maximum_row > maximum_num)
        {
            maximum_num = maximum_row;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int maximum_column = CheckColumnSerialNum(n, j, candy_color);
        if (maximum_column > maximum_num)
        {
            maximum_num = maximum_column;
        }
    }
    return maximum_num;
}
bool CheckRowChange(int n, int k, vector<vector<char>> &candy_color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != k && i - 1 != k && i > 1 && candy_color[i - 1][j] != candy_color[i][j])
            {
                return true;
            }
            if (i != k && i + 1 != k && i < n - 1 && candy_color[i + 1][j] != candy_color[i][j])
            {
                return true;
            }
            if (i != k && j < n - 1 && candy_color[i][j + 1] != candy_color[i][j])
            {
                return true;
            }
            if (i != k && j > 1 && candy_color[i][j - 1] != candy_color[i][j])
            {
                return true;
            }
            // i행에서 바꿔야만 한다면 false
            // 언제??
        }
    }
    return false;
}
bool CheckColumnChange(int n, int k, vector<vector<char>> &candy_color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != k && i > 1 && candy_color[i - 1][j] != candy_color[i][j])
            {
                return true;
            }
            if (j != k && i < n - 1 && candy_color[i + 1][j] != candy_color[i][j])
            {
                return true;
            }
            if (j != k && j + 1 != k && j < n - 1 && candy_color[i][j + 1] != candy_color[i][j])
            {
                return true;
            }
            if (j != k && j > 1 && j - 1 != k && candy_color[i][j - 1] != candy_color[i][j])
            {
                return true;
            }
            // i행에서 바꿔야만 한다면 false
            // 언제??
        }
    }
    return false;
}
int ChangeRowColor(int n, vector<vector<char>> &candy_color)
{
    // 바꾸고 나서 n 되면 바로 리턴
    // 바꾸고 나서 n 안되면 그중 가장 큰 것 리턴
    // 지금은 오른쪽을 바꾸는 것만 고려됨, 왼쪽을 바꾸는 경우도 고려해야함

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        char color = candy_color[i][0];
        for (int j = 0; j < n; j++)
        {
            if (candy_color[i][j] != color && i > 1 && candy_color[i - 1][j] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i - 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
                // 여기서 candy color를 복제한 벡터를 만들고

                // 그것을 ChangeRow에 준다음 CheckRow 를 확인해서 큰 것으로 채택..?
            }
            if (candy_color[i][j] != color && i < n - 1 && candy_color[i + 1][j] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i + 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            if (candy_color[i][j] != color && j + 1 < n && candy_color[i][j + 1] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i][j + 1] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            color = candy_color[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        char color = candy_color[i][n - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            if (candy_color[i][j] != color && (i > 1 && candy_color[i - 1][j] == color))
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i - 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
                // 여기서 candy color를 복제한 벡터를 만들고

                // 그것을 ChangeRow에 준다음 CheckRow 를 확인해서 큰 것으로 채택..?
            }
            if (candy_color[i][j] != color && i < n - 1 && candy_color[i + 1][j] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i + 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            if (candy_color[i][j] != color && j - 1 >= 0 && candy_color[i][j - 1] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i][j - 1] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            color = candy_color[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (CheckRowChange(n, i, candy_color))
        {
            int row_maximum = CheckRowSerialNum(n, i, candy_color);
            if (maximum < row_maximum)
            {
                maximum = row_maximum;
            } // 만일 해당하는 행이 바뀔 수밖에 없는 상황이라면 그 행을 안바꾸는 경우(밑의 for문에서) 배제해야함
        }
    }

    return maximum;
}
int ChangeColumnColor(int n, vector<vector<char>> &candy_color)
{

    // 바꾸고 나서 count 최댓값 return
    //  바꾸고 나서 n 되면 바로 리턴
    //  바꾸고 나서 n 안되면 그중 가장 큰 것 리턴
    bool changed = false;
    int maximum = 0;
    for (int j = 0; j < n; j++)
    {
        char color = candy_color[0][j];
        for (int i = 0; i < n; i++)
        {
            if (candy_color[i][j] != color && (j > 1 && candy_color[i][j - 1] == color))
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            if (candy_color[i][j] != color && (j < n - 1 && candy_color[i][j + 1] == color))
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            if (candy_color[i][j] != color && i + 1 < n && candy_color[i + 1][j] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i + 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }

            color = candy_color[i][j];
        }
    }
    for (int j = 0; j < n; j++)
    {
        char color = candy_color[n - 1][j];
        for (int i = n - 1; i >= 0; i--)
        {
            if (candy_color[i][j] != color && j > 1 && candy_color[i][j - 1] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i][j - 1] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }

            if (candy_color[i][j] != color && j < n - 1 && candy_color[i][j + 1] == color)
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i][j + 1] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            if (candy_color[i][j] != color && (i - 1 >= 0 && candy_color[i - 1][j] == color))
            {
                vector<vector<char>> new_candy_color = candy_color;
                new_candy_color[i][j] = color;
                new_candy_color[i - 1][j] = candy_color[i][j];
                int row_serial_num = CheckRowSerialNum(n, i, new_candy_color);
                int column_serial_num = CheckColumnSerialNum(n, j, new_candy_color);
                if (maximum < column_serial_num)
                {
                    maximum = column_serial_num;
                }
                if (maximum < row_serial_num)
                {
                    maximum = row_serial_num;
                }
            }
            color = candy_color[i][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (CheckColumnChange(n, j, candy_color) == true)
        {
            int column_maximum = CheckColumnSerialNum(n, j, candy_color);
            if (maximum < column_maximum)
            {
                maximum = column_maximum;
            } // 만일 해당하는 행이 바뀔 수밖에 없는 상황이라면 그 행을 안바꾸는 경우(밑의 for문에서) 배제해야함
        }
    }

    return maximum;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> candy_color; // candy color를 2차원 벡터에 저장
    for (int i = 0; i < n; i++)
    {
        vector<char> candy_color_width;
        for (int j = 0; j < n; j++)
        {
            char candy;
            cin >> candy;
            candy_color_width.push_back(candy);
        }
        candy_color.push_back(candy_color_width);
    }

    int row_maximum = ChangeRowColor(n, candy_color);
    int column_maximum = ChangeColumnColor(n, candy_color);
    if (row_maximum > column_maximum)
    {
        cout << row_maximum;
    }
    else
    {
        cout << column_maximum;
    }

    return 0;
}