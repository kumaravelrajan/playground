/**
 * @param {number[]} ages
 * @return {number}
 */
var numFriendRequests = function(ages) {
    const MAX = 120;
    const freq = new Array(MAX + 1).fill(0);
    for (const age of ages) freq[age]++;

    let ans = 0;
    for (let a = 1; a <= MAX; a++) {
        if (freq[a] === 0) continue;

        // Need b > 0.5 * a + 7  =>  b >= floor(0.5 * a + 7) + 1
        const minB = Math.floor(0.5 * a + 7) + 1;

        for (let b = minB; b <= a; b++) {
            if (freq[b] === 0) continue;

            ans += freq[a] * freq[b];

            // If same age, exclude sending to self
            if (a === b) {
                ans -= freq[a];
            }
        }
    }

    return ans;
};

console.log(numFriendRequests([8,85,24,85,69]));