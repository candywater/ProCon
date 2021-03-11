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

unordered_map<char, int> map;

void add(char c) {
  if (map.count(c) > 0) {
    map[c] += 1;
  } else {
    map[c] = 1;
  }
}

long sum(char c) {
  int csum = map[c];
  int real_sum = 0;
  for (auto i : map) {
    real_sum += i.second;
  }
  return real_sum - csum;
}

long operate(char c) {
  long counter = 0;
  for (auto i = map.begin(); i != map.end(); ++i) {
    if (i->first == c) continue;
    map[c] += i->second;
    counter += i->second;
    i->second = 0;
  }
  return counter;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  // show(map);

  // map = {{'a', 2}, {'b', 3}, {'c', 0}};
  // operate('c');

  // show(map);

  long res = 0;

  char tmp = str[str.size() - 1];
  add(tmp);
  for (long i = str.size() - 2; i >= 0; i--) {
    char t2 = str[i];
    if (t2 == tmp) {
      res += operate(t2);
    } else {
      add(t2);
      tmp = t2;
    }
    check(t2, res);
  }

  cout << res << endl;
}
