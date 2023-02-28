#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int  main() {
  int w, o, t, d, l, a, w1, w2, g;
  
  cin >> w >> o >> t; 
  cin >> d >> l >> a;
  
  g = o, w1 = w, w2 = w;
  for (int i = 0; i < d; i++)
  {
    w1 = w1 + l - (o + a);
    w2 = w2 + l - (g + a);
    if (abs(l - (g + a)) > t)
      g += floor((l - (g + a)) / 2.0); 
  }
  if (w1 <= 0)
    cout << "Danger Diet\n";
  else
    cout << w1 << " " << o << "\n";
  if (g <= 0 || w2 <= 0)
    cout << "Danger Diet\n";
  else
  {
    cout << w2 << " " << g;
    if (g < o)
      cout << " YOYO\n";
    else
      cout << " NO\n";
  }
}