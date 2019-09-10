# 프로그래밍 대회에서 사용하는 C, C++, STL
- https://code.plus/course/2
## C
## C++
## STL Container
## String
## STL Algorithm
개수 세기(10807)
- map을 활용하여 문제를 해결했다. 입력되는 집합에서 중복된 값이 이전에 있다면, value를 증가시 키고, 없는 경우 새로 insert를 해주었다. 그후 v의 값은 map에 key를 의미하기 때문에 map[v]를 출력함으로 결과를 알아 냈다.

알파벳 개수(10808)
- 해당 문제는 입력받은 영단어의 알파벳 개수를 구하고, a-z의 전체 개수를 출력하는 문제이다. 이 문제를 해결하기 위해 `string`으로 입력 값은 받은 후, 입력받은 문자열 길이만큼 반복하면서, 해당 문자가 어떤 문자인지 파악한 후, 26의 크기를 가진 배열에 값을 증가 시켜주었다. 이때 배열의 위치는 `string[i] - 'a'`를 활용해서 위치를 구한후 증가 시켜주었다. 이후 저장된 배열을 출력하여, 결과를 출력했다.