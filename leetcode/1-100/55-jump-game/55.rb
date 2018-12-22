# @param {Integer[]} nums
# @return {Boolean}
def can_jump(nums)
  nums[nums.length-1] = 0;
  can_jump_recur(0, nums)
  return nums[nums.length-1] >= nums.length-1
end

def can_jump_recur(pos, nums)
  return if pos >= nums.length
  nums[pos] += pos;
  if pos > 0
    nums[pos] = nums[pos-1] if nums[pos] < nums[pos-1]
  end
  return if nums[pos] <= pos;
  can_jump_recur(pos+1, nums)
end

n = [2,3,1,1,4]
p n
p can_jump(n)
p n 

p ""
n = [3,2,1,0,4]
p can_jump(n)

p ""
n = [2,0,0]
p can_jump(n)
p n 


p ""
n = [2,0]
p can_jump(n)
p n 