class Solution {
public:
  string countAndSay(int n) {
    if(n <= 1) return "1";
    string res = "1";
    vector<char> vc;
    vector<int> vn;
    //cout << "res:" <<  res << endl;
    for(int i = 1; i < n; i++){
      count(res, vc, vn);
      //cout << "show vc:" << endl;show(vc);
      //cout << "show vn:" << endl;show(vn);
      //cout << "res:" <<  res << endl;
      trans(res, vc, vn);
    }
    return res;
  }

  void trans(string& in, const vector<char>& vc, const vector<int>& vn){
    in.clear();
    for(size_t i = 0; i < vc.size(); i++){
      in.push_back(vn[i] + '0');
      in.push_back((char)vc[i]);
    }
  }

  void count(const string& in, vector<char>& vc, vector<int>& vn){
    vc.clear();
    vn.clear();
    char c = in[0];
    size_t i = 0, j = 0;
    for(; i < in.size(); i++) {
      if(in[i] == c) continue; //cout << "c:" << c << endl;
      vc.push_back(c);
      vn.push_back(i - j);
      c = in[i];
      j = i;
    }
    vc.push_back(c);
    vn.push_back(i - j);
    c = in[i];
    j = i;
  }
  //debug
  template <class T>
  void show(vector<T>& j){
    for(auto i : j){
      cout << i << " ";
    }
    cout << endl;
  }
};
