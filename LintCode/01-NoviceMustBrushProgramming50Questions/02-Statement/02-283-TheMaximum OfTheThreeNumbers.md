# <center> 283 · 三数之中的最大值 

## 描述

给三个整数，求他们中的最大值。

## 样例

### 样例  1

#### 输入

```txt
num1 = 1, num2 = 9, num3 = 0
```

#### 输出

```txt
9
```

#### 样例解释

返回三个数中最大的数。

### 样例 2

#### 输入

```txt
num1 = 1, num2 = 2, num3 = 3
```

#### 输出

```txt
3
```

#### 样例解释

返回三个中最大的数字。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param num1: An integer
     * @param num2: An integer
     * @param num3: An integer
     * @return: an interger
     */
    int maxOfThreeNumbers(int num1, int num2, int num3) {
        // write your code here
        if(num1>num2){
            if(num1>num3) return num1;
            else return num3;
        }
        else{
            if(num2>num3) return num2;
            else return num3;
        }
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param num1: An integer
     * @param num2: An integer
     * @param num3: An integer
     * @return: an interger
     */
    public int maxOfThreeNumbers(int num1, int num2, int num3) {
        // write your code here
        if(num1>num2){
            if(num1>num3) return num1;
            else return num3;
        }
        else{
            if(num2>num3) return num2;
            else return num3;
        }
    }
}
```