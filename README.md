# 알고리즘 공부

# 백준 문제
## 알고리즘 A

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

## 알고리즘 B
https://code.plus/course/32

- ### 수학

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
    - 전체의 틀을 준비한뒤, 틀에 해당하는지 아닌지 판단한 후 해당하는 값들을 더해준다.
      한개라도 틀에서 이탈한 경우 check를 해서 최대값 계산을 할때 제외해준다. 문제 없이 4개를 다 더한 경우 이 경우가 최대 값인지 확인해 준다.
    - 이 문제의 경우 5개의 블록이 있으며, 블록으로 만들수 있는 경우는 총 19가지이다. 그러므로 19가지의 if else를 통해 검사를 할 수 있으며, 이 외에도 19개의 블록을 미리 만들고 검사할 수 있다.
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
    - 이 문제는 상담했을때 최대의 값을 구하는 문제이다. 이를 해결하기 위해서는 해당 날짜에 상담을 시작하면 퇴사 전까지 상담이 가능한지와, 퇴사 전까지 상담을 했을때 최대의 값을 구해야한다.
      이를 해결하기 위해 시작한 날짜가 퇴사 날짜 보다 작은지와, 이날 상담하면, 퇴사 전까지 상담이 가능하며 돈을 받을 수 있다를 판단해줘야한다.
  - 연산자 끼워넣기(2)(15658) @
  - === 비트마스크 ===
  - 부분집합의 합(1182)
    - 비트 마스크를 활용해서 문제를 풀수 있음. 1 ~ (1 << N)개의 경우의 수를 확인하는 식으로
      `if( i & (1 << j))`를 통해 해당 숫자가 사용중인지 확인하고, 사용한다면 더해준다
      bit연산을 활용하여 경우의 수를 찾고 정할 수 있음을 알 수 있었다.
  - 집합(11723)
    - switch보다는 if가 성능이 좋기 때문에, if를 활용하는게 좋다

- ### N과 M

  - N과 M1(15649)
    - 재귀를 활용하여, 값을 구해야 하며, 값을 뽑았는지 안뽑았는지 확인하는 배열을 만들어 확인을 해주고, 초기화 해주어야, 위치 및 중복 문제를 해결 할 수 있다. 
      또한 순서가 다르면 다른 개수로 치기 때문에,  뽑은것을 저장하고 출력해주어도 좋고, 그냥 뽑고 바로 출력해도 된다.
      추가적으로 c++ `endl`은 성능상 매우 느릭때문에 사용하지말아야한다.
  - N과 M2(15650)
  - N과 M3(15651)
  - N과 M4(15652)
  - N과 M5(15654) 
  - N과 M6(15655)@
  - N과 M7(15656)
  - N과 M8(15657)여기까지품
  - N과 M9(15663)@
  - N과 M10@
  - N과 M11@
  - N과 M12@

- ### 그래프와 BFS

  - ABCDE(13023)@

  - DFS와 BFS(1260)

    - DFS, BFS를 직접 구현해보고 실험해보는 문제이다. DFS의 경우 재귀를 활용해서 문제를 해결했고, BFS의 경우 `while`문을 통해 문제를 해결했다.

    - 이 문제의 경우, 테스트 케이스 및 연결고리에 문제가 없어서 `if true`체크 없이 동작이 가능하다. 하지만 BFS를 정확하게 구현하기 위해서는 사용한것은 `true`체크를 해줘야한다.

      ```c++
      vector<int> tempVector[1001];  // 오름차순으로 정렬이 되있다고 가정
      bool check[1001] = {false, };
      // DFS
      void DFS(int temp)
      {
          cout << temp << '\n';
          check[temp] = true;
          for(int i = 0; i < tempVector[temp].size(); ++i)
          {
              int tempT = tempVector[temp][i];
              if(!check[temp])
              {
                  DFS(tempT);
      		}
          }
      }
      // BFS
      void BFS(int temp)
      {
      	queue<int> tempQueue;
      
      	tempQueue.push(temp);
      	check[temp] = true;
      	while (!tempQueue.empty())
      	{
      		int tempNum = tempQueue.front();
      		tempQueue.pop();
      		cout << tempNum << ' ';
      		for (int i = 0; i < tempVector[tempNum].size(); i++)
      		{
      			if (!check[tempVector[tempNum][i]])
      			{
      				check[tempVector[tempNum][i]] = true;
      				tempQueue.push(tempVector[tempNum][i]);
      			}
      		}
      	}
      }
      ```

  - 연결 요소의 개수(11724)

    - 연결 요소를 구하는 문제로, BFS를 활용해서 문제를 풀었다. 일단 `vector`연결된 간선의 개수를 넣은 후 정렬한다. 정렬한 후 BFS코드를 통해 연결요소를 확인하고, 연결된 요소가 없는 경우 count값을 증가시켜주고, check배열에서 false 배열을 찾아 넣어준 후, 다시 BFS를 통해 연결요소를 구한다.
      추가적으로 정점은 1부터 시작하므로, for문의 초기 값을 1부터 시작한다.
    - [그래프에 관한 자료](https://ratsgo.github.io/data%20structure&algorithm/2017/11/18/graph/)

  - 이분 그래프(1707)@

  - 단지번호붙이기(2667)

    - BFS를 활용해 문제를 풀었으며, 문제를 해결하기 위해 map에서 단지를 파악하기 위해 연결 요소 문제와 동일하게 문제를 풀었으며, 이때 위치를 파악하기 위해 `pair`를 활용했다. 또한 단지의 개수를 알아야 하기 때문에, 단지를 확인할때 마다 값을 더해주며 단지의 개수를 확인하고, 마지막 부분에 `vector`에 추가해 주었다.
      이때 참고 사항으로 상하 좌우를 확인 해야하기 때문에 상하 좌우를 확인하는 코드를 추가해야한다.

  - 섬의 개수(4963)

    - 단지번호 붙이기 문제와 비슷하게 풀었으며, 차이점으로는 상하 좌우 대각선을 포함하여, 8방향을 확인해야했다. 그러므로 해당 확인하는 배열을 추가했고, 주의 사항으로 0 0 값이 입력되기 전에는 다시 맵을 만들어 확인해야 하므로, 초기화를 잘해줘야 한다.

  - 미로 탐색(2178)

    - 대표적인 BFS문제로, DFS문제를 풀경우 시간 초과 및 경우를 명확하게 구하기 업렵다.
      그러므로 BFS를 활용하여, 최단거리 탐색을 진행하며, 이전에 지나간 곳을 check해 나가듯, check한 곳에 가중치를 두어, 최단거리를 구할 수 있다.

  - 토마토(7576)

    - BFS문제로 해결을 했고, 처음 입력 받을 때, 가지 못하는 곳과 수확해야 하는곳을 표시 및 `queue`에 넣어 두고, `queue`에 넣어둔 값을 bfs를 활용해서 가중치를 구하고, 구한 가중치중 값이 가장 큰경우 -1을 해서 최대 일수를 구해왔다. 이때 주의할점은,  bfs가 끝나고도 0이 존재하면 -1을 반환줘야 한다.

  -  숨바꼭질(1697)

    - BFS문제로 해결할 수 있는 최단 거리를 구하는 문제이다. 이경우 해당 위치에서 `x-1`, `x+1`, `x*2`의 경우를 한번도 안간경우 `queue`에 넣어 최단 거리를 구하는 문제이다. 이때 주의 할 점은 해당 위치를 찾으면 멈춰야 하는 것과, 이동한 초를 정확하게 구하는 것이다.

  - 이모티콘(14226)@

- ### 다이나믹 프로그래밍

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

    - bottom up 방식으로도 풀었으며, 처음 1인경우는 0이며, `for`을 활용하여 2부터 입력받은 범위까지 최소의 경우를 구한다. 이때  d[n]은 d[n -1] + 1, d[n/2] + 1, d[n/3] + 1의 값을 확인 하여 최소인 값을 d[n]에 넣어주면서 올라가기 때문에 중복되는 연산을 빠르게 제외 시킬 수 있다

  - 2*n 타일링(11726)

    - n은 n -1의 경우와 n -2경우의 타일로 이루어져 있기 때문에 d[n] = d[n-1] + d[n-2]로 구할 수 있다. 추가적으로 값을 구할 때 마다 10007로 나눈뒤 값을 넣어줘야 큰 값의 문제를 해결 할 수 있다.

  - 2*n 타일링2(11727)

    - 2 * 2 블록이 추가된것이므로 d[n -2] 경우를 2*n  타일링 문제에 추가주면 해결할 수 있다.

  - 1, 2, 3 더하기(9095)

    - top-down방식으로 풀었으며, n -1, n -2, n -3 인 경우 재귀를 활용하여 답을 구했다, 이때 입력 받은 값이 -1이 되는 경우 0으로 예외 처리하였으며, 입력 받은 값이 0 인경우 카운트를 증가해 반환함으로써 결과값을 얻을 수 있다.
      결국 맨마지막에 -1온경우와 -2가 온경우  -3이 온경우를 다 더하는 문제

  - 1, 2, 3 더하기3(15988)

    - bottom up 방식으로 문제를 풀었으며, d[n] = d[n -1] + d[n -2] + d[n -3]이므로 이를 활용해서 문제를 풀었다.

  - 카드 구매하기(11052)

    - bottom up 방식을 활용하여 문제를 해결했다. 2중 포문을 활용하여, 2부터 범위 까지의 값을 구해 나갔고, 최대의 값은 d[n] = p[@] + d[n - @]이므로 이때의 최대값을 확인하여 d[n]의 값을 구했다.

  - 카드 구매하기2(16194)

    - 카드 구매하기와 동일한 방식으로 문제를 풀었으며, 이때 주의할 점은 최소 값을 구한다는 문제이다.
      최소값을 구하기 위해 초기 초기 및 대소 비교를 주의해야한다.

  - 1, 2, 3 더하기 5(15990)

    - 해당 문제의 경우 1,2,3 더하기 문제와 동일하지만, 연속된 값은 제외해야하는 조건이 추가되어 있다.
      그렇기 때문에 조건을 추가해서 값을 구해 줘야 한다. 이전 1,2,3 더히가는 그냥  `d[n] = d[n -1] + d[n -2] + d[n -3]`을 통해 값을 구했다면, 이 경우는 `d[n][1] + d[n][2] + d[n][3]`인 경우를 합해서 구해줘야한다. 왜냐하면 연속된 값을 제외 시키기 때문에 앞에 값과 뒤에 나오는 값이 무엇인지 정해 줌으로 연속을 방지한다.
      `d[i][1] = (d[i -1][2] + d[i -1][3])`
      `d[i][2] = (d[i -2][1] + d[i -2][3])`
      `d[i][3] = (d[i -3][1] + d[i -3][2])`
      또한 값이 일정이상 부터는 값이 엄청 커지므로, 자료형 또는 `mod`를 명확히 해주어, 오버플로우가 없게 출력해야한다.

  - 쉬운 계단 수(10844)

    - 인접한 모든 자리수의 차이가 1이나를 수를 계단수라고 하는데 이를 구하기 위해서는,  아래와 같은 경우를 구해한다. 주의할 점은 2자리 부터는 `10`의 경우가 발생하기 때문에 0인 경우도 유의해서 구해야한다.

      ```c++
      if(j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
      if(j + 1 < 10) d[i][j] += d[i - 1][j + 1];
      ```

  - 오른수(11057)

    - 오르막 수는 같은수 또는 큰수가 연속되어야 한다. 그렇기 때문에 아래와 같이 앞이 작은지 확인한 후, 값을 그게 맞다면 더해 준다

      ```c++
          for(int i = 0; i <= 9; ++i)
          {
              d[1][i] = 1;
          }
      
          for(int i = 2; i <= num; ++i)
          {
              for(int j = 0; j <= 9; ++j)
              {
                  for(int k = 0; k <= j; ++k)
                  {
                      d[i][j] += d[i -1][k];
                      d[i][j] %= mod;
                  }
              }
          }
      ```

  - 이친수(2193)

    - 이친수의 경우 앞에는 무조건 1로 시작되면 1은 연속될수 없다는 조건이 있다. 그러므로 문제를 해결하기 위해서는 아래 코드와 같이 i자리가 0인 경우와, 1인경우 올수 있는 가지수를 더해가며 구한다.
      이를 통해 전체 경우의 수를 구할 수 있다.

      ```c++
              d[i][0] = d[i - 1][0] + d[i - 1][1];
              d[i][1] = d[i - 1][0];
      ```

  - 스티커(9465)

    - 해당 문제는 2n개의 스티커중 @개를 골라 최대의 값을 구하는 문제이다. 이때 스티커는 2 * N의 행렬을 가지며, 특정 위치의 스티커를 선택한경우, 해당 스티커를 기준으로 전후 좌후 스티커를 사용할 수 없다 그렇기 때문에, 해당 줄의 스티커를 사용하지 않은  경우, 위의 스티커를 사용한 경우, 아래 스티커를 사용한 경우를 각각 구해서 최대의 값을 구해야한다. 만약 최대의 값을 구한다음 값을 구하면 쉽다라고 생각할 수 있지만, 예외인 경우가 존재하기 때문에 처음 부터 끝까지 값을 구해가며, 마지막에 최대값을 비교해서 구하면 된다.

      ```c++
             d[1][0] = 0;
              d[1][1] = value[1][0];
              d[1][2] = value[1][1];
      
              for(int i = 2; i <= N; i++)
              {
                  d[i][0] = d[i-1][0] > d[i-1][1] ? 
                          d[i-1][0] > d[i-1][2] ? d[i-1][0] : d[i-1][2] :
                          d[i-1][1] > d[i-1][2] ? d[i-1][1] : d[i-1][2];
      
                  d[i][1] = d[i-1][0] > d[i-1][2] ? d[i-1][0] : d[i-1][2];
                  d[i][1] += value[i][0];
      
                  d[i][2] = d[i-1][0] > d[i-1][1] ? d[i-1][0] : d[i-1][1];
                  d[i][2] += value[i][1];
              }
      ```

  - 포도주 시식(2156)

    - 해당 문제는 1차원 배열에 있는 포도주를 많이 경우를 찾는 문제이다. 이때 주의할 점은 연속해서 3번 마실수 없다. 그렇기 때문에 값을 구할 때 유의해야하며, 안먹는 경우, 1번 먹는 경우, 2번 연속해서 먹는 경우를 기준으로 값을 더해서 구해주면 해결할 수 있다. 추가적으로 안먹는 경우는 이전의 경우에서 최대값을 찾아 넣어줘야한다.

      ```c++
          for(int i = 3; i <= N; ++i)
          {
              d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
              d[i][1] = d[i -1][0] + value[i];
              d[i][2] = d[i -1][1] + value[i];
          }
      ```

  - 가장 긴 증가하는 부분 수열(11053)

    - LIS(longest Increasing Subsequence)라는 이름을 가진 문제이다.  가장 긴 증가하는 부분 수열을 찾는 문제이며, 이때 특정 위치를 기준으로 아래 수에서 내가 증가되는 지를 확인하 및 최대 값을 구해주면 되는 문제이다.

      ```c++
      	for (int i = 1; i <= N; ++i)
      	{
      		d[i] = 1;
      		for (int j = i - 1; j >= 1; --j)
      		{
      			if (A[i] > A[j])
      			{
      				if (d[i] <= d[j])
      					d[i] = d[j] + 1;
      			}
      		}
      	}
      ```

  - 가장 긴 증가하는 부분 수열4(14002)

    - 방식은 가장긴 증가하는 부분수열과 동일하며 추가적으로 `d[n][2]`의 크기로 정한뒤 0에는 연속되는 값을, 1에는 연속되는 값들의 연결고리 값을 넣어준다. 이를 통해 최대의 연속되는 값을 구한뒤, 연속되는 값의 1번 값을 통해 어떤 값들을 선택했는지 출력한다.

  - 가장 큰 증가하는 부분 수열(11055)

    - 가장 긴 증가하는 부분 수열과 비슷하게 풀수 있다. 가장 긴 증가하는 부분 수열에서는 증가하는 연속되는 가장 긴 경우를 구했다면, 가장 큰 증가 부분 수열에서는 연속되는 가장 큰값을 구해주면 된다.

      ```c#
      for(int i = 1; i <= N; ++i)
      {
          d[i] = A[i];
          for(int j = i; j >= 1; ++j)
          {
              if(A[i] > A[j])
              {
                  if(d[i] < d[j] + a[i])
                      d[i] = d[j] + a[i];
              }
          }
      }
      ```

  - 가장 긴 감소하는 부분 수열(11722)

    - 가장 긴 증가하는 부분 수열을 역으로 해서 풀어도 되고, 작은 경우 증가한다로 바꿔서 풀어도 되는 아주 쉬운 문제이다.

      ```c++
      for(int i = 1; i <= N; ++i)
      {
          d[i] = 1;
          for(int j = i; j >= 1; ++j)
          {
              if(A[i] < A[j] && d[i] < d[j] + 1)
                  d[i] = d[j] + 1;
          }
      }
      ```

  - 가장 긴 바이토닉 부분 수열(11054)

    - LIS의 방식을 활용해서 문제를 풀었다. 
      처음에는 왼쪽 방향으로 LIS의 값을 구하고, 두번째는 오른쪽 방향으로 LIS값을 구한다. 이렇게 값을 구하고 해당 같은 위치의 왼쪽 오른쪽 값을 더해준다. 이후 최대값을 구한 후 -1을 빼준게 최대의 값이 된다. -1을 해주는 이유는 왼쪽 오른쪽 총 2번을 지나가기 때문에 중복이 발생한다. 그러므로 최대 값에서 -1을 해줘야 진짜 최대 값이 된다.

  - 연속합(1912)

    - 연속되는 합의 최대 값을 구하는 문제이기 때문에, 연속되는 숫자들의 합이 큰지 작은지 판단하여 값을 변경해준뒤 가장 큰 값을 구하면된다.

  - 연속합2(13398)

    - 연속되는 합의 최대 값을 구하는 문제이면서, 한자리 숫자를 제외했을 때 연속되는 숫자들의 최대 합을 구하는 문제이다. 이때 전체에서 최대의 값과, 한자리를 빼고 합했을 때의 최대값을 비교해서 최대의 값을 구해야한다.

  - 제곱수의 합(1699)

    - N의 값을 제곱수의 합으로 구하는 문제이며, 최소의 개수를 구해야하는 문제이다. 
      아래와 같이 해당 경우에 값을 바꿔주면서 구하면 문제를 해결할 수 있다.

      ```c++
      if(d[i] > d[i - j * j] + 1)
          d[i] = d[i - j * j] + 1
      ```

  - 합분해(2225)

    - 0부터 N까지의 정수 K개를 더해서 합이 N이되는 경우의 수를 찾는 문제이다. 이때 각각의 경우를 합해주면서 찾아가면 쉽게풀 수 있다.

      ```c++
      
          d[0][0] = 1L;
          for(int i = 1; i <= K; ++i)
          {
              for(int j = 0; j <= N; ++j)
              {
                  for(int l = 0; l <= j; ++l)
                  {
                      d[i][j] += d[i - 1][j - l];
                      d[i][j] %= mod;
                  }
              }
          }
      ```

  - 합분해2(13707)

    - 합분해와 동일하게 0부터 N가지의 정수 K개를 더해 합이 N이되는 경우를 찾는 문제이지만, 추가적으로 순서가 바뀌어도 다른 경우로 인정한다. 그러므로 아래와 같이 2가지 경우를 더해 주면 해결할 수 있다. 주의 할 점은 N의 입력 범위는 1 ~20이고 찾는 범위는 0 ~ N이므로 주의해야한다.

      ```c++
          for(int i = 0; i <= N; ++i)
          {
              d[1][i] = 1;
          }
      
          for(int i = 2; i <= K; ++i)
          {
              for(int j = 0; j <= N; ++j)
              {
                  d[i][j] = d[i - 1][j] + d[i][j -1]; 
                  d[i][j] %= mod;
              }
          }
      ```

      

아직 못푼 문제



## 알고리즘 C

https://code.plus/course/33

### 브루트 포스

리모컨(1107)



https://code.plus/course/34

https://code.plus/course/35

#### 참고자료

- [백준 결과에 대하여]( <https://www.acmicpc.net/help/judge>)

- [eof에 관하여](https://funylife.tistory.com/entry/%EB%AC%B8%EC%9E%90%EC%99%80-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-3-EOF%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4)

- [c scanf](http://www.cplusplus.com/reference/cstdio/scanf/)

- [ios_base](https://modoocode.com/144)

- [VScode auto complete 자동완성에 대해](<https://stackoverflow.com/questions/32911977/prevent-autocomplete-in-visual-studio-code>)

- [memset](http://www.cplusplus.com/reference/cstring/memset/)

- 입력에 관하여

  ```c++
  char tempChar[100][100];
  for(int i = 0; i < 100; ++i)
  {
      cin >> tempChar[i];
  }
  ```

  



[SungBeom/다이나믹 프로그래밍/1, 2, 3 더하기(9095)_3.cpp](https://github.com/as-is-as/Basic/pull/26/files#diff-425ba894b91729586012873a57c3a06b)

