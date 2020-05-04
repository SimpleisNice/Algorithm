function solution(s) {
    var answer = '';
    let str_len = s.length;
    let mid_pos = parseInt(str_len/2);
    
    if(str_len % 2 === 0) {
        answer = s.slice(mid_pos -1, mid_pos + 1);
    }else {
        answer = s[mid_pos]; 
    }
    return answer;
}