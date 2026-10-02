/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    let l = 0, r = tokens.length - 1;
    let score = 0, maxScore = 0; 

    tokens.sort((a, b) => a - b);

    if (power < tokens[0]) return 0;

    while (l <= r){
        if (tokens[l] <= power){
            power -= tokens[l];
            score++;

            if (score > maxScore) maxScore = score; 
            l++;
        } else {
            score--;
            power += tokens[r];
            r--;
        }
    }

    return maxScore;
};

console.log(bagOfTokensScore([100,200,300,400], 200));