#include "iostream"
#include "unordered_map"

using namespace std;

int main(int argc, char const *argv[]) {

  unordered_map<int, int> t;
  int x, a, b, c;//a: 500, b: 100, c: 50
  cin >> a >> b >> c >> x;

  //O(n^2)
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      int tmp = i * 500 + j * 100;
      if(tmp <= 20000){
        t[tmp] = t.count(tmp) > 0 ? t[tmp] + 1 : 0;
      }
    }
  }

  //for(auto i : t)
    //cout << i.first << " " << i.second << endl;

  int res = 0;
  for(int i = 0; i <= c; i++){
    int tmp = x - i*50;
    int times = t[tmp];
    if(times != 0)
      res += times ;
  }

  cout << res << endl;

  return 0;
}
