function solution(skill, skill_trees) {
    var answer = 0;
    var skill_len = skill.length;
        
    skill_trees.forEach((skill_set) => {
        let pos = skill_set.indexOf(skill[0]);
        if(pos === -1) pos = 27;
        ++answer;
        for(let i=1; i<skill_len; ++i) {
            let temp_pos = skill_set.indexOf(skill[i]);
            
            if(temp_pos === -1) temp_pos = 27;
            if((pos > temp_pos)) {
                answer--;
                break;
            }
            pos = temp_pos;
        }
    });
    return answer;
}