function solution(n) {
    var answer = '';
    var tempList = [];
    var tempNum = n;
    while(tempNum > 0) {
        let tempD = parseInt(tempNum / 3);
        let tempM = tempNum % 3;
        
        if(tempM === 0) {
            tempD -= 1;
            tempList.unshift(4);
        } else {
            tempList.unshift(tempM);
        }
        tempNum = tempD;
    }
    answer = tempList.join('');
    return answer;
}