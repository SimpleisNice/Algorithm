# 알고리즘 공부

## 백준 문제
### 알고리즘 A

https://code.plus/course/4

알고리즘과 입/출력

- A + B(1000)

- 에디터(1406)

- 풍선 터트리기(2346)

- Hello World(2557)

- A + B -2(2558)

- 괄호(9012)

  - `string`으로 입력 받은 값을 `stack`에 넣으면서 비교를 진행한다. 이때 `checkNum`이라는 int형 변수를 두어 음수 또는 양수인 경우 "NO"를 출력하고, 0인경우 "YES"를 출력한다.

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

자료구조

- 스택(10828)
  - `string`에서 비교시, `==`또는 `compare()`를 사용할 수 있으며, 디버그 빌드시 `==`이 `compare()`에 비해 과정이 길지만. 릴리즈 빌드시 거의 차이가 없이 비슷함([참고자료](https://choryeonworkshop.tistory.com/119))
- 괄호(9012)
  - `string`으로 입력 받은 값을 `stack`에 넣으면서 비교를 진행한다. 이때 `checkNum`이라는 int형 변수를 두어 음수 또는 양수인 경우 "NO"를 출력하고, 0인경우 "YES"를 출력한다.
- 쇠막대기(10799)

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
    - gcd의 합을 구하면된다. 틀린 이유를 모르는데 틀렸다는 이유가 발생해서 자료들을 찾아보니, 문제에서 합계의 자료형은 `int`가 아닌 `long`으로 처리해 풀린다.
  - 소수 구하기(1929)
    - 에라토스테네스의 체를 활용하여 소수를 미리 구한후, 해당 N, M범위에 있는 소수를 구하면 된다.
  - 소수 찾기(1978)
    - 2부터 입력받은 값까지 `mod`를 활용하여 수소인지 판단하며, 소수인경우 
  - 골드바흐의 추측(6588)
    - c++의 경우 `ios_base::sync_with_stdio(false)`입력을 받아야 시간초과 문제를 해결할 수 있이며, 에라토스테네스의 체를 활용하여 소수를 미리 구하는 방식을 활용해야 시간 안에 문제를 해결할 수 있다. 이러한 방식을 활용하지 않는 경우 값을 구하는데 많은 시간 소모가 발생한다.

- 브루트포스
  - 일곱 난쟁이(2309)
    - `C(n, r) = n! / (r! * (n - r)! )` Combination을 생각하여 문제를 생각해 볼수 있다.
  - 날짜 계산(1476) 
    - `년`이라는 의미를 E S M을 활용해서 나타내며, 이때  E S M의 범위는 다르기 때문에 
  - 테트로미노(14500) 2415 @
    - 
  - 1, 2, 3 더하기(9095)
    - 3중 포문을 활용하여 3,2,1의 값을 변경하여 입력값 보다 크게된경우 break를 주어 횟수를 줄였으며, 같은 숫자 조합여이도 위치가 다르면 다른 경우임으로, `(a + b + c)! / (a! * b! * c!)`을 활용하여 경우의 수를 구하였다. 다른 코드를 참조해보니, 이전의 전체의 합은 현재 경우의 수임을 파악할 수있었다. 차후 문제를 풀경우 다이나믹처럼 푸는게 더빠르고, 손쉬울거라 생각한다.
  - 다음 순열(10972)
    - C++ STL `algorithm`에 정의되어있는 `next_permutation`을 활용하여 문제를 해결할 수 있다. 이때 `next_permutation`을 활용하면 입력받은 값의 다음 순열을 구할 수 있으며, 마지막인 경우 `false`를 반환하기 때문에 마지막을 확인할 수 있다.
  - 이전 순열(10973)
    - 10972번과 동일하게 `algorithm`의 `prev_permutation`을 활용하여 문제를 해결할 수 있다. 이때  `prev_permutation`을 활용하여 이전의 순열을 구할 수 있으며, 처음과 이전의 수열로 될경우 `false`를 반환하기 때문에 처음인지 확인 할 수 있다.
  - 모든 순열(10974)
    - `vector`에 시작 순열을 넣어 준뒤, `next_permutation`을 활용해 끝까지 출력해주면 문제를 해결할 수 있다.
  - 차이를 최대로(10819)
    - `vector`에 값을 순열을 넣어준뒤 정렬을 한다. 그후 `permutation`을 활용하여 순열의 다음 순열을 구하며, 다음 순열로 넘어갈때 마다 기존의 순열 합의max값과 현재 순열 합의 max값을 비교한다. 이때 현재 순열의 합이 큰경우 기존의 max값을 변경한다.
      이후 최대 max값을 구한뒤 출력한다.
  - 외판원 순회2(10971)
    - 2차원 배열을 활용하여, 도시로 이동하는 비용을 저장한다. 이후 `vector`에 저장된 순열을 `next_permutation`을 활용하여 순회하면서 도시에서 도시로 이동하는 최소 비용의 합을 구한다. 이때 주의할 점은 조건에 나와있듯 도시에서 다른 도시로의 이동 비용이 0인 경우와, 돌아갈때 비용이 0인 경우를 확인해 주어야한다.
  - 로또(6603)
    - 로또는 전체의 개수중에 6개를 뽑아 만드는 조합을 출력하는 문제이다. 이때 출력의 순서는 사전순이어야한다. 이 문제를 해결하기 위해서는 1과 0으로 초기화된 백터를 `prev_permutation`을 활용하여 어떤 위치의 숫자가 사용됬는지 확인 가능하다.
  - 연산자 끼워넣기(14888) @
    - N개의 숫자와, N-1개의 연산자가 존재하며, 이때 숫자의 위치는 고정이고 연산자 위치만 바꿔가면서 최대 및 최소의 값을 구해야한다. 이때 주의할점은 연산자 우선순위와 상관없이 앞에서 부터 뒤로 가면서 계산을 하며, 나누기의 경위 `c++14`문법을 기준으로 나누기를 하니 주의해야한다.
      추가적으로 N-1개 연산자를 입력시 +, -, *, / 순으로 개수를 입력을 받아왔으며, 모든 경의 수를 찾기 위해 따로 N-1크기의 `vector`을 만들어 연산자 순으로 순열을 생성한뒤 `next_permutation`을 활용해 경우를 계산했다.
  - 암호 만들기(1759)
    - C개의 문자로, L개의 문자 암호를 만든다. 이때 조건에 따라 중복, 모음 자음 개수, 순서등의 문제를 해결해야한다. 중복의 경우 현재 선택된 것을 로또 문제와 동일하게 1로 채워넣고, 아닌것을 0으로 채워 넣은뒤 `prev_permutation`을 활용하여 순서를 바꾸면서 순열을 구한다.
      모음 자음의 경우 단순하게 a,e,i,o,u를 확인한뒤 모음 자음 개수를 증가시켜서 해결할 수있고, 마지막으로 순서는 C개의 문자열을 처음부터 `sort`를 활용하여 정렬하면 모든 문제를 쉽게 해결할 수 있다.
  - 부분 집합의 합(1182) @
    - N개의 정수를 입력 받고, N개의 정수들 중 더한 값이 S가 되는 경우를 찾는 문제이다. 
      이때 문제를 해결하기 위해 첫째, N개의 정수를  저장하고, 조합에 사용되는 경우를 `vector`에 저장한다. 사용하는 경우 1 사용하지 않는 경우를 0. 조합에 사용되는 경우를 가지고 합을 구한다. 시작은 다사용한다를 가정으로 1로 초기화 하고, 점차 1을 제거하고, 0으로 채워가며, 전체가 0이 된경우 검사를 완료한다.
  - 퇴사(14501) @
  - 연산자 끼워넣기(2)(15658) @
  - === 비트마스크 ===
  - 부분집합의 합
  - 집합(11723)
    - switch보다는 if가 성능이 좋기 때문에, if를 활용하는게 좋다

- N과 M
  - N과 M1(15649)
    - 재귀를 활용하여, 값을 구해야 하며, 값을 뽑았는지 안뽑았는지 확인하는 배열을 만들어 확인을 해주고, 초기화 해주어야, 위치 및 중복 문제를 해결 할 수 있다. 
      또한 순서가 다르면 다른 개수로 치기 때문에,  뽑은것을 저장하고 출력해주어도 좋고, 그냥 뽑고 바로 출력해도 된다.
      추가적으로 c++ `endl`은 성능상 매우 느릭때문에 사용하지말아야한다.
  - N과 M2(15650)
  - N과 M3(15651)
  - N과 M4(15652)
  - N과 M5(15654) 
  - N과 M6(15650)
  - N과 M7(15650)
  - N과 M8(15650)여기까지품
  - N과 M9(15663)
  - N과 M10
  - N과 M11
  - N과 M12

- 그래프와 BFS
  - ABCDE(13023)
  - DFS와 BFS(1260)
  - 이분 그래프(1707)

- 다이나믹 프로그래밍

  - 1로 만들기(1463)

    - 세개의 조건을 적절히 사용해 정수 X의 값을 1로 만들어야 한다.

      1. X가 3로 나누어 떨어지면, 3으로 나눈다.
      2. X가 2로 나누어 떨어지면, 2로 나눈다
      3. 1을 뺀다.

      위 3개의 조건을 적절하게 계산한다면 

      ​	d[x] = d[x - 1] + 1
      ​	d[x] = d[x / 2] + 1
      ​	d[x] = d[x / 3] + 1 
      중에서 최소값을 구하면된다. 이때 주의 할 점은 d[x] = d[x -1] + 1을 통해 d[@]의 값을 초기화 해주며, 초기화된 값을 통해 정정하며 최소 값을 구하게된다. 

  - 2*n 타일링(11726)

    - n은 n -1의 경우와 n -2경우의 타일로 이루어져 있기 때문에 d[n] = d[n-1] + d[n-2]로 구할 수 있다. 추가적으로 값을 구할 때 마다 10007로 나눈뒤 값을 넣어줘야 큰 값의 문제를 해결 할 수 있다.

  - 2*n 타일링2(11727)

    - 2 * 2 블록이 추가된것이므로 d[n -2] 경우를 2*n  타일링 문제에 추가주면 해결할 수 있다.

  - 1, 2, 3 더하기(9095)

    - top-down방식으로 풀었으며, n -1, n -2, n -3 인 경우 재귀를 활용하여 답을 구했다, 이때 입력 받은 값이 -1이 되는 경우 0으로 예외 처리하였으며, 입력 받은 값이 0 인경우 카운트를 증가해 반환함으로써 결과값을 얻을 수 있다.

  - 1, 2, 3 더하기3(15988)

  - 카드 구매하기(11052)

  - 1, 2, 3 더하기 5(15990)

  - 


https://code.plus/course/33

https://code.plus/course/34

https://code.plus/course/35

#### 참고자료

- [백준 결과에 대하여]( <https://www.acmicpc.net/help/judge>)

- [eof에 관하여](https://funylife.tistory.com/entry/%EB%AC%B8%EC%9E%90%EC%99%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-3-EOF%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4)
- [c scanf](http://www.cplusplus.com/reference/cstdio/scanf/)
- [ios_base](https://modoocode.com/144)

- [VScode auto complete 자동완성에 대해](<https://stackoverflow.com/questions/32911977/prevent-autocomplete-in-visual-studio-code>)

