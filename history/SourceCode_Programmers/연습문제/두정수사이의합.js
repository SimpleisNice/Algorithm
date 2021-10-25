function solution(a, b) {
  // set value
  let bigValue = Math.max(a, b);
  let smallValue = Math.min(a, b);
  
  // get totalValue small, big
  const aTotalSum = Math.floor((smallValue * (smallValue + 1)) / 2);
  const bTotalSum = Math.floor((bigValue * (bigValue + 1)) / 2);
  
  // get value
  return  bTotalSum - aTotalSum + smallValue;
}