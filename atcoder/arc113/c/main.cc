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
void check(long i = 0) { cout << "checkpoint:[" << i << "]" << endl; }
void check(int i = 0) { cout << "checkpoint:[" << i << "]" << endl; }
void check(char i = ' ') { cout << "checkpoint:[" << i << "]" << endl; }
void check(char i = ' ', int j = 0) {
  cout << "checkpoint:[" << i << "," << j << "]" << endl;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  if (str.size() <= 0) return 0;

  // https://atcoder.jp/contests/arc113/editorial/710
  // block: aaaa in aaaasss
  // block: bbb in abdbbbd

  vector<int> pos;
  vector<char> block;
  vector<int> blocklen;

  // collect blocks
  char tmp = str[0];
  for (int i = 1; i < str.size(); i++) {
    if (tmp == str[i]) {
      pos.push_back(i - 1);
      block.push_back(str[i]);
      int len = 2;
      while (tmp == str[++i]) {
        len++;
      }
      blocklen.push_back(len);
    }
    if (tmp != str[i]) {
      tmp = str[i];
    }
  }

  show(pos);
  show(block);
  show(blocklen);

  int res = 0;

  int j = 0;
  tmp = block[j];
  for (int i = pos[j] + blocklen[j]; i < str.size(); i = pos[j] + blocklen[j]) {
    while (i < str.size() && tmp != str[i++]) {
      res++;
    }
    j++;
    while (j < block.size() && (block[j] == block[j - 1] || pos[j] < i)) {
      j++;
    }
    tmp = block[j];
  }

  // // analyze blocks
  // // if same blocks, merge them
  // for (int i = 0; i + 1 < pos.size(); i++) {
  //   if (block[i] == block[i + 1]) {
  //     blocklen[i] += blocklen[i + 1];
  //     pos[i + 1] = -1;
  //     block[i + 1] = '\0';
  //     blocklen[i + 1] = -1;
  //   }
  // }

  // // erase them
  // for (int i = pos.size() - 1; i >= 0; i--) {
  //   if (pos[i] == -1) {
  //     pos.erase(pos.begin() + i);
  //     block.erase(block.begin() + i);
  //     blocklen.erase(blocklen.begin() + i);
  //   }
  // }

  // long res = 0;
  // for (int i = 0; i + 1 < pos.size(); i++) {
  //   int left = pos[i];
  //   int right = pos[i + 1];
  //   res += (right - left) - blocklen[i];
  // }
  // int left = pos[pos.size() - 1];
  // int right = str.size();
  // cout << "left:" << left << " right:" << right << endl;
  // res += (right - left) - blocklen[blocklen.size() - 1];

  cout << res << endl;
}
