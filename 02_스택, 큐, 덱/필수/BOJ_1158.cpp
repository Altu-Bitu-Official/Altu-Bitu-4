#include <iostream>
#include <queue>

using namespace std;

queue<int> numPop(queue<int> q, int pop)
{
  int tmp_q;
  for(int i = 0; i < pop - 1; i++)
  {
    tmp_q = q.front();
    q.push(tmp_q);
    q.pop();
  }
  cout << q.front() << ", ";
  q.pop();
  return q;
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int num, pop;
  cin >> num >> pop;
  queue<int> q;
  for(int i = 1; i <= num; i++)
    q.push(i);
  cout << '<';
  while(q.size() > 1)
  {
    q = numPop(q, pop);
  }
  cout << q.front() << ">\n";
	return 0;
}
