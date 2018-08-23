#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x < -INT_MAX) return 0;

        int res = 0;
        bool minus = true;
        if( x > 0 )
          minus = false;
        else
          x = -x;
        //cout << res << " " << x << endl;
        while(x >= 10){
          if(res > INT_MAX/10 || (res == INT_MAX/10 && x > INT_MAX%10)) return 0;
          res = res*10 + (x%10);
          x /= 10;
          //cout << res << " " << x << endl;
        }
        //cout << res << " " << x << endl;
        if(res > INT_MAX/10 || (res == INT_MAX/10 && x > INT_MAX%10)) return 0;
        res = res*10 + (x%10);
        //cout << res << " " << x << endl;
        if(minus)
          res = -res;
        return res;
    }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution a;
  cout << INT_MAX << endl;
  cout << a.reverse(1534236469) << endl;
  return 0;
}
