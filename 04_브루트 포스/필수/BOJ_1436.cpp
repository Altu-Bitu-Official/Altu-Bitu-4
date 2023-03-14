#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> first_arr(){
  set<int> arr;
  for(int i = 1; i < 10; i++)
  {
    arr.insert(i*1000 + 666);    
  }
  for(int i = 0; i < 10; i++)
  {
    arr.insert(6660 + i);    
  }
  return arr;
}

set<int> second_arr(){
  set<int> arr;
  for(int i = 10; i < 100; i++)
  {
    arr.insert(i*1000 + 666);    
  }
  for(int i = 0; i < 100; i++)
  {
    arr.insert(66600 + i);    
  }
  for(int i = 1; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      arr.insert(i * 10000 + 6660 + j);
    }
  }
  return arr;
}

set<int> third_arr(){
  set<int> arr;
  for(int i = 100; i < 1000; i++)
  {
    arr.insert(i*1000 + 666);    
  }
  for(int i = 0; i < 1000; i++)
  {
    arr.insert(666000 + i);    
  }
  for(int i = 1; i < 10; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      arr.insert(i * 100000 + 66600 + j);
    }
  }
  for(int i = 10; i < 100; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      arr.insert(i * 10000 + 6660 + j);
    }
  }
  return arr;
}

set<int> end_arr(){
  set<int> arr;
  for(int i = 1000; i < 10000; i++)
  {
    arr.insert(i*1000 + 666);    
  }
  for(int i = 0; i < 10000; i++)
  {
    arr.insert(6660000 + i);    
  }
  for(int i = 1; i < 10; i++)
  {
    for(int j = 0; j < 1000; j++)
    {
      arr.insert(i * 1000000 + 666000 + j);
    }
  }
  for(int i = 10; i < 100; i++)
  {
    for(int j = 0; j < 100; j++)
    {
      arr.insert(i * 100000 + 66600 + j);
    }
  }
  for(int i = 100; i < 1000; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      arr.insert(i * 10000 + 6660 + j);
    }
  }
  return arr;
}

int main() {
  int n, count = 0;
  cin >> n;
  set<int> s;
  if (n == 1)
  {
    cout << "666";
  }
  else if (n <= 19)
  {
    s = first_arr();
    n = n - 1;
    for(auto iter = s.begin(); iter != s.end(); iter++){
      count++;
      if (count == n)
      {
        cout << *iter;
      }
    } 
  }
  else if (n <= 280)
  {
    s = second_arr();
    n = n - 19;
    for(auto iter = s.begin(); iter != s.end(); iter++){
      count++;
      if (count == n)
      {
        cout << *iter;
      }
    } 
  }
  else if (n <= 3700)
  {
    s = third_arr();
    n = n - 280;
    for(auto iter = s.begin(); iter != s.end(); iter++){
      count++;
      if (count == n)
      {
        cout << *iter;
      }
    } 
  }
  else if (n <= 10000)
  {
    s = end_arr();
    n = n - 3700;
    for(auto iter = s.begin(); iter != s.end(); iter++){
      count++;
      if (count == n)
      {
        cout << *iter;
      }
    } 
  }
  return 0;
}