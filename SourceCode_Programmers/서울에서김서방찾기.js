function solution(seoul) {
  const arrayLen = seoul.length;
  
  for (let i = 0; i < arrayLen; i += 1) {
      const isKim = seoul[i].includes('Kim');
      
      if (isKim) {
          return `김서방은 ${i}에 있다`;
      }
  }
}