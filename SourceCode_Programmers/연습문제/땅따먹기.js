function solution(land) {
    var answer = 0;
    let landLen = land.length;
    let tempArray = Array.from(Array(landLen + 1), () => Array(0,0,0,0));
    
    for(let i=1; i<= landLen; ++i) {
        for(let j=0; j<4; ++j) {
            for(let k=0; k<4; ++k) {
                if(j === k) 
                    continue;
                if(tempArray[i][j] < tempArray[i - 1][k] + land[i-1][j])
                    tempArray[i][j] = tempArray[i -1][k] + land[i-1][j];
            }
        }
    }
    for(let i=0; i<4; ++i) {
        if(answer < tempArray[landLen][i]) {
            answer = tempArray[landLen][i];
        }
    }
    return answer;
}