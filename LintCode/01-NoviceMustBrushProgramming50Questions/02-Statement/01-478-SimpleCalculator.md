# <center>478 · 简单计算器

## 描述

给出两个整数 a , b ,以及一个操作符 opeator

```txt
+, -, *, /
```

返回结果 `a<operator>b`

## 样例

### 样例 1：

#### 输入：

```txt
a = 1
b = 2
operator = +
```

#### 输出：

```txt
3
```

#### 解释：

返回 1 + 2 的结果

### 样例 2：

#### 输入：

```txt
a = 10
b = 20
operator = *
```

#### 输出：

```txt
200
```

#### 解释：

返回10 * 20的结果

### 样例 3：

#### 输入：

```txt
a = 3
b = 2
operator = /
```

#### 输出：

```txt
1
```

#### 解释：

返回 3 / 2的结果

### 样例 4：

#### 输入：

```txt
a = 10
b = 11
operator = -
```

#### 输出：

```txt
-1
```

#### 解释：

返回 10 - 11的结果

## 我的代码

### C++语言

```c++
class Calculator {
public:
    /**
     * @param a: An integer
     * @param operator: A character, +, -, *, /.
     * @param b: An integer
     * @return: The result
     */
    int calculate(int a, char Operator, int b) {
        // write your code here
        if(Operator=='+') return a+b;
        if(Operator=='-') return a-b;
        if(Operator=='*') return a*b;
        if(Operator=='/') return a/b;
    }
};
```

### Java语言

```java
public class Calculator {
    /**
     * @param a: An integer
     * @param operator: A character, +, -, *, /.
     * @param b: An integer
     * @return: The result
     */
    public int calculate(int a, char operator, int b) {
        // write your code here
        if(operator=='+') return a+b;
        if(operator=='-') return a-b;
        if(operator=='*') return a*b;
        if(operator=='/') return a/b;
        return 0;
    }
}
```