/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    let targetPos = s.length - 1;

    while (targetPos >= 0 && s[targetPos] === "1"){
        targetPos--;
    }

    let track1 = targetPos; 
    let swaps = 0; 

    while(track1 >= 0){
        if (s[track1] === "1"){
            swaps += targetPos - track1; 
            targetPos--;
        }
        track1--;
    }

    return swaps;
};

console.log(minimumSteps("0100101"));