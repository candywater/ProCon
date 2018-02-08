#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string r(s);
        reverseStr(s, r);
        int epos = 0;
        int lcs = 0;
        int len = s.size();
        std::vector<int> t(len);

        for(int i = 0; i < len; i++){
          if(s[i] == r[0]) t[i] = 1;
          else t[i] = 0;
        }

        for(int j = 1; j < len; j++){
          //show(t);
          for(int i = len - 1; i > 0; i--){
            if(s[i] == r[j]){
              //cout << s[i] << " " << i << " " << j << endl;
              t[i] = t[i - 1] + 1;
              //start pos = reverse_str's end pos
              if(t[i] > lcs && i + 1 - t[i] == len - j - 1){
                lcs = t[i];
                epos = i;
              }
            }
            else t[i] = 0;
          }
          if(s[0] == r[j]) t[0] = 1;
          else t[0] = 0;
        }
        //show(t);
        /*cout << s << endl;
        cout << r << endl;
        cout << "lcs:" << lcs << endl;
        cout << "epos:" << epos << endl;*/
        return lcs == 0 ? string(s, 0, 1) : string(s, epos - lcs + 1, lcs);
    }

    void show(vector<int>& t){
      for(auto i : t)
        cout << " " << i ;
      cout << " " << endl;
    }

    void reverseStr(const string& s, string& r){
      int len = s.size();
      for(int i = 0; i < len; i++){
        r[len - i - 1] = s[i];
      }
    }
};

int main(){
  Solution a;
  cout << a.longestPalindrome("gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv") << endl;

  cout << a.longestPalindrome("banana") << endl;
  return 0;
}
