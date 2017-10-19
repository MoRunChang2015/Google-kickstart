#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int t, k;
  double n, m;
  k = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    printf("Case #%d: %.8f\n", k++, (n - m) / (n + m));
  }
  return 0;
}
