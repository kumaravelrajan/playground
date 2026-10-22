/**
 * @param {string} s
 * @return {string}
 */
var lexSmallest = function(s) {
    let l = 0, r = s.length - 1;
    let k = 2;
    let lexSmallest = s;
    let minChar = s[0];

    for (let char of s){
        if (char < minChar) minChar = char;
    }

    while(k <= s.length){

        if (s[k-1] === minChar){
            let lSubStr = s.slice(l, k).split('').reverse().join('');

            lSubStr += s.slice(k);

            if (lSubStr < lexSmallest) lexSmallest = lSubStr;
        }
    
        if (s[0] === minChar){
            let rSubStr = s.slice(0, r - k + 1);

            rSubStr += s.slice(r - k + 1).split('').reverse().join('');

            if (rSubStr < lexSmallest) lexSmallest = rSubStr;
        }
        

        k++;
    }

    return lexSmallest;
};

console.log(lexSmallest("dcab"));