#include <iostream>
#include <vector>

using namespace std;

//초기화
void initCircle(vector<char> &circle, int num)
{
  for(int i = 0; i < num; i++)
  {
    circle[i] = '?';    
  }
}

//중복시 1반환
int findDuplicate(vector<char> circle, int i, int num)
{
  char c = circle[i];
  for (int j = 0; j < num; j++)
  {
    if (j == i)
    {
      continue;
    }
    if (circle[j] == c)
    {
      return 1;
    }
  }
  return 0;
}

int main() {
  int num, k;
  cin >> num >> k;
  vector<char> circle(num);
  initCircle(circle, num);
  int i = 0, count, flag = 0;
  char c;
  while (k--)
  {
    cin >> count >> c; 
    i = (i + count) % num;
    if (circle[i] == '?' || circle[i] == c)
    {
      circle[i] = c;
    }
    else
    {
      flag = 1;
      break;
    }
    if (findDuplicate(circle,i,num))
    {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
  {
    cout << "!";
  }
  else
  {
    int j = i, n = 0;
    while(1)
      {
        if (n == num)
        {
          break;
        }
        j = (j + num) % num;
        cout << circle[j];
        j--;
        n++;
      }
  }
  return 0;
}