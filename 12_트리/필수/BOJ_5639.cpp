#include <iostream>

using namespace std;

int tree[10000] = {0};

int total_idx = 0;

void expGraph(int begin, int end) {
  int idx = begin + 1, root = tree[begin];

  if (begin == end) {
      return;
  }

  while (tree[idx] < root) {
    idx++;
    if (idx == total_idx) {
        return;
    }
  }
  expGraph(begin + 1, idx);
    cout << tree[idx-1] << '\n';
    cout << root << '\n';
  expGraph(idx, end);
  cout << tree[idx-1] << '\n';
  cout << root << '\n';





}

int main() {
  int n;

  while (total_idx < 9) {
  cin >> n;
  tree[total_idx++] = n;
  }
  expGraph(0, total_idx);

}