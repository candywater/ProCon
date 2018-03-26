//OMG
//https://leetcode.com/problems/integer-to-roman/discuss/6274/Simple-Solution
class Solution {
    //I,  V,  X,  L,  C,     D,     M
    //1 	5 	10 	50 	100 	500 	1000
    const vector<string> one = {
      "", "I", "II", "III", "IV",
      "V", "VI", "VII", "VIII", "IX"
    };
    const vector<string> two = {
      "", "X", "XX", "XXX", "XL",
      "L", "LX", "LXX", "LXXX", "XC"
    };
    const vector<string> three = {
      "", "C", "CC", "CCC", "CD",
      "D", "DC", "DCC", "DCCC", "CM"
    };
    const vector<string> four = {
      "", "M", "MM", "MMM"
    };

public:
  string intToRoman(int num) {
    string res;
    if(num > 3999 || num < 1) return res;
    res.append(four[num/1000]);
    num %= 1000;
    res.append(three[num/100]);
    num %= 100;
    res.append(two[num/10]);
    num %= 10;
    res.append(one[num]);
    return res;
  }
};
