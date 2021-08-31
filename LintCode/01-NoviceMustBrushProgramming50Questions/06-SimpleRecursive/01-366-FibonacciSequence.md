# <center> 366 · 斐波纳契数列

## 描述

查找斐波纳契数列中第 N 个数。

所谓的斐波纳契数列是指：

    前2个数是 0 和 1 。
    第 i 个数是第 i-1 个数和第i-2 个数的和。

斐波纳契数列的前10个数字是：

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

> 在测试数据中第 N 个斐波那契数不会超过32位带符号整数的表示范围

## 样例

### 样例 1

#### 输入

```txt
1
```

#### 输出

```txt
0
```

#### 样例解释

返回斐波那契的第一个数字，是0.

### 样例 2

#### 输入

```txt
2
```

#### 输出

```txt
1
```

#### 样例解释

返回斐波那契的第二个数字是1.

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n==1) return 0;
        if(n==2||n==3) return 1;
        int a=1,b=1,ans=0;
        for(int i=0;i<n-3;i++){
            ans=a+b;
            b=a;
            a=ans;
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
     * @return: an ineger f(n)
     */
    public int fibonacci(int n) {
        // write your code here
        if(n==1) return 0;
        if(n==2||n==3) return 1;
        int a=1,b=1,ans=0;
        for(int i=0;i<n-3;i++){
            ans=a+b;
            b=a;
            a=ans;
        }
        return ans;
    }
}
```