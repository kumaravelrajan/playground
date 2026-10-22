/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    if (k === 0) return;

    let numsDup = [...nums];

    let i = nums.length - k, j = 0;
    let start = i;

    for (; j < nums.length; j++){
        nums[j] = numsDup[i];

        i = (i + 1) % nums.length;
    }
    return nums;
};

console.log(rotate([1,2,3,4,5,6,7], 3));