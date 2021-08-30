# <center> 1141 · 月份天数

## 描述

给定年份和月份，返回这个月的天数。

> 1≤year≤10000  
> 1≤month≤12

## 样例

### 样例 1

#### 输入

```txt
2020 
2
```

#### 输出

```txt
29
```

### 样例 2

#### 输入

```txt
2020 
3
```

#### 输出

```txt
31
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param year: a number year
     * @param month: a number month
     * @return: Given the year and the month, return the number of days of the month.
     */
    int getTheMonthDays(int year, int month) {
        // write your code here
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
        if(month==4||month==6||month==9||month==11) return 30;
        if(month==2&&(year%400==0||(year%4==0&&year%100!=0))) return 29;
        return 28;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param year: a number year
     * @param month: a number month
     * @return: Given the year and the month, return the number of days of the month.
     */
    public int getTheMonthDays(int year, int month) {
        // write your code here
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
        if(month==4||month==6||month==9||month==11) return 30;
        if(month==2&&(year%400==0||(year%4==0&&year%100!=0))) return 29;
        return 28;
    }
}
```