# <center> 145 · 大小写转换

## 描述

将一个字符由小写字母转换为大写字母

假设输入的一定是小写字母

## 样例

### 样例 1:

    输入: 'a'
    输出: 'A'

### 样例 2:

    输入: 'b'
    输出: 'B'

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param character: a character
     * @return: a character
     */
    char lowercaseToUppercase(char character) {
        // write your code here
        return character-32;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param character: a character
     * @return: a character
     */
    public char lowercaseToUppercase(char character) {
        // write your code here
        return (char)(character-32);
    }
}
```