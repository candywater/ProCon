#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string list2str(vector<int>& list){
    string res = "";
    for(int i = 0; i < list.size(); i++){
      res.append(to_string(list[i]));
      res.push_back(',');
    }
    return res;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > map;
    for(auto str : strs){
      vector<int> list(26, 0);
      for(char i : str){
        list[i-'a'] += 1; 
      }
      string key = list2str(list);
      if(map.count(key) == 0)
        map.insert({key, vector<string>()});
      map[key].push_back(str);
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
  
  return 0;
}