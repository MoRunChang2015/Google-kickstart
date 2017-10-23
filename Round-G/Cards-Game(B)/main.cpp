#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> r, b;
vector<bool> f;

long long ans = -1, n;

void solve(long long x, long long tot) {
  if (x <= 1) {
    if (ans == -1 || ans > tot) ans = tot;
    return;
  }
  for (long long i = 0; i < n; ++i)
    if (f[i] == false) {
      f[i] = true;
      for (long long j = i + 1; j < n; ++j)
        if (f[j] == false) {
          solve(x - 1, tot + min(r[i] ^ b[j], b[i] ^ r[j]));
          f[j] = true;
          f[i] = false;
          solve(x - 1, tot + min(r[i] ^ b[j], b[i] ^ r[j]));
          f[i] = true;
          f[j] = false;
        }
      f[i] = false;
    }
}

int main() {
  long long t, k = 1, x, i;
  cin >> t;
  while (t--) {
    cin >> n;
    r.clear();
    b.clear();
    f.clear();
    for (i = 0; i < n; ++i) {
      cin >> x;
      r.push_back(x);
      f.push_back(false);
    }
    for (i = 0; i < n; ++i) {
      cin >> x;
      b.push_back(x);
    }
    ans = -1;
    solve(n, 0);
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
