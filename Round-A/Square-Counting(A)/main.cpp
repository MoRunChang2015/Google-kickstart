#include <cmath>
#include <iostream>
using namespace std;

const long long MOD = 1000000007;
const long long inv_6 = 166666668LL;
int main() {
  long long t, k, n, m, ans;
  cin >> t;
  k = 1;
  while (t--) {
    ans = 0;
    cin >> n >> m;
    long long r = min(n, m);
    ans += n * m % MOD * (r * (r - 1) / 2 % MOD) % MOD;
    ans %= MOD;
    ans -= (n + m) % MOD * r % MOD * (r - 1) % MOD * (2 * r - 1) % MOD * inv_6 %
           MOD;
    ans = (ans + MOD) % MOD;
    long long temp = r * (r - 1) / 2 % MOD;
    ans += temp * temp % MOD;
    ans %= MOD;
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
