# <center> 298 · 寻找素数

## 描述

输出n以内所有的素数。

> 保证 n 是100以内的整数。

## 样例

### 样例 1

#### 输入

```txt
5
```

#### 输出

```txt
[2, 3, 5]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: an integer
     * @return: return all prime numbers within n.
     */

    bool isPrem(int x){
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0) return false;
        }
        return true;
    }
    
    vector<int> prime(int n) {
        // write your code here
        vector<int> ans;
        for(int i=2;i<=n;i++){
            if(isPrem(i)==true) ans.push_back(i);
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: an integer
     * @return: return all prime numbers within n.
     */
    
    boolean isPrem(int x){
        for(int i=2;i<=Math.sqrt(x);i++){
            if(x%i==0) return false;
        }
        return true;
    }

    public List<Integer> prime(int n) {
        // write your code here
        List<Integer> ans=new ArrayList<>();
        for(int i=2;i<=n;i++){
            if(isPrem(i)==true) ans.add(i);
        }
        return ans;
    }
}
```