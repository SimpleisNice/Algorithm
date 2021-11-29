/**
 * https://leetcode.com/problems/roman-to-integer/
 */
/**
 * @param {string} s
 * @return {number}
 */
 var romanToInt = function(s) {  
  const SPECIAL_TYPE = {
      IV: 4,
      IX: 9,
      XL: 40,
      XC: 90,
      CD: 400,
      CM: 900,
  }
  const NORMAL_TYEP = {
      I: 1,
      V: 5,
      X: 10,
      L: 50,
      C: 100,
      D: 500,
      M: 1000,
  };
  
  let totalCount = 0;
  let tempString = s;
  
  Object.keys(SPECIAL_TYPE).forEach(value => {
      let count = 0;
      let index = tempString.indexOf(value);
      
      while(index !== -1) {
          count += 1;
          tempString = tempString.replace(value, ' ');
          index = tempString.indexOf(value);
      }
      
      totalCount += count * SPECIAL_TYPE[value];
  });
  
  Object.keys(NORMAL_TYEP).forEach(value => {
      let count = 0;
      let index = tempString.indexOf(value);
      
      while(index !== -1) {
          count += 1;
          tempString = tempString.replace(value, ' ');
          index = tempString.indexOf(value);
      }
      
      totalCount += count * NORMAL_TYEP[value];
  });
  
  return totalCount;
};