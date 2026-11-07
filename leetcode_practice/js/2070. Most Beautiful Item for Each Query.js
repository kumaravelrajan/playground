/**
 * @param {number[][]} items
 * @param {number[]} queries
 * @return {number[]}
 */
var maximumBeauty = function(items, queries) {
    items.sort((a, b) => a[0] - b[0]);

    // Array to hold max beauty until a certain index in items
    let maxBeautyArr = Array(items.length + 1).fill(0);

    maxBeautyArr[0] = items[0][1];

    for (let i = 1; i < items. length; i++){
        maxBeautyArr[i] = Math.max(items[i][1], maxBeautyArr[i-1]);
    }

    let ans = [];

    for (let q of queries){
        let l = 0, r = items.length - 1;
        let ctAns = 0;
        while(l <= r){
            let mid = Math.floor((l + r) / 2);

            if (items[mid][0] > q){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (r >= 0)
            ans.push(maxBeautyArr[r]);
        else 
            ans.push(0);
    }

    return ans.length > 0 ? ans : 0;

};

console.log(maximumBeauty([[193,732],[781,962],[864,954],[749,627],[136,746],[478,548],[640,908],[210,799],[567,715],[914,388],[487,853],[533,554],[247,919],[958,150],[193,523],[176,656],[395,469],[763,821],[542,946],[701,676]], 
    [885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584]));