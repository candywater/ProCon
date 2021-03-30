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

const double pi = std::acos(-1);

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

const ll WARU = 998244353;
vector<ll> line;
ll res = 0;

// backtrack, TLE
void bt(ll i, bool isSelected, ll min, ll max) {
  if (isSelected) {
    if (line[i] < min) min = line[i];
    if (line[i] > max) max = line[i];
  }
  // printf("[%lld] {%d} %lld %lld \n",i, isSelected, min, max);
  if (i == line.size() - 1) {
    if (min == LLONG_MAX && max == -1) return;
    ll tmp = min * max;
    res = res % WARU + tmp % WARU;
    // printf("[%lld] %lld %lld %lld %lld\n",i, min, max, tmp, res);
    return;
  }
  bt(i + 1, false, min, max);
  bt(i + 1, true, min, max);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 9223372036854775807
  // 998244352 998244352

  // INPUT
  ll n;
  cin >> n;
  line = vector<ll>(n, 0);
  rep(i, n) { cin >> line[i]; }

  // TLE: backtrack
  // bt(0, false, LLONG_MAX, -1);
  // bt(0, true, LLONG_MAX, -1);

  rep(i, n) {
    res += line[i] * line[i] % WARU;
    res = res % WARU;
  }

  // O(n^2)
  // https://www.youtube.com/watch?v=-zB7ZbXl7Nc
  // (a-c) mod c + c mod c = a mod c
  // a*b mod c = (a mod c) * (b) mod c = (a mod c) * (b mod c) mod c
  // nlogn
  // sort(line.begin(), line.end());
  // rep2(i, 0, n - 1) {
  //   ll tmp = 1;
  //   rep2(j, i + 1, n) {
  //     res += line[j] * line[i] % WARU * tmp % WARU;
  //     tmp *= 2;
  //     tmp %= WARU;
  //     res %= WARU;
  //   }
  // }

  // O(n)
  // https://www.youtube.com/watch?v=-zB7ZbXl7Nc
  // reverse version
  // nlogn
  // sort(line.begin(), line.end(), std::greater<ll>());
  sort(line.begin(), line.end());

  ll tmp = 0;
  // printf("%d, %d\n", res, tmp);
  rep2(i, 1, n) {
    tmp = tmp * 2 % WARU + line[i - 1] % WARU;
    res += line[i] * tmp % WARU;
    res %= WARU;
    tmp %= WARU;
    // printf("%d, %d\n", res, tmp);
  }

  cout << res % WARU << endl;
}
