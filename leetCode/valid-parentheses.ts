/**
 * https://leetcode.com/problems/valid-parentheses/
 */
function isValid(s: string): boolean {
  const openList: Array<string> = [];
  const bracketsObj: {[key: string]: string} = {
      '{': '}',
      '[': ']',
      '(': ')'
  }
  const sLen: number = s.length;

  // is odd length
  if (sLen % 2 !== 0) {
      return false;
  }
  
  // is first char close bracket
  if (!bracketsObj[s[0]]) {
      return false;
  }
  
  for (let index: number = 0; index < sLen; index += 1) {
      const sChar: string = s[index];
      
      if (sChar === '[' || sChar === '{' || sChar === '(') {
          openList.push(sChar);
      } else {
          const lastChar: string = openList.pop();
          
          if (bracketsObj[lastChar] !== sChar) {
              return false;
          }
      }
  }

  if (openList.length) {
      return false;
  }
  return true;
};