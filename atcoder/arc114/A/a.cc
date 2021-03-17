#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> dx = {0, 1, 0, -1};
vector<ll> dy = {1, 0, -1, 0};

template <typename T>
void show(T a) {
  for (auto i : a) {
    cout << i << "\t";
  }
  cout << endl;
}
template <typename T>
void showmatrix(T a) {
  for (auto j : a) {
    for (auto i : j) {
      cout << i << "\t";
    }
    cout << endl;
  }
  cout << endl;
}
void check(ll i = 0) { cout << "checkpoint:[" << i << "]" << endl; }

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a == b)
    return a;
  else
    return gcd(a - b, b);
}

bool isPrime(ll num) {
  if (num == 1) return false;
  if (num == 2) return true;
  ll half = num / 2 + 1;
  for (ll i = 2; i <= half; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

vector<ll> primes;
set<int> list;
ll finalres = LLONG_MAX;

void backtrack(int index, const vector<set<int>> table) {
  // cout << res << endl;
  // cout << primes.size() << endl;
  // cout << index << endl;
  if (index >= primes.size()) {
    for (int i = 0; i < table.size(); i++) {
      bool flg = false;
      for (int j : table[i]) {
        if (list.count(j) > 0) {
          flg = true;
          break;
        }
      }
      if (!flg) {
        return;
      }
    }
    ll res = 1;
    for (int i : list) {
      if (LLONG_MAX / res > i)
        res *= i;
      else
        return;
    }
    if (res < finalres) finalres = res;
    return;
  }

  backtrack(index + 1, table);
  list.insert(primes[index]);
  backtrack(index + 1, table);
  list.erase(primes[index]);
  return;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (ll i = 2; i < 51; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }

  finalres = 1;
  for (int i : primes) {
    finalres *= i;
  }

  // cout << gcd(49, 14) << endl;
  // cout << gcd(7, 7) << endl;

  ll n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<set<int>> table(n, set<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < primes.size(); j++) {
      if (gcd(nums[i], primes[j]) > 1) {
        table[i].insert(primes[j]);
      }
    }
  }

  backtrack(0, table);

  // it is possible that
  // a: 2x3
  // b: 3
  // res: 3

  // showmatrix(table);
  // show(primes);
  // show(set);

  cout << finalres << endl;
}
