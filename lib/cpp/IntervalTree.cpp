//セグメントツリー
//区間木

class IntervalTree{
public:
  int len = 0;
  vector<int> tree;
  IntervalTree(vector<int>& a){
    len = getTreeSize(a.size());
    tree = vector<int>(len*2, 0);
    for(int i = 0; i < a.size(); i++){
      update(i, a[i]);
    }
  }
  int find(int a, int b){
    return find_interval(a, b, 0, len, 0);
  }
private:
  int find_interval(int a, int b, int start, int end, int index){
    if(a >= end || b <= start) return 0;
    if(a <= start && b >= end) return tree[index];
    return 
      find_interval(a, b, start, (start+end)/2, index*2+1)
      + find_interval(a, b, (start+end)/2, end, index*2+2);
  }
  void update(int index, int a){
    index += len - 1;
    tree[index] = a;
    while(index > 0){
      index = (index-1)/2;
      tree[index] = tree[index*2+1] + tree[index*2+2];
      } 
    }
  }
  int getTreeSize(int a){
    int i = 1;
    while(i < a)
      i *= 2;
    return i;
  }
}