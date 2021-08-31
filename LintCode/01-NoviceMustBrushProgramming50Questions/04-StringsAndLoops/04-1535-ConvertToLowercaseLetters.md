# <center> 1535 · 转换成小写字母 

## 描述

实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

## 样例

### 样例 1

#### 输入

```txt
"Hello"
```

#### 输出

```txt
"hello" 
```

### 样例 2

#### 输入

```txt
"here"
```

#### 输出

```txt
"here"
```

### 样例 3

#### 输入

```txt
"LOVELY"
```

#### 输出

```txt
"lovely"
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param str: the input string
     * @return: The lower case string
     */
    string toLowerCase(string &str) {
        // Write your code here
        for(int i=0;i<str.size();i++){
            if(str[i]>='A'&&str[i]<='Z') {
	    		str[i]+=32;
	    	}
        }
        return str;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param str: the input string
     * @return: The lower case string
     */
    public String toLowerCase(String str) {
        String string="";
	    for(int i=0;i<str.length();i++) {
	    	if(str.charAt(i)>='A'&&str.charAt(i)<='Z') {
	    		string+=(char)(str.charAt(i)+32);
	    	}
	    	else string+=str.charAt(i);
	    }
	    return string;
    }
}
```