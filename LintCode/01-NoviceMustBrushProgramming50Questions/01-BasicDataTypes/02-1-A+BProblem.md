# <center> 1 · A + B 问题

## 描述

给出两个整数 aaa 和 bbb , 求他们的和并以整数（int）的形式返回。

> 你不需要从标准输入流读入数据，只需要根据aplusb传入的两个参数 a 和 b，计算他们的和并返回就行。  
> $−2^{31}$≤a , b≤$2^{31}$-1  
> $−2^{31}$≤a+b≤$2^{31}$−1

## 样例

### 样例 1

#### 输入

```txt
a = 1
b = 2
```

#### 输出

```txt
3
```
#### 解释

a + b = 1 + 2 = 3

### 样例 2

#### 输入

```txt
a = -1
b = 1
```

#### 输出

```txt
0
```
#### 解释

a + b = -1 + 1 = 0

## 挑战

显然你可以直接返回 a + b，但是你是否可以挑战不这样做？（不使用+等算数运算符）

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
        // write your code here
        return a+b;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    public int aplusb(int a, int b) {
        // write your code here
        return a+b;
    }
}
```