/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let n1 = version1.length;
    let n2 = version2.length;

    let i1 = 0, i2 = 0;

    while (i1 < n1 || i2 < n2){
        let curV1 = '', curV2 = '';
        while(i1 < n1 && version1[i1] !== '.'){
            curV1 = curV1.concat(version1[i1]);
            i1++;
        }
        i1++;

        while(i2 < n2 && version2[i2] !== '.'){
            curV2 = curV2.concat(version2[i2]);
            i2++;
        }
        i2++;

        curV1 = Number(curV1);
        curV2 = Number(curV2);

        if (i1 === n1 && i2 === n2){
            return cmp(curV1, curV2);
        } else {
            let ret = cmp(curV1, curV2);
            if (ret !== 0){
                return ret;
            }
        }
    }

    return 0;
};

let cmp = (a, b) =>{
    if (a > b){
        return 1;
    } else if (a < b){
        return -1;
    } else {
        return 0;
    }
}

console.log(compareVersion("1.0", "1.0.0.0"));