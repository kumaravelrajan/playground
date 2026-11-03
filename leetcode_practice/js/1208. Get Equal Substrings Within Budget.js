/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function(s, t, maxCost) {

    // if (maxCost === 0){
    //     return 1;
    // }

    let left = 0, right = 0;
    let copyMaxCost = maxCost;
    let res = 0;

    for(; right < s.length; right++){
        if(copyMaxCost >= Math.abs(s.charCodeAt(right) - t.charCodeAt(right))){
            copyMaxCost -= Math.abs(s.charCodeAt(right) - t.charCodeAt(right));
            if (right - left + 1 > res){
                res = right - left + 1;
            }
        } else {
            while(left <= right && copyMaxCost < Math.abs(s.charCodeAt(right) - t.charCodeAt(right))){
                let add = Math.abs(s.charCodeAt(left) - t.charCodeAt(left));

                if (copyMaxCost + add <= maxCost){
                    copyMaxCost += add;
                } else {
                    // copyMaxCost is not large enough to accommodate expanding window to the right. Hence, we want to shrink and add to copyMaxCost. 
                    // But here, if we add the s[left] - t[left] to copyMaxCost then it will exceed maxCost. We obviously do not want this.
                    // Summary - shrinking from left will mean copyMaxCost > maxCost. expanding to right not possible because copyMaxCost < s[right] - t[right]. Hence, abandon this stretch of s and t altogther and set left = right + 1;

                    left = right + 1;
                    continue;
                }
                left++;
            }

            if (left > right){
                continue;
            } else {
                copyMaxCost -= Math.abs(s.charCodeAt(right) - t.charCodeAt(right));

                if (right - left + 1 > res){
                    res = right - left + 1;
                }
            }
        }

    }

    return res;    
};

console.log(equalSubstring("abcd", "acde", 0));