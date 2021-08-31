# <center> 771 · 二阶阶乘

## 描述

给定一个数n，返回该数的二阶阶乘。在数学中，正整数的二阶阶乘表示不超过这个正整数且与它有相同奇偶性的所有正整数乘积。


+ 结果一定不会超过long。
+ n是一个正整数


## 样例

### 样例 1

#### 输入

```txt
n = 5
```

#### 输出

```txt
15
```

#### 解释

5!! = 5 * 3 * 1 = 15

### 样例 2

#### 输入

```txt
n = 6
```

#### 输出

```txt
48
```

#### 解释

6!! = 6 * 4 * 2 = 48

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: the given number
     * @return:  the double factorial of the number
     */
    long long doubleFactorial(int n) {
        // Write your code here
        if(n==0) return -1;
        long long ans=1;
        if(n%2==0){
            for(int i=2;i<=n;i+=2)
                ans*=i;
        }
        else{
            for(int i=1;i<=n;i+=2)
                ans*=i;
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: the given number
     * @return:  the double factorial of the number
     */
    public long doubleFactorial(int n) {
        // Write your code here
        if(n==0) return -1;
        long ans=1;
        if(n%2==0){
            for(int i=2;i<=n;i+=2)
                ans*=i;
        }
        else{
            for(int i=1;i<=n;i+=2)
                ans*=i;
        }
        return ans;
    }
}
```