/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */

// Todo: what if binary search does not return earliest occurence.

var successfulPairs = function(spells, potions, success) {
    potions.sort((a, b) => a - b);
    let result = Array(spells.length).fill(0);

    function binarySearch(minPotionVal){
        let l = 0, r = potions.length - 1;
        let mid = (l + r) / 2;
        let earliestIndex = -1;

        while (l <= r){
            mid = Math.ceil((l + r) / 2);
            if (potions[mid] === minPotionVal){
                earliestIndex = mid;
                r = mid - 1;
            } else if (potions[mid] < minPotionVal){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (earliestIndex === -1){
            // Exact minPotionVal not found. 
            if (potions[mid] < minPotionVal){
                return mid + 1;
            } else {
                return mid;
            }
        } else {
            return earliestIndex;
        }
    }

    for (let i = 0; i < spells.length; i++){
        if (spells[i] >= success){
            result[i] = potions.length;
            continue;
        } else {
            // spells[i] lesser than success.
            let minPotionVal = Math.ceil(success / spells[i]);

            let minPotionIndex = binarySearch(minPotionVal);

            let compatiblePotionIndices = potions.length - minPotionIndex;

            if (compatiblePotionIndices >= 1){
                result[i] = compatiblePotionIndices;
            } else {
                result[i] = 0;
            }
        }
    }

    return result;
};

console.log(successfulPairs([5,1,3], [1,2,3,4,5], 7));
console.log(successfulPairs([3,1,2], [8,5,8], 16));
console.log(successfulPairs([15,8,19], [38,36,23], 328));