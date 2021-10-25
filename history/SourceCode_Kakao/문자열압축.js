function solution(s) {
    var s_len = s.length - 1;
    var answer = s_len + 1;
    
    var stop_point = parseInt((s_len + 1)/2);
    var token_len = 1;

    while(token_len <= stop_point) {
        let count = 1;
        let re_str = "";
        let num = s.slice(0, token_len);
        let i=token_len;
        
        for(;i<=s_len; i+= token_len) {
            let temp_num = s.slice(i, i + token_len);
            if(temp_num === num) {
                count++;
            }
            else {
                if(count !== 1) {
                    re_str += count;
                }
                re_str += num;
                num = temp_num;
                count = 1;
            }
        }
        if(count !== 1) {
            re_str += count;
        }
        re_str += num;
        if(answer > re_str.length) {
            answer = re_str.length;
        }
        token_len++;
    } 
    return answer;
}