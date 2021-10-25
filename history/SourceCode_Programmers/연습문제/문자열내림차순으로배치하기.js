function solution(s) {
  return  s.split('').sort((targetA, targetB) => {
      if (targetA < targetB) {
          return 1;
      }
      
      if (targetA > targetB) {
          return -1;
      }
      
      return 0;
  }).join('');
}