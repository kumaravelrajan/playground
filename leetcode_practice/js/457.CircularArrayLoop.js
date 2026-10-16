/**
 * @param {number[]} nums
 * @return {boolean}
 */
var circularArrayLoop = function(nums) {
    let targets = Array(nums.length).fill(0);

    for(let i = 0; i < nums.length; i++){
        if (nums[i] >= 0){
            targets[i] = (i + nums[i]) % nums.length;
        } else {
            // nums[i] negative. Move backward. 
            if (Math.abs(nums[i]) <= i){
                targets[i] = i + nums[i];
            } else {
                // nums[i] value large enough for us to circle around from 0 -> n.
                targets[i] = (nums.length - 1) + (nums[i] + (i + 1)) % nums.length;
            }
        }
    }
    for (let i = 0; i < targets.length; i++){
        let visitedIndices = Array(targets.length).fill(false);
        visitedIndices[i] = true;

        let next = targets[i];
        let elements = 1, posMoves = 0, negMoves = 0;

        if (nums[i] > 0){
            posMoves++;
        } else {
            negMoves++;
        }

        while(i !== next && visitedIndices[next] === false){

            if (nums[next] > 0){
                posMoves++;
            } else {
                negMoves++;
            }

            elements++;
            visitedIndices[next] = true;
            next = targets[next];
        }

        if (i === next && ((posMoves > 0 && negMoves === 0) || (negMoves > 0 && posMoves === 0)) && (elements > 1)){
            return true;
        }
    }   

    return false;
};

console.log(circularArrayLoop([1,-1,5,1,4]));