# @param {Integer[][]} matrix
# @return {Integer[]}
def spiral_order(matrix)
  res = [];
  # spiral(0, 0, matrix, 0, res);
  $direct = 0;
  spiral_better(0, 0, matrix, res);
  return res;
end

# better way to write it
$dx = [0, 1, 0, -1];
$dy = [1, 0, -1, 0];
$direct = 0;
# https://leetcode.com/problems/spiral-matrix/solution/ 
# Approach 1: Simulation
def spiral_better(x, y, matrix, res)
  if x >= matrix.length \
  or y >= matrix[0].length \
  or x < 0 \
  or y < 0 \
  or matrix[x][y] == 'x'
    $direct = ($direct+1) % 4;
    return
  end
  res.push matrix[x][y];
  matrix[x][y] = 'x';

  spiral_better(x + $dx[$direct], y + $dy[$direct], matrix, res)
  spiral_better(x + $dx[$direct], y + $dy[$direct], matrix, res)
  spiral_better(x + $dx[$direct], y + $dy[$direct], matrix, res)
  spiral_better(x + $dx[$direct], y + $dy[$direct], matrix, res)
  # 残念なことに、ここを一行に収まる方法は思いつかない。
end 


# direction 0, 1, 2, 3
def spiral(x, y, matrix, direction, res)
  if x >= matrix.length then return end
  if y >= matrix[0].length then return end
  if x < 0 then return end
  if y < 0 then return end
  if matrix[x][y] == 'x' then return end
  res.push matrix[x][y];
  matrix[x][y] = 'x';
  if direction == 0
    spiral(x, y+1, matrix, 0, res)
    spiral(x+1, y, matrix, 1, res)
    spiral(x, y-1, matrix, 2, res)
    spiral(x-1, y, matrix, 3, res)
  end
  if direction == 1 
    spiral(x+1, y, matrix, 1, res)
    spiral(x, y-1, matrix, 2, res)
    spiral(x-1, y, matrix, 3, res)
    spiral(x, y+1, matrix, 0, res)
  end
  if direction == 2
    spiral(x, y-1, matrix, 2, res)
    spiral(x-1, y, matrix, 3, res)
    spiral(x, y+1, matrix, 0, res)
    spiral(x+1, y, matrix, 1, res)
  end
  if direction == 3
    spiral(x-1, y, matrix, 3, res)
    spiral(x, y+1, matrix, 0, res)
    spiral(x+1, y, matrix, 1, res)
    spiral(x, y-1, matrix, 2, res)
  end

end 


matrix = [  [ 1, 2, 3 ],  [ 4, 5, 6 ],  [ 7, 8, 9 ] ]
for i in matrix do p i end
p spiral_order(matrix)
p ' '
matrix = [  [1, 2, 3, 4],  [5, 6, 7, 8],  [9,10,11,12]]
for i in matrix do p i end
p spiral_order(matrix)
p ' '

matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
for i in matrix do p i end
p spiral_order(matrix)
p ' '