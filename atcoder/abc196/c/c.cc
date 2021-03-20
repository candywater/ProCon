#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define rep(i, n) for (size_t i = 0; i < (size_t)(n); i++)
#define rep2(i, s, n) for (size_t i = (s); i < (size_t)(n); i++)
#define rep3(i, s, n) for (ll i = (s); i >= (ll)(n); i--)

using namespace std;
using ll = long long;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

template <typename T>
void show(T a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void showmatrix(T a) {
  for (auto j : a) {
    for (auto i : j) {
      cout << i;
    }
    cout << endl;
  }
  cout << endl;
}
void check(int i = 0) { cout << "checkpoint:[" << i << "]" << endl; }

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;

  ll res = 0;
  {
    int count = 9;
    ll m = n;
    m = m / 100;
    while (m > 0) {
      res += count;
      m = m / 100;
      count *= 10;
    }
  }

  auto isdoubled = [](string& s) -> bool {
    ll len = s.size() / 2;
    rep(i, len) {
      if (s[i] != s[i + len]) return false;
    }
    return true;
  };

  string num = to_string(n);
  if (num.size() % 2 == 0) {
    res = 0;
    string before = num.substr(0, num.size() / 2);
    string after = num.substr(num.size() / 2, num.size());
    res = stoll(before);
    if (after < before) {
      res--;
    }
  }

  /*
  2:9
  4:90
  6:900
  */
  // ll m = n;
  // ll res = 0;

  // m = n;
  // ll digitcount = 0;
  // while (m > 0) {
  //   digitcount++;
  //   m /= 10;
  // }

  // if (digitcount % 2 == 0) {
  //   string num = to_string(n);
  //   ll tmp = num[num.size() / 2 - 1] - '0';
  //   ll zerocount = 10;
  //   rep3(i, num.size() / 2 - 2, 0) {
  //     if (i == 0) {
  //       tmp += (num[i] - '0') * zerocount;
  //     } else {
  //       tmp += (num[i] - '0' + 1) * zerocount;
  //     }
  //     zerocount *= 10;
  //   }
  //   string before = num.substr(0, num.size() / 2);
  //   string after = num.substr(num.size() / 2, num.size());
  //   if (after < before) {
  //     res += tmp - 1;
  //   } else {
  //     res += tmp;
  //   }
  //   // cout << tmp << endl;
  // } else {
  //   int count = 9;
  //   m = n;
  //   m = m / 100;
  //   res = 0;
  //   while (m > 0) {
  //     res += count;
  //     m = m / 100;
  //     count *= 10;
  //   }
  // }
  cout << res << endl;
}
