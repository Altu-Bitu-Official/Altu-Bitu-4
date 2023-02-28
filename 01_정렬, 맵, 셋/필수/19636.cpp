/*요요 시뮬레이션*/
#include <iostream>

using namespace std;

int main() {
	int w, l, t, days, ingest, consume;
	cin >> w >> l >> t;
	cin >> days >> ingest >> consume;
	int w1 = w, w2 = w;
	int l2 = l;
	for (int i = 0; i < days; i++) {
		w1 += ingest - (l + consume);
		w2 += ingest - (l2 + consume);
		if (abs(ingest - l2 - consume) > t) {
			l2 += floor((ingest - l2 - consume) / 2.0);
		}
	}
		if (w1 <= 0)
			cout << "Danger Diet\n";
		else
			cout << w1 << " " << l << "\n";

		if (w2 <= 0 || l2 <= 0)
			cout << "Danger Diet\n";
		else {
			cout << w2 << " " << l2 << " ";
			if (l - l2 > 0)
				cout << "YOYO";
			else
				cout << "NO";
		}
}




