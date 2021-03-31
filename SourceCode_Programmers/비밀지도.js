function solution(n, arr1, arr2) {
  var answer = [];
  
  for (let i = 0; i < n; i += 1) {
      const firstArr = arr1[i].toString(2).padStart(n, 0);
      const secondArr = arr2[i].toString(2).padStart(n, 0);
      const tempArr = [];
      
      for (let j = 0; j < n; j += 1) {
          if (firstArr[j] === '1' || secondArr[j] === '1') {
              tempArr[j] = '#';
          } else {
              tempArr[j] = ' ';
          }
      }
      answer[i] = tempArr.join('');
  }
  
  
  return answer;
}