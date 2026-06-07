/**
 * @param {number[]} landStartTime
 * @param {number[]} landDuration
 * @param {number[]} waterStartTime
 * @param {number[]} waterDuration
 * @return {number}
 */
var earliestFinishTime = function(ls, ld, ws, wd) {
    const l = Math.min(...ls.map((s,i) => s + ld[i]));
    const w = Math.min(...ws.map((s,i) => s + wd[i]));
    return Math.min(
        ...ws.map((s,i) => Math.max(l, s) + wd[i]),
        ...ls.map((s,i) => Math.max(w, s) + ld[i])
    );
};