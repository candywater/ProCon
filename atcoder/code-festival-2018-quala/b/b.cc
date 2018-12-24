#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

template<typename T> 
void showpair(T a){
  for(auto i : a){ cout << i.first << "," << i.second << " "; }
  cout << endl;
}

// leetcode 56と似ている
int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m, a, b, big, tmp1, tmp2;
  vector<pair<int, int> > list;
  vector<pair<int, int> > range;
  
  cin >> n >> m >> a >> b;
  big = a > b ? a : b;
  while(cin >> tmp1 >> tmp2){
    list.push_back({tmp1, tmp2});
  }
  
  auto sortmethod = [](pair<int, int> a, pair<int, int>b){
    if(a.first == b.first)
      return a.second > b.second;
    else
      return a.first < b.first;
  };
  
  /* [] から　[)に変換 <- 間違い、アルゴリズムも[]
  for(auto i : list){
    i.second += 1;
  }*/
  
  //showpair(list);
  sort(list.begin(), list.end(), sortmethod);
  //showpair(list);
  
  tmp1 = list.begin()->first;
  tmp2 = list.begin()->second;
  for(auto i : list){
    if(i.first > tmp2){
      range.push_back({tmp1, tmp2});
      tmp1 = i.first;
      tmp2 = i.second;
    }
    else if(i.second > tmp2){
        tmp2 = i.second;
      }
    //cout << tmp1 << "-" << tmp2 << "  i:" << i.first << "-" << i.second << endl;
  }
  range.push_back({tmp1, tmp2});
  
  int number_a = 0;
  for(auto i : range){
    number_a += (i.second - i.first + 1);
  }
  
  //showpair(range);
  cout << number_a*a + (n-number_a)*big << endl;
  
  return 0;
}
