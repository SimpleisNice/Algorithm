# 알고리즘 공부

## 백준 문제
### 알고리즘 A

https://code.plus/course/4

- A + B(1000)

- 에디터(1406)

- 풍선 터트리기(2346)

- Hello World(2557)

- A + B -2(2558)

- 괄호(9012)

  - `string`으로 입력 받은 값을 `stack`에 넣으면서 비교를 진행한다. 이때 `checkNum`이라는 int형 변수를 두어 음수 또는 양수인 경우 "NO"를 출력하고, 0인경우 "YES"를 출력한다.

- 스택(10828)

  - `string`에서 비교시, `==`또는 `compare()`를 사용할 수 있으며, 디버그 빌드시 `==`이 `compare()`에 비해 과정이 길지만. 릴리즈 빌드시 거의 차이가 없이 비슷함([참고자료](https://choryeonworkshop.tistory.com/119)

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

### 알고리즘 B
https://code.plus/course/32

- 수학

  - 나머지(10430)
    - `mod`가 특정 조건을 성립함을 확인하고, 출력하는 문제이다. 
      `*`의 경우 `(A * B) mod C`  == `((A mod C) * (B mod C)) mod C`조건을 만족한다.
      `+`의 경우`(A + B) mod C` == `((A mod C) + (B mod C)) mod C`조건을 만족한다.
  - 최대공약수와 최소 공배수(2609)
    - `gcd`와 `lcm`을 구하는 문제이며, 이때 `gcd`는 유클리드 호제법을 활용해서 구할 수 있다. 
      또한 `lcm`은 `a * b / gcd(a, b)`를 활용해서 구할 수 있다. 
  - 최소공배수(1934)
    - 2609문제와 동일하게 `gcd`를 구한 뒤 `lcm`을 구하면된다. 추가적으로 `T`번 횟수 만큼 입력 받은 값의 `lcm`을 구해야 한다.
  - GCD 합(9613)
  - 소수 찾기
  - 골드바흐의 추측


https://code.plus/course/33

https://code.plus/course/34

https://code.plus/course/35

#### 참고자료

- [eof에 관하여](https://funylife.tistory.com/entry/%EB%AC%B8%EC%9E%90%EC%99%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-3-EOF%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4)
- [c scanf](http://www.cplusplus.com/reference/cstdio/scanf/)

