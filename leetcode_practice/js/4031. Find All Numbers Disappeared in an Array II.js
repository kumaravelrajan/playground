/**
 * @param {number[]} nums
 * @param {number} lower
 * @param {number} upper
 * @return {number[][]}
 */
var findDisappearedNumbers = function(nums, lower, upper) {

    if (lower === upper) {
        if (nums.find((el) => el === lower) !== undefined){
            return [];
        } else {
            return [[lower, upper]];
        }
    }

    nums.sort((a, b) => a - b);
    let ans = [];
    
    for (let i = 0; i < nums.length && lower <= upper; i ++){
        if (lower < nums[i] && nums[i] <= upper){
            ans.push([lower, nums[i] - 1]);
            lower = nums[i] + 1;
        } else if (lower === nums[i]){
            lower = nums[i] + 1;
        } else if (lower > nums[i]){
            continue;
        } else if (nums[i] > upper){
            ans.push([lower, upper]);
            lower = upper + 1;
            break;
        }
    }

    if (lower <= upper){
        ans.push([lower, upper]);
    }

    return ans;
    
};

console.log(findDisappearedNumbers([101,884,611,10,910,396,900,835,662,29,727,118,609,513,492,484,595,750,549,382], 531, 531));