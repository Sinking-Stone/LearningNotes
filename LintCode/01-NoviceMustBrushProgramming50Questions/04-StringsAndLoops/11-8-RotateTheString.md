# <center> 8 · 旋转字符串

## 描述

给定一个字符串str和一个偏移量，根据偏移量原地旋转字符串(从左向右旋转)。  
对于不同的语言，str将以不用的形式给出，例如对于字符串 "abc" ，将以下面的形式给出

    Java: char[] str = {'a', 'b', 'c'};
    Python：str = ['a', 'b', 'c']
    C++：string str = "abc";

> offset >= 0  
> str的长度 >= 0  
> 原地旋转意味着需要在函数中更改字符串s。你不需要返回任何东西。

## 样例

### 样例 1

#### 输入

```txt
str = "abcdefg"
offset = 3
```

#### 输出

```txt
"efgabcd"
```

#### 解释

注意是原地旋转，即str旋转后为"efgabcd"

### 样例 2

#### 输入

```txt
str = "abcdefg"
offset = 0
```

#### 输出

```txt
"abcdefg"
```

#### 解释

注意是原地旋转，即str旋转后为"gabcdef"

### 样例 3

#### 输入

```txt
str = "abcdefg"
offset = 1
```

#### 输出

```txt
"gabcdef"
```

#### 解释

注意是原地旋转，即str旋转后为"gabcdef"


### 样例 4

#### 输入

```txt
str = "abcdefg"
offset = 2
```

#### 输出

```txt
"fgabcde"
```

#### 解释

注意是原地旋转，即str旋转后为"fgabcde"

### 样例 5

#### 输入

```txt
str = "abcdefg"
offset = 10
```

#### 输出

```txt
"efgabcd"
```

#### 解释

注意是原地旋转，即str旋转后为"efgabcd"

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if(str.size()==0) str="";
        else{
            string temp;
            offset%=str.size();
            for(int i=0;i<offset;i++)
                temp.push_back(str[str.size()-offset+i]);
            for(int i=0;i<str.size()-offset;i++)
                temp.push_back(str[i]);
            str.replace(str.begin(),str.end(),temp);
        }
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    public void rotateString(char[] str, int offset) {
        // write your code here
        if(str.length==0) ;
        else{
            char[] temp=new char[str.length];
            offset%=str.length;
            for(int i=0;i<offset;i++)
                temp[i]=str[str.length-offset+i];
            for(int i=0;i<str.length-offset;i++)
                temp[i+offset]=str[i];
            for(int i=0;i<str.length;i++)
                str[i]=temp[i];
        }
    }
}
```