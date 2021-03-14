#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

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

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const long long LEVEL = 1000;

  const long long i1 = LEVEL;
  const long long i2 = LEVEL * LEVEL;
  const long long i3 = LEVEL * LEVEL * LEVEL;
  const long long i4 = LEVEL * LEVEL * LEVEL * LEVEL;
  const long long i5 = LEVEL * LEVEL * LEVEL * LEVEL * LEVEL;
  const long long i6 = LEVEL * LEVEL * LEVEL * LEVEL * LEVEL *
                       LEVEL;  // 1,000,000,000,000,000,000
  const long long n1 = 999;
  const long long n2 = 999999;
  const long long n3 = 999999999;
  const long long n4 = 999999999999;
  const long long n5 = 999999999999999;
  const long long n6 = 999999999999999999;

  long long n;
  cin >> n;

  long long count = 0;
  if (n >= i1) {
    count += n - n1;
  }
  if (n >= i2) {
    count += n - n2;
  }
  if (n >= i3) {
    count += n - n3;
  }
  if (n >= i4) {
    count += n - n4;
  }
  if (n >= i5) {
    count += n - n5;
  }

  cout << count << endl;
}