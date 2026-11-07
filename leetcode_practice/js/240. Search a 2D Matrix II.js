/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    for (let row of matrix){
        let l = 0, r = row.length - 1;

        while(l <= r){
            let mid = Math.floor((l+r) / 2);

            if (row[mid] < target){
                l = mid + 1;
            } else if (row[mid] > target){
                r = mid - 1;
            } else {
                return true;
            }
        }
    }

    return false;
};

console.log(searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5));