# <center> 23 · 判断数字与字母字符

## 描述

给出一个字符c，如果它是一个数字或字母，返回true，否则返回false。

> 如果您使用的是Python语言，那么输入将是一个长度为1的字符串。

## 样例

### 样例 1:

    输入: c = '1'
    输出: true
    解释：'1'属于数字。


## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param c: A character.
     * @return: The character is alphanumeric or not.
     */
    bool isAlphanumeric(char c) {
        // write your code here
        if((c>=48&&c<=57)||(c>=65&&c<=90)||(c>=97&&c<=122)) return true;
        return false;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param c: A character.
     * @return: The character is alphanumeric or not.
     */
    public boolean isAlphanumeric(char c) {
        // write your code here
        if((c>=48&&c<=57)||(c>=65&&c<=90)||(c>=97&&c<=122)) return true;
        return false;
    }
}
```