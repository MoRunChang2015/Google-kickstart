#include <cmath>
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
  long long t, k, n, m;
  cin >> t;
  k = 1;
  long long ans;
  while (t--) {
    ans = 0;
    cin >> n >> m;
    n--;
    m--;
    for (long long i = 1; i <= min(n, m); ++i) {
      ans +=
          (((m - i + 1) % MOD) * ((n - i + 1) % MOD)) % MOD * (i % MOD) % MOD;
      ans %= MOD;
    }
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
