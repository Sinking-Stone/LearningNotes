# <center> 807 · 回文数 II

## 描述

判断一个非负整数 n 的二进制表示是否为回文数

> 我们保证 0 <= n <= 2^32 - 1

## 样例

### 样例 1

#### 输入

```txt
n = 0
```

#### 输出

```txt
True
```

#### 样例解释

0 的二进制表示为：0。

### 样例 2

#### 输入

```txt
n = 3
```

#### 输出

```txt
True
```

#### 样例解释

3 的二进制表示为：11。


### 样例 3

#### 输入

```txt
n = 4
```

#### 输出

```txt
False
```

#### 样例解释

4 的二进制表示为：100。


### 样例 4

#### 输入

```txt
n = 6
```

#### 输出

```txt
False
```

#### 样例解释

6 的二进制表示为：110。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: non-negative integer n.
     * @return: return whether a binary representation of a non-negative integer n is a palindrome.
     */
    
    string binarySystem(int n) {
        if (n == 1)
            return "1";
        else
            return binarySystem(n / 2) + to_string(n % 2);
    }

    bool isPalindrome(int n) {
        // Write your code here
        if(n==0) return true;
        string str = binarySystem(n);
        int len = str.length();
        for (int i = 0, j = len - 1; i < len / 2; i++, j--)
            if (str[i] != str[j])
                return false;
        return true;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: non-negative integer n.
     * @return: return whether a binary representation of a non-negative integer n is a palindrome.
     */

    String binarySystem(int n) {
        if (n == 1)
            return "1";
        else
            return binarySystem(n / 2) + (n % 2)+"";
    }
    
    public boolean isPalindrome(int n) {
        // Write your code here
        if(n==0) return true;
        String str = binarySystem(n);
        int len = str.length();
        for (int i = 0, j = len - 1; i < len / 2; i++, j--)
            if (str.charAt(i) != str.charAt(j))
                return false;
        return true;
    }
}
```