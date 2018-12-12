###
@param {number[]} nums
@param {number} target
@return {number[]}

var searchRange = function(nums, target) {
};
###

# example
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]

# [low, high)
binarySearch = (nums, target, low, high) -> 
  #console.log "###: low" + low + " high:" + high
  mid = parseInt (low+high) / 2
  return mid if nums[mid] is target
  return -1 if high - low <= 1
  return binarySearch(nums, target, 0, mid) if nums[mid] > target
  return binarySearch(nums, target, mid+1, high) if nums[mid] < target
  # return -1; 
  
# find End if flg == 1 
# find Front if flg == -1
findFrontOrEnd = (nums, target, pos, flg) ->
  while(pos >= 0) and (pos < nums.length) 
    if nums[pos] is target then pos += flg 
    else break;
  pos - flg;
  

searchRange = (nums, target) -> 
  return [-1, -1] if target < nums[0] or target > nums[-1]
  res = binarySearch(nums, target, 0, nums.length);
  # console.log res
  return [-1, -1] if res is -1 
  end = findFrontOrEnd(nums, target, res, 1);
  front = findFrontOrEnd(nums, target, res, -1);
  [front, end]

# DEBUG
console.log searchRange([5,7,7,8,8,10], 8)
console.log searchRange([5,7,7,8,8,10], 6)
console.log searchRange([1,2,2,4], 3)
console.log searchRange([2,2], 3)
console.log searchRange([2,2], 9)
console.log searchRange([1], 1)
console.log searchRange([1, 3], 1)