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

const string ODD = "Odd";
const string SAME = "Same";
const string EVEN = "Even";

bool isPrime(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void calc(ll n) {
  if (n == 1) {
    cout << ODD << endl;
  } else if (n == 2) {
    cout << SAME << endl;
  } else if (n % 2 != 0) {
    cout << ODD << endl;
  } else if (n % 4 == 0) {
    cout << EVEN << endl;
  } else {
    cout << SAME << endl;
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // unordered_set<ll> primes;

  // check();

  // rep2(i, 998244352, 998244354){
  //   if(isPrime(i)){
  //     primes.insert(i);
  //     cout<<i<<" ";
  //   }
  // }

  // check();

  // ll t;
  // cin >> t;
  // if(primes.count(t)>0){
  //   cout<<"isprime";
  // }
  // check();

  ll t, n;
  cin >> t;
  rep(i, t) {
    cin >> n;
    calc(n);
  }
}
