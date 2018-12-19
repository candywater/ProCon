
"use strict";
# ordinary binary search 
# as ascending sorted array
binary_search = (low, high, value, list) ->
  mid = parseInt( (parseInt(high) + parseInt low) / 2 )
  # console.log low + " " + high
  # console.log "mid: " + (parseInt(high) + parseInt low)/2
  if value is list[mid] then return mid;
  if high - low <= 1 then return -1;
  if value < list[mid] 
    return binary_search(low, mid, value, list);
  else if value > list[mid]
    return binary_search(mid+1, high, value, list);
# unit debug
# list = [1,2,3,4,5,6,7]
# console.log binary_search(0,6,3,list)
# console.log binary_search(0,6,9,list)

find_start_pos = (list) ->
  for i of list
    return i if list[i] < list[(i-1+list.length)%list.length]
  return 0;
# unit test
# list = [3,4,5,1,2]
# list2 = [1,2,3,4]
# list3 = [2,3,4,1]
# console.log find_start_pos(list)
# console.log find_start_pos(list2)
# console.log find_start_pos(list3)

# change_pos = (pos, minus, len) => (pos-minus+len)%len

###
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
###
search = (nums, target)->
  startpos = find_start_pos(nums);
  res = binary_search(0, startpos, target, nums);
  res = binary_search(startpos, nums.length, target, nums) if res is -1;
  res

list = [4,5,6,7,0,1,2]
console.log search list, 6
list = []
console.log search list, 5