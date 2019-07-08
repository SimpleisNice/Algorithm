# 알고리즘 공부

## 백준 문제
### 알고리즘 A

https://code.plus/course/4

- A + B(1000)

- 에디터(1406)

- 풍선 터트리기(2346)

- Hello World(2557)

- A + B -2(2558)

- A + B -3(10950)

- A + B -4(10951)

  - eof까지 받아야함

- A + B -5(10952)

- A + B -6(10953)

  - `%*c`는 `*`이 위치에 있는 문자는 무시하라는 것을 의미

- A + B -7(11021)

- A + B -8(11022)

- 그대로 출력하기(11718)

  - string getline을 활용하여 입력을 받고, 길이를 확인해 결과값을 변경하여 출력함

- 그대로 출력하기2(11719)

  - ​    11718과 동일해도 문제가 없는 이유는, string getline으로 처리하기 때문에

    ​    입력에 문제가 없으며, 길이상 문제는 length()를 통해 확인 및 길이를 넘는 경우

    ​    substr()을 통해 길이를 줄여서 temp를 변경해줌

- 숫자의 합(11720)

  - ​    tempStr[i]의 경우 const char이기 때문에 변환이 필요하다.

    ​    이 경우 간단하게 '0' 또느 48을 빼주면 된다.

- 열 개씩 끊어 출력하기(11721)

  - ​    string substr를 활용하여 문자를 10개씩 짤라서 받아올 수 있다.

    ​    추가적으로 substr 2개의 값을 받을 수 있으며, 1번째는 위치, 2번쨰는 개수 이다.

    ​    개수란, 해당 위치부터 몇개를 받아올건지를 의미하며, 많이 개수가 문자열의 개수보다 많은경우

    ​    문자열 길이 이상을 반환하지 않고 문자열의 끝 까지만 리턴함

    ​    -> 참고 링크(https://modoocode.com/235)

https://code.plus/course/5

https://code.plus/course/6



#### 참고자료

- [eof에 관하여](https://funylife.tistory.com/entry/%EB%AC%B8%EC%9E%90%EC%99%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-3-EOF%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4)
- [c scanf](http://www.cplusplus.com/reference/cstdio/scanf/)

### 알고리즘 B
https://code.plus/course/32

https://code.plus/course/33

https://code.plus/course/34

https://code.plus/course/35