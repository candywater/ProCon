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

const string NG = "UNSATISFIABLE";

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  long long w;
  cin >> a >> b >> w;

  long long min = LLONG_MAX;
  long long max = -1;

  w *= 1000;

  // an <= w <= bn
  for (int i = 1; i <= 1e6; i++) {
    if (a * i <= w && w <= b * i) {
      if (i >= max) max = i;
      if (i <= min) min = i;
    }
  }

  if (max == -1 || min == LLONG_MAX) {
    cout << NG << endl;
  } else {
    cout << min << " " << max << endl;
  }
}
