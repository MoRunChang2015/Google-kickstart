#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int a[50][50];
long long dp[50][50][50][50];
bool f[50][50][50][50];
int n, m;

int getMin(int x1, int y1, int x2, int y2) {
  int ans = a[x1][y1];
  for (int i = x1; i <= x2; ++i)
    for (int j = y1; j <= y2; ++j)
      if (ans > a[i][j]) ans = a[i][j];
  return ans;
}

long long solve(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return 0;
  if (f[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
  long long ans = -1, temp;
  for (int i = y1; i < y2; ++i) {
    temp = solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2);
    if (ans < temp) ans = temp;
  }
  for (int i = x1; i < x2; ++i) {
    temp = solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2);
    if (ans < temp) ans = temp;
  }
  ans += getMin(x1, y1, x2, y2);
  f[x1][y1][x2][y2] = true;
  return dp[x1][y1][x2][y2] = ans;
}

int main() {
  int t, k = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) cin >> a[i][j];
    memset(dp, 0, sizeof dp);
    memset(f, 0, sizeof f);
    solve(1, 1, n, m);
    cout << "Case #" << k++ << ": " << dp[1][1][n][m] << endl;
  }
  return 0;
}
