#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000; //k의 최대 범위
vector<int> primes(MAX + 1, 0);
vector<int> sangun(MAX + 1, 0);

void getPrimes() {
    for(int i = 2; i * i <= MAX; i++) {
        if(primes[i] != 0) {
            continue;
        }
        for(int j = i * i; j <= MAX; j += i) {
            if (primes[j] == 0) {
                primes[j] = 1;
            }
        }
    }
}

int sumSplit(int num)
{
  vector<int> split;
  int k = 1, tmp = num;
  //num 의 자릿수 계산하기
  while (tmp)
  {
    tmp = tmp / 10;
    k = k * 10;
  }
  k = k / 10;
  //배열에 각 자리 저장
  while(k)
  {
    split.push_back(num / k);
    num = num % k;
    k = k / 10;
  }
  int sum = 0;
  //배열의 합 리턴
  for(int i = 0; i < split.size(); i++)
  {
    sum += split[i] * split[i];
  }
  return sum;
}

// 상근수 체크 재귀로 넘겨 count
int checkNum(int num, int count, int tmp, vector<int> &tmp_split) 
{
    //MAX를 넘기는 count 혹은 이미 상근수가 아닌 수가 지나온 경우
    if (count > MAX || sangun[num]) { 
      for (int i = 0; i < tmp_split.size(); i++)
      {
        if(sangun[tmp_split[i]] != 1){
          sangun[tmp_split[i]] = 1;    // 지나온 수를 저장함 
        }
      }
      tmp_split = {};
      return 0; 
    }
    //상근수인 경우
    if (num == 1) {
      tmp_split = {};
      return 1; 
    }
    tmp_split.push_back(num);
    count++; 
  return checkNum(sumSplit(num), count, tmp, tmp_split);
}


vector<int> getRes(int num)
{
  vector<int> res;
  for(int i = num; i > 1; i--)
  {
    vector<int> tmp_split;
    //소수일때 상근수인지 체크
    if(!primes[i]){
      if(checkNum(i, 0, i, tmp_split))
      {
        res.push_back(i);
      }
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  getPrimes();
  vector<int> res = getRes(n);
  for(int i = res.size() - 1; i >= 0; i--)
  {
    cout << res[i] << "\n";
  }
  return 0;
}