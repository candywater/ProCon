#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, y;
  cin >> n >> y;
  int a, b, c;
  a = y / 10000;
  a = a > n ? n : a;
  b = y / 5000;
  b = b > n ? n : b;
  c = y / 1000;
  c = c > n ? n : c;
  int count = 0;
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      int tmp = y - 10000*i - 5000*j;
      tmp /= 1000;
      if(tmp < 0) break;
      if(i+j+tmp != n) continue;
      //printf("%d %d %d\n", i, j, tmp);
      //count += tmp >= 0 && tmp <= c ? 1 : 0;
      if(tmp <= c){
        printf("%d %d %d\n", i, j, tmp);
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  //cout << count << endl;
}
