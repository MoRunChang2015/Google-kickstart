#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int getDiffLetter(const string& str) {
  int a[30] = {0};
  int ans = 0;
  for (size_t i = 0; i < str.length(); ++i)
    if ('A' <= str[i] && str[i] <= 'Z') {
      if (a[str[i] - 'A'] == 0) {
        ans++;
        a[str[i] - 'A'] = 1;
      }
    }
  return ans;
}

int main() {
  int t, k, n;
  cin >> t;
  k = 1;
  string ans = "", str;
  int max = -1;
  while (t--) {
    ans = "";
    max = -1;
    cin >> n;
    getchar();
    while (n--) {
      getline(cin, str);
      int temp = getDiffLetter(str);
      if (max == -1 || max < temp) {
        max = temp;
        ans = str;
      } else if (max == temp && ans > str) {
        ans = str;
      }
    }
    cout << "Case #" << k++ << ": " << ans << endl;
  }
}
