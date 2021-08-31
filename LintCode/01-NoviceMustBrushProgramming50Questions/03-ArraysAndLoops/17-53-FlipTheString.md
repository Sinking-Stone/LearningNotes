# <center> 53 · 翻转字符串

## 描述

给定一个字符串，逐个翻转字符串中的每个单词。

> + 单词的构成：无空格字母构成一个单词，有些单词末尾会带有标点符号  
> + 输入字符串是否包括前导或者尾随空格？  
> 可以包括，但是反转后的字符不能包括
> + 如何处理两个单词间的多个空格？  
> 在反转字符串中间空格减少到只含一个

## 样例

### 样例 1

#### 输入

```txt
s = "the sky is blue"
```

#### 输出

```txt
"blue is sky the"
```

#### 解释

返回逐字反转的字符串。

### 样例 2

#### 输入

```txt
s = "hello world"
```

#### 输出

```txt
"world hello"
```

#### 解释

返回逐字反转的字符串。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        // write your code here
        string ans="";
        s+=" ";
        int start;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '&&!flag){
                start=i;
                flag=true;
            } 
            if(s[i]==' '&&flag){
                ans=s.substr(start,i-start)+" "+ans;
                flag=false;
            }
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /*
     * @param s: A string
     * @return: A string
     */
    public String reverseWords(String s) {
        // write your code here
        if(s==null||s.length()==0) return s;
        int num=0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)!=' ') num++;
        }
        if(num==0) return "";
        String ans="";
        s+=" ";
        int start=0;
        boolean flag=false;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=' '&&!flag){
                start=i;
                flag=true;
            } 
            if(s.charAt(i)==' '&&flag){
                ans=s.substring(start,i)+" "+ans;
                flag=false;
            }
        }
        ans=ans.substring(0,ans.length()-1);
        return ans;
    }
}
```