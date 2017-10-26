#include <iostream>
using namespace std;

long long quick_pow(long long a, long long n, long long p) {
  if (n == 0) return 1;
  long long half = quick_pow(a, n / 2, p);
  long long ans = (half * half) % p;
  if (n % 2 == 0)
    return ans;
  else
    return (ans * a) % p;
}

int main() {
  int t, k;
  k = 1;
  cin >> t;
  while (t--) {
    long long a, n, p;
    cin >> a >> n >> p;
    long long ans = a % p;
    for (long long i = 2; i <= n; ++i) ans = quick_pow(ans, i, p);
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
