#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int getMin(int l, int r) {
  int min = v[l];
  for (int i = l + 1; i <= r; ++i) {
    if (v[i] < min) min = v[i];
  }
  return min;
}

int solve(int l, int r) {
  if (l == r) return 0;
  int max = -1, temp, min = getMin(l, r);
  for (int i = l; i < r; ++i) {
    temp = solve(l, i) + solve(i + 1, r) + min;
    if (max == -1 || temp > max) max = temp;
  }
  return max;
}

int main() {
  int t, k = 1, n, m, i, j, x;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    v.clear();
    for (int i = 1; i <= m; ++i) {
      cin >> x;
      v.push_back(x);
    }
    cout << "Case #" << k++ << ": " << solve(0, m - 1) + min(0, m - 1) << endl;
  }
  return 0;
}
