#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  //linear solution
  //follow https://leetcode.com/problems/house-robber/discuss/55681/Java-O(n)-solution-space-O(1)
  int rob(vector<int>& nums) {


    //eg: [100, 1, 1, 100]
    //it can be divided into small problems
    //as new selection and old selection which like
    // old selection: [0] ~ [1]
    // new selection: [3] ~

    // eg: [0, 1, 2, 3, 4, 5, 6]
    // (1)
    // old selection: [0] ~ [0]
    // new selection: [2] ~
    // (2)
    // old selection: [0] ~ [1]
    // new selection: [3] ~
    // (3)
    // old selection: [0] ~ [2]
    // new selection: [4] ~

    // in case (3), as u know old selection is the best selection,
    // and to make new selection a best choice,
    // u should check below
    // if [4] > [3] then do not select [3], no need to think about old seleciton
    // otherwise choose [0] ~ [3] as a new old selection,
    // which has already calculated before this turn

    //so...

    int oldsel = 0;//presious best selection, at current index minus 2
    int tmpsel = 0;//template best selection, at current index minus 1
    int newsel = 0;//template new best selection, at current index

    for(int i = 0; i < (int)nums.size(); i++){
      oldsel = tmpsel;//select before current
      tmpsel = oldsel > newsel ? oldsel : newsel;
      newsel = oldsel + nums[i];//select current
      //cout << oldsel << " " << tmpsel << " " << newsel << endl;
    }

    return tmpsel > newsel ? tmpsel : newsel;

  }
};

int main(int argc, char const *argv[]) {
  Solution a;
  vector<int> v = {
    2,3,2
  };
  cout << a.rob(v) << endl;
  return 0;
}
