function solution(participant, completion) {
    var answer = '';
    var len = completion.length;
    
    participant.sort();
    completion.sort();
    
    for(let i=0; i<len; ++i) {
        if(participant[i] !== completion[i]) {
            answer = participant[i];
            return answer;
        }
    }
    return participant[participant.length - 1];
    
}