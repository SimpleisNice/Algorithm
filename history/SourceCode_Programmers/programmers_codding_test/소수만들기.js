function getPrime(primeArray) {
  const arrayLen = primeArray.length;
  
  primeArray[1] = false;
  
  for (let i = 2; i < arrayLen; i += 1) {
      if (primeArray[i] === undefined) {
          primeArray[i] = true;
      }
      
      for (let j = i * i; j < arrayLen; j += i) {
          primeArray[j] = false;
      }
  }
}
function solution(nums) {
  var answer = 0;
  const primeArray = new Array(50000);
  const numLen = nums.length;
  
  getPrime(primeArray);
  
  
  for (let i = 0; i < numLen - 2; i += 1) {
      for (let j = i + 1; j < numLen - 1; j += 1) {   
          for (let k = j + 1; k < numLen; k += 1) {
              let sum = nums[i] + nums[j] + nums[k];
              
              if (primeArray[sum]) {
                  answer += 1;
              }
          }
      }
  }
  
  return answer;
}