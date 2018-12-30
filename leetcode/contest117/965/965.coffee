###
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 * @param {TreeNode} root
 * @return {boolean}
###

flg = false
num = -1;

isUnivalTree = (root) ->
  flg = true
  num = root.val
  dfs(root)
  return flg

dfs = (node) ->
  return if node is null
  console.log node
  if node.val != num 
    flg = false
    return
  dfs(node.right)
  dfs(node.left)
  return 
  

