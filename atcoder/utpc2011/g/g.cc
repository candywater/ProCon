#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}

// a <= b <= c <= d <= e <= f
bool canTriangle(long long a, long long b, long long c, long long d, long long e, long long f){
  return  (a+b >c && d+e > f)
        ||(a+b >e && c+d > f)
        ||(a+b >f && c+d > e)
        ||(a+c >d && b+e > f)
        ||(a+c >e && b+d > f)
        ||(a+c >f && b+d > e)
        ||(a+d >e && b+c > f)
        ||(a+d >f && b+c > e)
        ||(a+e >f && b+c > d);
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n;
  long long res = 0;
  cin >> n;
  vector<long long> a(n, 0);
  vector<long long> mem(n, 0);
  for(long long& i: a){
    cin >> i;
  }
  sort(a.begin(), a.end());
  //show(a);

  //https://atcoder.jp/contests/utpc2011/submissions/3413
  //https://www.utpc.jp/2011/slides/triangles.pdf
  for(long long i = 2; i < a.size(); i++){
    if(a[i-2] + a[i-1] > a[i]){
      mem[i] = a[i] + a[i-1] + a[i-2];
    }
    else
      mem[i] = mem[i-1];
  }
  
  //show(mem);
  
  for(long long i = a.size()-1; i >= 5; i--){
    if(a[i-2] + a[i-1] > a[i] && mem[i-3] > 0){
      res = max(res, a[i-2]+a[i-1]+a[i]+mem[i-3]);
    }
    if(canTriangle(a[i-5], a[i-4], a[i-3], a[i-2], a[i-1], a[i])){
      long long tmp = a[i-5]+ a[i-4]+ a[i-3]+ a[i-2]+ a[i-1]+ a[i];
      res = max(res, tmp);
    }
  }
  cout << res << endl;

}
