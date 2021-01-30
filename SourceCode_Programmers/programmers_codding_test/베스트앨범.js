function solution(genres, plays) {
  var answer = [];    
  const playList = {};
  
  // 데이터 셋팅
  genres.forEach((value, index) => {
      if (!playList[value]) {
          playList[value] = { count: 0, data: [] };
      }
      
      playList[value].count += plays[index];
      playList[value].data.push({
          index,
          count: plays[index],
      });
  });
  
  // 장르 내 data 정렬 및 데이터 변경
  const mergePlayList = Object.keys(playList).map(key => {
      playList[key].data.sort(function (itemA, itemB) {
          if (itemA.count < itemB.count) {
              return 1;
          } else if (itemA.count > itemB.count) {
              return -1;
          }
          return itemA.index - itemB.index;
      })
      
      
      const merge = {
          key,
          count: playList[key].count,
          list: playList[key].data.map(value => value.index),
      };
      return merge;
  });
  
  // 장르 정렬
  mergePlayList.sort(function (itemA, itemB) {
      return itemB.count - itemA.count;
  })
  
  // 결과값 추출
  mergePlayList.forEach((item) => {
      answer = answer.concat(item.list.slice(0, 2));
  })
  
  return answer;
}