function solution(s){
    let strLen = s.length;
    let pCount = 0;
    let yCount = 0;
    
    while(strLen--) {
        const tempChar = s[strLen];
        
        if (tempChar === 'p' || tempChar === 'P') {
            pCount += 1;
        } else if (tempChar === 'y' || tempChar === 'Y') {
            yCount += 1;
        }
    }
    
    if (pCount || yCount) {
        return pCount === yCount;
    }
    
    return true;
}