/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */
var findRadius = function(houses, heaters) {

    let heatl = -1, heatr = -1;
    let maxDist = -1;
    // distance = Array(houses.length).fill(-1);
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);

    if (heaters.length === 1){
        heatr = 0;
    } else {
        heatl = 0;
        heatr = 1;
    }

    if (heaters.length === 1){
        // Only a single heater present. 
        for (let i = 0; i < houses.length; i++){
            let curDist = Math.abs(houses[i] - heaters[heatr]);
            
            if (curDist > maxDist){
                maxDist = curDist;
            }
        }

        return maxDist;
    }

    // There are multiple heaters present.
    for (let i = 0; i < houses.length; i++){
        let curDist = -1; 
        if (houses[i] < heaters[heatl]){
            curDist = Math.abs(heaters[heatl] - houses[i]);
            maxDist = Math.max(curDist, maxDist);
        } else if (heaters[heatl] <= houses[i] && houses[i] <= heaters[heatr]){
            curDist = Math.min(Math.abs(heaters[heatl] - houses[i]), Math.abs(heaters[heatr] - houses[i]));
            maxDist = Math.max(curDist, maxDist);
        } else if (houses[i] > heaters[heatr]){
            // Time to shift heaters window forward.
            while(heatr < heaters.length - 1 && houses[i] > heaters[heatr]){
                heatl = heatr;
                heatr++;
            }
            curDist = Math.min(Math.abs(heaters[heatl] - houses[i]), Math.abs(heaters[heatr] - houses[i]));
            maxDist = Math.max(curDist, maxDist);
        }
    }    

    return maxDist;
};

console.log(findRadius([1,2,3,5,15], [2, 30]));