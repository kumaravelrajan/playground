/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function(nums) {
    let set = new Set(nums);
    let arr = Array.from(set).sort((a, b) => a - b);
    let ans = -1;

    for (let num of arr){
        let curr = num;
        let count = 0;

        while(set.has(curr)){
            count++;
            set.delete(curr);
            curr = curr ** 2;
        }

        if (count > 1 && count > ans){
            ans = count;
        }
    }

    return ans;
};

console.log(longestSquareStreak([4,3,6,16,8,2]));