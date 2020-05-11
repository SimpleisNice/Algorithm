function solution(heights) {
    var answer = [];
    const top_cnt = heights.length;
    
    for(let i=0; i<top_cnt; ++i) {
        answer[i] = 0;
        for(let j=i-1; j>=0; --j) {
            if(heights[i] < heights[j]) {
                answer[i] = j + 1;
                break;
            }
        }
    }
    return answer;
}