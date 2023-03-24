#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void move_king(string move, int *row, int *col)
{
  if (move == "R")
  {
    if((*row) < 8)
    { 
      (*row)++;
    }
  }
  if (move == "L")
  {
    if((*row) > 1)
    { 
      (*row)--;
    }
  }
  if (move == "B")
  {
    if((*col) > 1)
    { 
      (*col)--;
    }
  }
  if (move == "T")
  {
    if((*col) < 8)
    { 
      (*col)++;
    }
  }
  if (move == "RT")
  {
    if((*row) < 8 && (*col) < 8){
      (*row)++;
      (*col)++;
    }
  }
  if (move == "LT")
  {
    if((*row) > 1 && (*col) < 8){
      (*row)--;
      (*col)++;
    }
  }
  if (move == "RB")
  {
    if((*row) < 8 && (*col) > 1){
      (*row)++;
      (*col)--;
    }
  }
  if (move == "LB")
  {
    if((*row) > 1 && (*col) > 1){
      (*row)--;
      (*col)--;
    }
  }
}

void move_back(string move, int *row, int *col)
{
  if (move == "R")
  {
      (*row)--;
  }
  if (move == "L")
  {
      (*row)++;
  }
  if (move == "B")
  {
      (*col)++;
  }
  if (move == "T")
  {
      (*col)--;
  }
  if (move == "RT")
  {
      (*row)--;
      (*col)--;
  }
  if (move == "LT")
  {
      (*row)++;
      (*col)--;
  }
  if (move == "RB")
  {
      (*row)--;
      (*col)++;
  }
  if (move == "LB")
  {
      (*row)++;
      (*col)++;
  }
}

int main()
{
  int row_king, col_king, row, col, n;
  string state1, state2, move;
  cin >> state1 >> state2 >> n;
  row_king = state1[0] - 64;
  col_king = state1[1] - 48;
  row = state2[0] - 64;
  col = state2[1] - 48;
  while(n--)
  {
    cin >> move;
    move_king(move, &row_king, &col_king);
    if(row_king == row && col_king == col)
    {
      int tmp_row = row, tmp_col = col;
      move_king(move, &row, &col);
      if(tmp_row == row && tmp_col == col)
      {
        move_back(move, &row_king, &col_king);
      }
    }
  }
  char c = row_king + 64;
  cout << c << col_king << "\n";
  c = row + 64;
  cout << c << col;
}