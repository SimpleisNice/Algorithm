function solution(n) {
  // n 의 값을 3진법 및 리버스
  let reverseNum = n.toString(3).split('').reverse().join('');
  return parseInt(reverseNum, 3);
}