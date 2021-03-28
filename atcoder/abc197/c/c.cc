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
#define rep3(i, s, n) for (long long i = (s); i >= (long long)(n); i--)

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

ll minxor = LLONG_MAX;
int n;
vector<ll> table;

// 2^20 = 1024x1024 = 10^6
// or < 2^30, ll >= 2^32
void bt(int index, vector<bool>& split) {
  if (index >= n - 1) {
    ll or_num = table[0];
    ll xor_num = LLONG_MAX;
    rep2(i, 1, table.size()) {
      if (split[i - 1] == true) {
        if (xor_num == LLONG_MAX) {
          xor_num = or_num;
        } else {
          xor_num ^= or_num;
        }
        // cout << "xor_num:" << xor_num << endl;
        or_num = LLONG_MAX;
      }
      if (or_num == LLONG_MAX) {
        or_num = table[i];
      } else {
        or_num |= table[i];
      }
      // cout << "or_num:" << or_num << endl;
    }
    if (xor_num == LLONG_MAX) {
      xor_num = or_num;
    } else {
      xor_num ^= or_num;
    }
    // rep(i, split.size()) { cout << split[i]; }
    // cout << endl;
    // cout << "xor:" << xor_num << endl;
    if (xor_num < minxor) minxor = xor_num;
    return;
  }
  split[index] = true;
  bt(index + 1, split);
  split[index] = false;
  bt(index + 1, split);
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  table = vector<ll>(n);
  vector<bool> split(n - 1, false);
  rep(i, table.size()) { cin >> table[i]; }

  bt(0, split);

  // or: |, xor: ^
  cout << minxor << endl;
};