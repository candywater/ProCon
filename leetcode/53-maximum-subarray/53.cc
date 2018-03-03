#include "iostream"
#include "vector"
#include "climits"

using namespace std;

class Solution {
public:
  //use 区間木
  /*
                        0
              1                     2
        3         4           5           6
    7    8     9    10     11   12    13    14
15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
  */
  int maxSubArray(vector<int>& nums) {
    int treesize = twotimes(nums.size());
    std::vector<int> v(treesize, -INT_MAX);
    int max;
    for(size_t i = 0; i < nums.size(); i++){
      update(v, i, nums[i]);
    }
    //show(v);
    max = query(0, nums.size(), 0, 0, treesize/2, v);
    //cout << "max:" << max << endl;
    for(size_t i = 0; i < nums.size(); i++){
      int tmp = query(i, nums.size(), 0, 0, treesize/2, v);
      if(max < tmp) max = tmp;
      //cout << "i, j " << i << " " << j << endl;
      //cout << "tmp:" << tmp << endl << endl;
      for(size_t j = nums.size() - 1; j > i; j--){
        tmp = tmp - nums[j];
        if(max < tmp) max = tmp;
      }
    }
    //cout << "max:" << max << endl;
    return max;
  }

  int twotimes(int j){
    int i = 1;
    while(i < j) i *= 2;
    return i*2;
  }

  //val = [m, n)
  int query(int i, int j, int valindex, int m, int n, const vector<int>& v){
    if(i >= n || j <= m) return 0;
    if(m >= i && n <= j) return v[valindex];
    int val_left = query(i, j, valindex*2 + 1, m, (n + m) / 2, v);
    int val_right= query(i, j, valindex*2 + 2, (n + m) / 2, n, v);
    //cout << "left: " << m << " " << (n + m) / 2 << " " << val_left << " index:" << valindex*2+1 << endl;
    //cout << "righ: " <<  (n + m) / 2 << " " << (n) << " " << val_right << " index:" << valindex*2+2 << endl;
    return (val_left + val_right);
  }

  void update(std::vector<int>& v, int i, int val){
    int len = v.size() / 2 - 1;
    i += len;
    v[i] = val;
    while(i > 0){
      i = (i - 1) / 2;
      v[i] = v[i*2 + 1] + v[i*2 + 2];
    }
  }


  //debug
  template <class T>
  void show(std::vector<T> v){
    for(auto i : v)
      cout << i << " ";
    cout << endl;
  }

};

int main(int argc, char const *argv[]) {
  Solution a ;
  std::vector<int> v = {
    -2, 1
    //-2,1,-3,4,-1,2,1,-5,4
    //-2,1,-3,4,-1,2,1,-5
    //1,2,3,4,5,6,7,8
    //0,0,2,3,0,2,2,1
  };
  cout << a.maxSubArray(v) << endl;
  /* code */
  return 0;
}
