/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number[][]}
 */
var findDisappearedNumbers = function(nums, lower, upper) {
    nums.sort((a, b) => a - b);
    let ans = [];
    let cLower = lower, cUpper = 0;
    let i = 0;
    while(cLower <= upper && i < nums.length){
        if (cLower < nums[i]){
            // gap exists between cLower and val.
            ans.push([cLower, nums[i] - 1]);
            cLower = nums[i] + 1;
        } else if (cLower === nums[i]){
            cLower++;
        }
        i++;
    }

    if (i === nums.length){
        ans.push([cLower, upper]);
    }

    return ans;
    
};

console.log(findDisappearedNumbers([3,9,7], 1, 12));