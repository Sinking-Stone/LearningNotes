# <center> 146 · 大小写转换 II 

## 描述

将一个字符串中的小写字母转换为大写字母。不是字母的字符不需要做改变。

## 样例

### 样例 1

#### 输入

```txt
str = "abc"
```

#### 输出

```txt
"ABC"
```

### 样例 2

#### 输入

```txt
str = "aBc"
```

#### 输出

```txt
"ABC"
```

### 样例 3

#### 输入

```txt
str = "abC12"
```

#### 输出

```txt
"ABC12"
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param str: A string
     * @return: A string
     */
    string lowercaseToUppercase2(string &str) {
        // write your code here
        for(int i=0;i<str.size();i++){
            if(str[i]>='a'&&str[i]<='z') str[i]-=32;
        }
        return str;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param str: A string
     * @return: A string
     */
    public String lowercaseToUppercase2(String str) {
        // write your code here
        
        return str.toUpperCase();
    }
}
```