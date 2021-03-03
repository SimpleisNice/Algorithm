function solution(array, commands) {
    const answer = [];
    // commands 배열을 기준으로 순회
    commands.forEach((value) => {
        const [i, j, k] = value;
        // 조건에 맞는 배열을 복사한 뒤, 오름차순으로 정렬
        const selectList = array.slice(i - 1, j).sort((firstTarget, secondTarget) => firstTarget - secondTarget);

        answer.push(selectList[k - 1]);
    })
    return answer;
}