// 2019 카카오 개발자 겨울 인터쉽
function solution(s) {
    var answer = [];
    let tempStr = s.slice(2, s.length - 2);
    const temp_list = tempStr.split("},{");
    const list = Array(temp_list.length + 1).fill(null).map(()=>Array());
    
    temp_list.forEach((value)=> {
        const num_list = value.split(",");
        const pos = num_list.length;
        num_list.forEach((temp_value)=>{
            list[pos].push(Number(temp_value));
        });
    });
    
    for(let i=1, len = list.length; i<len; ++i) {
        list[i].forEach((value)=>{
            if(answer.indexOf(value) === -1) {
                answer.push(value);
            }
        })
    }
    return answer;
}