function solution(progresses, speeds) {
    var answer = [];
    var totalDay = 0;
    while(true) {
        if(!progresses.length)
            break;
        
        let day = 100 - progresses[0] - speeds[0] * totalDay;
        let count = 0;
 
        day = parseInt(day / speeds[0]);

        if(progresses[0] + speeds[0] * day < 100)
            day++;
        
		totalDay += day;
        for(let i=0; i<progresses.length;) {
            if(progresses[i] + speeds[i] * totalDay >= 100) {
                progresses.shift();
                speeds.shift();
                count++;
            } else {
                break;
            }
        }
        if(count) 
			answer.push(count);		
    }
    return answer;
}