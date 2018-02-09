#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        int len = s.size();
        vector<string> vstr(numRows,string());

        int i = 0;
        string res;

        while(i < len){
            for(int j = 0; j < numRows && i < len; j++){
                vstr[j].push_back(s[i++]);
            }
            for(int j = numRows - 2; j >= 1 && i < len; j--){
                vstr[j].push_back(s[i++]);
            }
        }

        for(int j = 0; j < numRows; j++){
            //cout << vstr[j] << ":" << vstr[j].size() << endl;
            res.append(vstr[j]);
            //cout << "res:" << res << endl;
        }

        //cout << "end:" << res << endl;
        return res;
    }
};

int main(){
  Solution a;
  cout << a.convert("1234567890", 3) << endl;
  return 0;
}
