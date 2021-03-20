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
  // 
  cout << res << endl;
}
