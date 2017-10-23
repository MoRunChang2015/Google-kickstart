#include <iostream>
#include <set>
using namespace std;

int main() {
  set<long long> s;
  int t, k;
  k = 1;
  cin >> t;
  while (t--) {
    long long a, n, p, g, temp, r, step, last;
    s.clear();
    cin >> a >> n >> p;
    temp = a;
    step = 1;
    s.insert(temp % p);
    last = temp % p;
    temp = (temp % p) * a;
    while (true) {
      r = temp % p;
      if (s.find(r) != s.end()) break;
      step++;
      s.insert(r);
      last = r;
      temp = r * a;
    }
    cout << "Case #" << k++ << ": ";
    if (n >= step)
      cout << last << endl;
    else {
      long long ans = 1;
      while (n--) {
        ans *= a;
        ans %= p;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
