#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
void show(T a) {
  for (auto i : a) {
    cout << i.first << " " << i.second << " ";
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
void check(long i = 0) { cout << "checkpoint:[" << i << "]" << endl; }
void check(int i = 0) { cout << "checkpoint:[" << i << "]" << endl; }
void check(char i = ' ') { cout << "checkpoint:[" << i << "]" << endl; }
void check(char i = ' ', int j = 0) {
  cout << "checkpoint:[" << i << "," << j << "]" << endl;
}

unordered_map<char, long long> map;

void setMapZero() {
  for (auto &i : map) {
    i.second = 0;
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  if (str.size() < 3) return 0;

  for (int i = 0; i < 26; i++) {
    map.insert({i + 'a', 0});
  }

  // https://atcoder.jp/contests/arc113/editorial/710
  // https://atcoder.jp/contests/arc113/submissions/20811170

  long long res = 0;

  map[str.back()] += 1;
  for (long long i = str.size() - 2; i >= 0; i--) {
    map[str[i]] += 1;
    if (str[i] == str[i + 1]) {
      long long righthand = str.size() - i;
      res += righthand - map[str[i]];
      setMapZero();
      map[str[i]] = righthand;
    }
  }

  cout << res << endl;
}
