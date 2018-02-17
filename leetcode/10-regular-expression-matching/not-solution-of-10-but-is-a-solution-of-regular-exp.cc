#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  //use BNF
  //https://dai1741.github.io/maximum-algo-2012/docs/parsing/
  /*
    <expr> ::= <term>[('.')<term>]*
    <term> ::= <str>[('*')<term>]*
    <str> ::= '.'と‘*’以外の文字列[<expr>]*
  */
  /*
  "a*ab"
  "a*b"
  correct answer is true but leetcode got a false.......OMG
  it should get a greedy answer.but....that's ok
  */
    bool isMatch(string s, string r) {
      return expr(s, r, 0, 0);
    }

    bool expr(string s, string r, size_t spos, size_t rpos){
      //cout << "[str] " << "s:" << s << " r:" << r << " spos:" << spos << " rpos:" << rpos << endl;
      if(spos >= s.size() && rpos >= s.size()) return true;
      if(spos >= s.size() || rpos >= s.size()) return false;
      if(r[rpos] == '.')
        return term(s, r, spos + 1, rpos + 1);
      return term(s, r, spos, rpos);
    }

    bool term(string s, string r, size_t spos, size_t rpos){
      //cout << "[expr] " << "s:" << s << " r:" << r << " spos:" << spos << " rpos:" << rpos << endl;
      if(spos >= s.size() && rpos >= s.size()) return true;
      if(spos >= s.size() || rpos >= s.size()) return false;
      size_t rnext = rpos < r.size() - 1 ? rpos + 1 : rpos;
      while(r[rpos] == '*' && r[rnext] != s[spos]) spos++;
      if(r[rpos] == '*')
        return str(s, r, spos, rpos + 1);
      else return str(s, r, spos, rpos);
    }

    bool str(string s, string r, size_t spos, size_t rpos){
      //cout << "[term] " << "s:" << s << " r:" << r << " spos:" << spos << " rpos:" << rpos << endl;
      if(spos >= s.size() && rpos >= s.size()) return true;
      if(spos >= s.size() || rpos >= s.size()) return false;
      if(r[rpos] == '.' || r[rpos] == '*')
        return expr(s, r, spos, rpos);
      else if(r[rpos] == s[spos])
        return expr(s, r, spos + 1, rpos + 1);
      else
        return false;
    }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution a;
  /*cout << a.isMatch("aa", "aa") << endl;
  cout << a.isMatch("aa","a") << endl;// → false
  cout << a.isMatch("aa","aa") << endl;// → true
  cout << a.isMatch("aaa","aa") << endl;// → false
  cout << a.isMatch("aa", "a*") << endl;// → true
  cout << a.isMatch("aa", ".*") << endl;// → true
  cout << a.isMatch("ab", ".*") << endl;// → true*/
  cout << a.isMatch("aab", "c*a*b") << endl;// → true
  return 0;
}
