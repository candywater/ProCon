###
 * @param {number[]} nums
 * @return {number[][]}
###

###
equal = (a, b) ->
  return if b.length is 0
  # console.log b[0]
  for j, i in a
    return false if (a[i] isnt b[b.length-1][i]);
  return true;
###

originset = ->
  list = new Map();
  {
    push : (arr) ->
      str = arr.join();
      list.set(str, arr);
    toArray: () ->
       arr = [];
       arr.push(i[1]) for i from list;
       arr;
  }

dfs = (nums, pos, isusedlist, res, resarr) -> 
  if pos == nums.length
    tmp = res.slice(0, res.length);
    resarr.push tmp # if not equal(tmp, resarr)
    return;
  # console.log nums[pos] + " pos:" + pos
  for num, i in nums 
    if(not isusedlist[i])
      isusedlist[i] = true;
      res[pos] = num;
      dfs(nums, pos+1, isusedlist, res, resarr)
      isusedlist[i] = false;
  # console.log ""
  null

permuteUnique = (nums) -> 
  nums.sort();
  isusedlist = nums.slice(0, nums.length)
  isusedlist[j] = false for j of isusedlist 
  res = nums.slice(0, nums.length);
  resset = new originset();
  dfs(nums, 0, isusedlist, res, resset);
  resset.toArray();
  
###
test = -> 
  a = [1,2,3];
  b = [];
  b.push(a); 
  b.push(a); 
  a[2] = 66;
  console.log i for i, j in b;
###
# dfs([1,2,1], 0, [false, false, false], [-1, -1, -1], testres)
testres = permuteUnique([1,2,1])
console.log testres

# console.log equal([1,2], [1,2])
# console.log equal([1,3], [1,2])