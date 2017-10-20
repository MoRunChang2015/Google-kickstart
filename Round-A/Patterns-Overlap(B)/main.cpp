#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool f[5040][5040] = {0};

int main() {
  int t, k, i, j;
  cin >> t;
  k = 1;
  string temp_str, str1, str2;
  while (t--) {
    cin >> temp_str;
    str1 = "";
    for (int i = 0; i < temp_str.length(); ++i)
      if (temp_str[i] == '*')
        str1 += "****";
      else
        str1.push_back(temp_str[i]);
    cin >> temp_str;
    str2 = "";
    for (int i = 0; i < temp_str.length(); ++i)
      if (temp_str[i] == '*')
        str2 += "****";
      else
        str2.push_back(temp_str[i]);

    memset(f, 0, sizeof f);
    f[0][0] = true;
    for (int i = 0; i <= str1.length(); ++i)
      for (int j = 0; j <= str2.length(); ++j) {
        if (i == 0 && j != 0) {
          f[i][j] = (f[i][j - 1] && str2[j - 1] == '*');
        } else if (i != 0 && j == 0) {
          f[i][j] = (f[i - 1][j] && str1[i - 1] == '*');
        } else if (i != 0 && j != 0) {
          f[i][j] =
              (f[i - 1][j - 1] && (str1[i - 1] == str2[j - 1] ||
                                   str1[i - 1] == '*' || str2[j - 1] == '*'));
          if (str1[i - 1] == '*') f[i][j] = f[i][j] || f[i - 1][j];
          if (str2[j - 1] == '*') f[i][j] = f[i][j] || f[i][j - 1];
        }
      }
    string ans = f[str1.length()][str2.length()] ? "TRUE" : "FALSE";
    cout << "Case #" << k++ << ": " << ans << endl;
  }
  return 0;
}
