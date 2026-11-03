var maxProfitAssignment = function(difficulty, profit, worker) {
    // Pair difficulty with profit and sort jobs by difficulty
    const jobs = difficulty.map((d, i) => [d, profit[i]]);
    jobs.sort((a, b) => a[0] - b[0]);

    // Sort workers by ability so we only ever move forward through jobs
    worker.sort((a, b) => a - b);

    let res = 0;
    let best = 0; // best profit among all jobs seen so far
    let j = 0;    // pointer into jobs

    for (const ability of worker) {
        // Absorb every job this worker can do into the running best
        while (j < jobs.length && jobs[j][0] <= ability) {
            best = Math.max(best, jobs[j][1]);
            j++;
        }
        // best is now the max profit across all jobs up to this ability
        res += best;
    }

    return res;
};

console.log(maxProfitAssignment([2,4,6,6,6,6,8,10], [10,20,5,10,20,30,40,50], [4,5,6,1,1,1,7]));
