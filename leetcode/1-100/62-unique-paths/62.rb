# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def unique_paths(m, n)
  dp = Array.new(m).map{Array.new(n, 0)};
  for i in 0 .. m-1 do dp[i][0] = 1 end;
  for j in 0 .. n-1 do dp[0][j] = 1 end;
  return count_paths(m-1, n-1, m, n, dp);
  # return count_by_math(m-1, n-1);
end

# dp
# https://leetcode.com/problems/unique-paths/discuss/22953/Java-DP-solution-with-complexity-O(n*m)
def count_paths(x, y, m, n, dp)
  # puts "x:#{x} y:#{y}"
  if x >= m or y >= n then return 0 end;
  if dp[x][y] != 0 then return dp[x][y] end;
  dp[x][y] = \
  count_paths(x, y-1, m, n, dp) \
  + count_paths(x-1, y, m, n, dp);
  return dp[x][y];
end

# math
# https://leetcode.com/problems/unique-paths/discuss/22958/Math-solution-O(1)-space
def count_by_math(m, n)
  res = factorial(m+n);
  res /= factorial(m);
  res /= factorial(n);
  return res;
end

# https://stackoverflow.com/questions/2434503/ruby-factorial-function/37352690#37352690
def factorial(m)
  i = 1;
  res = 1;
  (m-1).times do (i+=1; res*=i;) end;
  return res;
end
# p factorial(3);

p unique_paths(2,3)
p unique_paths(7,3)
p unique_paths(23,12)

=begin
# time limit over
def count_paths(x, y, m, n)
  if x == m-1 and y == n-1 
    return 1;
  elsif x > m or y > n
    return 0;
  end
  return count_paths(x + 1, y, m, n) + count_paths(x, y+1, m, n);
end
=end