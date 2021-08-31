# <center> 936 · 首字母大写 

## 描述

输入一个英文句子，将每个单词的第一个字母改成大写字母

> 1. 这个句子可能并不是一个符合语法规则的句子。  
> 2. 句子长度小于等于100。


## 样例

### 样例 1

#### 输入

```txt
s =  "i want to get an accepted"
```

#### 输出

```txt
"I Want To Get An Accepted" 
```

### 样例 2

#### 输入

```txt
s =  "i jidls    mdijf  i  lsidj  i p l   "
```

#### 输出

```txt
"I Jidls    Mdijf  I  Lsidj  I P L   "
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param s: a string
     * @return: a string after capitalizes the first letter
     */
    string capitalizesFirst(string &s) {
        // Write your code here
        string ans="";
    	if(s[0]!=' ') ans+=(char)(s[0]-32);
    	else  ans+=" ";
        for(int i=1;i<s.size();i++){
        	if(s[i-1]==' '&&(s[i]<='z'&&s[i]>='a'))
                ans+=(char)(s[i]-32);
            else ans+=s[i];
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param s: a string
     * @return: a string after capitalizes the first letter
     */
    public String capitalizesFirst(String s) {
        // Write your code here
         String ans="";
    	if(s.charAt(0)!=' ') ans+=(char)(s.charAt(0)-32);
    	else  ans+=" ";
        for(int i=1;i<s.length();i++){
        	if(s.charAt(i-1)==' '&&(s.charAt(i)<='z'&&s.charAt(i)>='a'))
                ans+=(char)(s.charAt(i)-32);
            else ans+=s.charAt(i);
        }
        return ans;
    }
}
```