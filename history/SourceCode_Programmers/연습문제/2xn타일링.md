```c++
#include <string>
#include <vector>

using namespace std;
long long blocks[60001];
int solution(int n) {
    blocks[1] = 1;
    blocks[2] = 2;
    blocks[3] = 3;
    
    for(int i=4; i<=n; ++i) {
        long long tempNum = (blocks[i-1] + blocks[i-2]) % 1000000007;
        blocks[i] = tempNum;
    }
    return blocks[n];
}
```

```java
class Solution {
    public int solution(int n) {
        int[] tempArray = new int[n + 1];
        tempArray[1] = 1;
        tempArray[2] = 2;
        tempArray[3] = 3;
        
        for(int i=4; i<= n; ++i) {
            tempArray[i] = (tempArray[i-1] + tempArray[i-2]) % 1000000007;
        }
        return tempArray[n];
    }
}
```

```javascript
function solution(n) {
    var num_array = new Array(n + 1);
    num_array[1] = 1;
    num_array[2] = 2;
    num_array[3] = 3;
    
    for(let i=4; i<=n; ++i) {
        num_array[i] = (num_array[i-1] + num_array[i-2]) % 1000000007;
    }
    return num_array[n];
}
```