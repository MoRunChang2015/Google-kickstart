#include <algorithm>
#include <iostream>
#include <vector>

const long long MOD = 1000000007;

using namespace std;

int main() {
  int t, k = 1, i, n;
  long long temp, ans, l, r, sum, exp, x;
  cin >> t;
  vector<long long> v, d;
  while (t--) {
    cin >> n;
    v.resize(n);
    for (i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    d.clear();
    d.reserve(n);
    sum = 0;
    for (i = n - 2; i >= 0; --i) d.push_back(v[i + 1] - v[i]);
    for (i = 0; i < d.size(); ++i) sum += d[i];
    exp = 1;
    ans = 0;
    l = 0;
    r = 0;
    x = 0;
    temp = 0;
    for (i = 0; i < n - 1; ++i) {
      x = ((x + l) % MOD + r) % MOD;
      temp = (temp + sum) % MOD;
      ans += ((temp + MOD - x) % MOD) * exp % MOD;
      ans %= MOD;
      exp = (exp << 1) % MOD;
      l = (l + d[i]) % MOD;
      r = (r + d[d.size() - 1 - i]) % MOD;
    }
    ans %= MOD;
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
