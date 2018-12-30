#include <iostream>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  int res;
  if(c < a+b)
    res = c + b;
  else{
    if( c <= b )
      res = c + b;
    else if( c <= a) // c > b
      res = c + b;
    else if ( c >= a + b + 1)// c > b && c > a
      res = a + b + 1 + b ;
    else // a or b < c <= a + b
      res = c + b;
  }
  cout << res << endl;
}
