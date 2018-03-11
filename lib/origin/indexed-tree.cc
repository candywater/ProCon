#include "vector"

using namespace std;

// 区間木
/*
                      0
            1                     2
      3         4           5           6
  7    8     9    10     11   12    13    14
15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
*/
//区間和の場合
class indexedTree{
  vector<int> v;
public:
  indexedTree(int n){
    //v.clear();
    v = vector<int>(getLength(n), -1);
  }
  //[i, j)
  int getVal(int i, int j){
    return query(i, j, 0, (int)v.size()/2, (int)v.size());
  }
  //val = [m, n)
  int query(int i, int j, int valindex, int m, int n){
    if(i >= n || j <= m) return 0;
    if(m >= i && n <= j) return v[valindex];
    int val_left = query(i, j, valindex*2 + 1, m, (n + m) / 2);
    int val_right= query(i, j, valindex*2 + 2, (n + m) / 2, n);
    //cout << "left: " << m << " " << (n + m) / 2 << " " << val_left << " index:" << valindex*2+1 << endl;
    //cout << "righ: " <<  (n + m) / 2 << " " << (n) << " " << val_right << " index:" << valindex*2+2 << endl;
    return (val_left + val_right);
  }

  void update(int i, int val){
    int len = v.size() / 2 - 1;
    i += len;
    v[i] = val;
    while(i > 0){
      i = (i - 1) / 2;
      v[i] = v[i*2 + 1] + v[i*2 + 2];
    }
  }
  int getLength(int j){
    int i = 1;
    while(i < j) i *= 2;
    return i*2;
  }

}
