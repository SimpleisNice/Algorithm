function solution(d, budget) {
  let answer = 0;
  // 각 부서에 필요한 물품을 지원해 주기 위해 부서별로 물품을 구매하는데 필요한 금액 조사
  // 전체 예산이 정해져 있음
  // 최대한 많은 부서의 물품을 구매해 줄 수 있도록 하려고 함
  // 딱 맞게 금액을 지원함
  // d, budget
  
  const sortDList = d.sort((itemA, itemB) => itemA - itemB);
  const dLen = d.length;
  let totalSum = 0;
  for (; answer < dLen; answer += 1) {
      totalSum += sortDList[answer];
      
      if (totalSum > budget) {
          break;
      }
  }
  return answer;
}