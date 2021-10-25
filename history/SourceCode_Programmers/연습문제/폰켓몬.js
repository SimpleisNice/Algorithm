function solution(nums) {
  // get num type size
  const numType = (new Set([...nums])).size;
  // get max select
  const maxSelect = Math.floor(nums.length / 2);
  
  const answer = maxSelect > numType ? numType : maxSelect;
  return answer;
}