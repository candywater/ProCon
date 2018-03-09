
class Solution {
  int comb_num = 0;
  std::vector<std::vector<string> > res;
public:
  vector<vector<string>> solveNQueens(int n) {
    comb_num = 0;
    std::vector<bool> t(n, false);
    std::vector<int> c(n, -1);
    res.clear();
    //for(int i = 0; i < n; i++) c.push_back(i);
    comb(t, c, 0, n);
    return res;
  }

// in n-queen problem, n cannot be a large number, so I do loop with this kind of for statement, which takes O(n)
// otherwise, maybe I would use stack or something else to store numbers, and then for statement, which takes less than O(n)
  void comb(vector<bool>& t, std::vector<int>& c, int count, int n){
    if(count == n){
      isCorrect(c);
      //show(c);
      //cout << "comb_num:" << comb_num << endl;
    }

    for(size_t i = 0; i < t.size(); i++){
      if(t[i]) continue;
      t[i] = true;
      c[count] = (int)i;
      comb(t, c, count + 1, n);
      t[i] = false;
    }
  }

  void isCorrect(const std::vector<int>& c){
    for(size_t i = 0; i < c.size(); i++){
      for(size_t j = i + 1; j < c.size(); j++){
        if(!isPossible(i, c[i], j, c[j])) return;
      }
    }
    addRes(c);
    comb_num++;
  }

  bool isPossible(int a, int b, int x, int y){
    return ((a-x) != (b-y)) && ((x-a) != (b-y));
  }

  void addRes(const std::vector<int> c){
    res.push_back(vector<string>());
    for(size_t i = 0; i < c.size(); i++){
      string tmp;
      for(size_t j = 0; j < c.size(); j++){
        if(j == c[i]) tmp.push_back('Q');
        else tmp.push_back('.');
      }
      res[comb_num].push_back(tmp);
    }
  }

  template <class T>
  void show(std::vector<T>& c){
    for(size_t i = 0; i < c.size(); i++){
      cout << i << "," << c[i] << " ";
    }
    cout << endl;
  }
};
