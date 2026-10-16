/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    let list = String(n).split('').map((elem)=>Number(elem));

    // sanity check
    if (list.length === 1){
        return -1;
    }

    let i = list.length - 2;

    while (i >= 0 && list[i] >= list[i+1]){
        i--;
    }

    if (i === -1){
        return -1;
    }

    // pivot lesser than pivot + 1 element. This means from pivot + 1 to right extreme it is non-increasing. 
    let pivot = i;

    i = list.length - 1;

    let minInd = pivot + 1;

    while (i >= pivot + 1){
        if (list[i] < list[minInd] && list[i] > list[pivot]){
            minInd = i;
        }
        i--;
    }

    // Switch pivot with minInd
    let temp = list[pivot];
    list[pivot] = list[minInd];
    list[minInd] = temp ;

    let tail = list.slice(pivot + 1);
    tail.sort((a, b) => a - b);
    list.splice(pivot + 1, tail.length, ...tail);

    if (Number(list.join('')) > (2**31 - 1)){
        return -1; 
    } else {
        return Number(list.join(''));
    }


};

console.log(nextGreaterElement(12));