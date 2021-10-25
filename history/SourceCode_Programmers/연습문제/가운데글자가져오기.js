function solution(s) {
    let answer = '';
    // 문자열 길이
    const strLen = s.length;
    // 문자열의 중심 위치
    const strMidPos = parseInt(strLen / 2);
    
    answer = strLen % 2 === 0 
        ? s.slice(strMidPos - 1, strMidPos + 1) 
        : s.slice(strMidPos, strMidPos + 1);
    return answer;
}