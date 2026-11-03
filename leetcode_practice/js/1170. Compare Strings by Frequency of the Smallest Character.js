/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let wordLens = words.map((elem) => [getLexSmallestFreq(elem)]);
    wordLens.sort((a, b)=>{
        return a - b;
    });

    let answers = [];

    for (let q of queries){
        let querySmallestFreq = getLexSmallestFreq(q);

        let l = 0, r = wordLens.length - 1;
        let start = null;

        while(l <= r){
            let mid = Math.floor((l + r) / 2);

            if (wordLens[mid] <= querySmallestFreq){
                // Unsuitable. Simply move on. 
                l = mid + 1;
            } else if (wordLens[mid] > querySmallestFreq){
                start = mid;
                r = mid - 1;
            }
        }
        if (start !== null) answers.push(wordLens.length - start);
        else answers.push(0);
    }
    return answers;
};

var getLexSmallestFreq = function(s){
    let lexSmallest = 'z';
    let freq = 0;

    for (let c of s){
        if (c < lexSmallest){
            lexSmallest = c;
            freq = 1;
        } else if (c === lexSmallest){
            freq++;
        }
    }

    return freq;
}

console.log(numSmallerByFrequency(["aabbabbb","abbbabaa","aabbbabaa","aabba","abb","a","ba","aa","ba","baabbbaaaa","babaa","bbbbabaa"], 
    ["b","aaaba","aaaabba","aa","aabaabab","aabbaaabbb","ababb","bbb","aabbbabb","aab","bbaaababba","baaaaa"]));