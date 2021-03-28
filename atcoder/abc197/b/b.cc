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

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<vector<bool> > matrix(h, vector<bool>(w, false));

  char c;
  int count = 0;
  int maxmount = h * w;
  while (cin >> c) {
    int _x = count / w;
    int _y = count % w;
    matrix[_x][_y] = c == '#' ? true : false;
    count++;
    if (count >= maxmount) break;
    // printf("%d %d\n", _x, _y);
  }
  // showmatrix(matrix);


  count = 0;
  x = x - 1;
  y = y - 1;
  rep3(i, x, 0) {
    if (matrix[i][y]) {
      break;
    }
    count++;
  }
  rep2(i, x + 1, h) {
    if (matrix[i][y]) {
      break;
    }
    count++;
  }
  rep3(i, y, 0) {
    if (matrix[x][i]) {
      break;
    }
    count++;
  }
  rep2(i, y + 1, w) {
    if (matrix[x][i]) {
      break;
    }
    count++;
  }
  cout << count - 1 << endl;
}
