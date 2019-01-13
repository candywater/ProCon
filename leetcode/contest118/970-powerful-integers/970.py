import math

class Solution:
  def powerfulIntegers(self, x, y, bound):
    """
    :type x: int
    :type y: int
    :type bound: int
    :rtype: List[int]
    """
    if x == 0 and y == 0 and bound == 0:
      return [0]
    elif bound <= 0:
      return []
    i = 0
    if x > 1:
      i = math.log(bound, x)
    i = math.floor(i)
    j = 0
    if y > 1:
      j = math.log(bound, y)
    j = math.floor(j)
    
    res = set()
    for m in range(i+1):
      for n in range(j+1):
        tmp = pow(x, m) + pow(y, n)
        tmp = math.floor(tmp)
        if tmp <= bound:
          res.add(tmp)
    return list(res)
    
a = Solution
print( a.powerfulIntegers(a,3,5,15) )
print( a.powerfulIntegers(a,1,1,0) )
print( a.powerfulIntegers(a,2,3,10) )
print( a.powerfulIntegers(a,1,2,100) )