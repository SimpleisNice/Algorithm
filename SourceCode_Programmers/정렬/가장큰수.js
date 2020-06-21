function solution(numbers) {
    var answer = '';
    numbers.sort((numA, numB) => {
        let tempA = numA.toString();
        let tempB = numB.toString();
        
        if(tempA[0] < tempB[0])
            return 1;
        else if(tempA[0] > tempB[0])
            return -1;
        else {
            let tempALen = tempA.length;
            let tempBLen = tempB.length;
            
            if(tempALen === tempBLen) {
                if(numA < numB) 
                    return 1;
                else if(numA > numB)
                    return -1;
                return 0;
            }
            else {
                let bigLen = tempALen > tempBLen ? tempALen : tempBLen;
                for(let i=0; i<bigLen; ++i) {
                    if(tempA[i % tempALen] < tempB[i % tempBLen])
                        return 1;
                    else if(tempA[i % tempALen] > tempB[i % tempBLen])
                        return -1;
                }
            }
        }
    })
    numbers.forEach((value) => {
        answer += value;
    })
    return answer;
}