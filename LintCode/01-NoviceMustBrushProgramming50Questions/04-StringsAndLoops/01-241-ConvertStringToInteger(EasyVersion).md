# <center> 241 · 转换字符串到整数（容易版）

## 描述

给一个字符串, 转换为整数。你可以假设这个字符串是一个有效整数的字符串形式， 且范围在32位整数之间 (-$2^{31}$ ~ $2^{31}$ - 1)。

## 样例

### 样例 1

#### 输入

```txt
"123"
```

#### 输出

```txt
123
```

#### 样例解释

返回对应的数字.

### 样例 2

#### 输入

```txt
"-2"
```

#### 输出

```txt
-2
```

#### 样例解释

返回对应的数字，注意负数.

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param target: A string
     * @return: An integer
     */
    int stringToInteger(string &target) {
        // write your code here
        int ans=atoi(target.c_str());
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param target: A string
     * @return: An integer
     */
    public int stringToInteger(String target) {
        // write your code here
        int ans=Integer.parseInt(target);
        return ans;
    }
}
```