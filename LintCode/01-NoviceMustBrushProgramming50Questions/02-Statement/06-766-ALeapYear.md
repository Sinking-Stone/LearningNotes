# <center> 766 · 闰年

## 描述

判断给出的年份 n 是否为闰年. 如果 n 为闰年则返回 true

> 闰年是包含额外一天的日历年. 如果年份可以被 4 整除且不能被 100 整除 或者 可以被 400 整除, 那么这一年为闰年. --wikipedia

## 样例

### 样例 1

#### 输入

```txt
n = 2008
```

#### 输出

```txt
true
```

### 样例 2

#### 输入

```txt
n = 2018
```

#### 输出

```txt
false
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: a number represent year
     * @return: whether year n is a leap year.
     */
    bool isLeapYear(int n) {
        // write your code here
        if(n%400==0||(n%4==0&&n%100!=0)) return true;
        return false;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: a number represent year
     * @return: whether year n is a leap year.
     */
    public boolean isLeapYear(int n) {
        // write your code here
        if(n%400==0||(n%4==0&&n%100!=0)) return true;
        return false;
    }
}
```