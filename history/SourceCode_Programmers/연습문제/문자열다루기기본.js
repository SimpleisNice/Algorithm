function solution(s) {
  const strLen = s.length;
  let num = 0;
  let str = 0;
  
  if (strLen !== 4 && strLen !== 6) {
      return false
  }
  
  for (let i = 0; i < strLen; i += 1) {
      const tempChar = s[i];
      
      if (tempChar >= '0' && tempChar <= '9') {
          num += 1;
      } else {
          str += 1;
      }
  }
  
  if (num && str) {
      return false;
  }
  return true;
}