function solution(arr)
{
    const answer = [];
    let beforeValue = arr[0];
    
    // set first value
    answer.push(arr[0]);
    arr.shift();
    
    // search
    arr.forEach((value, inde) => {
        // value is same return
        if (beforeValue === value) {
            return;
        }
        // value is not same
        // set beforeValue
        beforeValue = value;
        answer.push(value);
    });
    
    return answer;
}