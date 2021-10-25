function solution(n) {
    var answer;
    var tempList = new Array(n +1);
    tempList[0] = 1;
    tempList[2] = 3;

    const modNum = 1000000007;
    
    for(let i=4; i<=n; i+=2) {
        tempList[i] = tempList[i - 2] * 3;
        for(let j=i - 4; j>=0; j-= 2) {
            tempList[i] += tempList[j] * 2;
        }
        tempList[i] %= modNum;
    }
    answer = tempList[n];
    return answer;
}