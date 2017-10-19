#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t, k, l, r;
  long long n;
  cin >> t;
  k = 1;
  while (t--) {
    cin >> l >> r;
    n = min(l, r);
    if (n >= 1)
      cout << "Case #" << k++ << ": " << n * (n + 1) / 2 << endl;
    else
      cout << "Case #" << k++ << ": 0" << endl;
  }
  return 0;
}
