function solution(arrangement) {
    var answer = 0;
    let bar = 0;
    for(let i=0, len = arrangement.length; i < len; ++i) {
        if(arrangement[i] === '(') {
            ++bar;
        } else {
            --bar;
            if(arrangement[i - 1] === '(') {
                answer += bar;
            } else {
                answer += 1;
            }
        }
    }
    return answer;
}