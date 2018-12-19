#include <iostream>
#include <vector>
#include <string>
#include <boost/unordered_map.hpp>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    boost::unordered_map<vector<int>, vector<string> > map;
    for(auto str : strs){
      vector<int> list(26, 0);
      for(char i : str){
        list[i-'a'] += 1; 
      }
      if(map.count(list) == 0)
        map.insert({list, vector<string>()});
      map[list].push_back(str);
    }
    vector< vector<string> > res;
    for(auto itr : map)
      res.push_back(itr.second);
    return res;
  }
};

int main(){
  Solution a;
  vector<string> list = {"aaa", "bba", "abb", "aba", "bab"};
  vector< vector<string> > res = a.groupAnagrams(list);
  for(vector<string>& j : res){
    for(string& i : j)
      cout << i << " ";
    cout << endl;
  }
  
  //unordered_map<int, vector<int> > dd;
  //cout << dd[2] << endl;
  /*
    
  */
  return 0;
}