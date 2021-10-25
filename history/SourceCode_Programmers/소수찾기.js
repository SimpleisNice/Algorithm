function solution(n) {
  const primeList = new Array(n + 1);
  const primeListLen = n + 1;
  let primeCount = 0;
  
  for (let i = 2; i < primeListLen; i += 1) {
      if (!primeList[i]) {
          primeList[i] = false;
          primeCount += 1;
          
          for (let j = i * i; j < primeListLen; j += i) {
              primeList[j] = true;
          }
      }
  }
  return primeCount;
}