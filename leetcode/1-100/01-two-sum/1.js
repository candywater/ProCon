var twoSum = function(nums, target) {
    var table = {};
    for( i in nums ){
      var tmp = table[ target - nums[i] ]
      if( tmp < nums.length && tmp >= 0)
        return [parseInt(tmp), parseInt(i)]           
      else
        table[nums[i]] = i
      //console.log(i)
      //console.log(target-nums[i])
      //console.log(tmp)
    }
    return "no answer";
};
