# <center> 422 · 最后一个单词的长度

## 描述

给定一个字符串， 包含大小写字母、空格 ' '，请返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

> 一个单词的界定是，由字母组成，但不包含任何的空格。

## 样例

### 样例 1

#### 输入

```txt
"Hello World"
```

#### 输出

```txt
5
```

### 样例 2

#### 输入

```txt
"Hello LintCode"
```

#### 输出

```txt
8
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param s: A string
     * @return: the length of last word
     */
    int lengthOfLastWord(string &s) {
        // write your code here
        int ans=0;
        bool flag=false;
        if(s.size()==0) return 0;
        else{
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]!=' '){
                    ans++;
                    flag=true;
                }
                if(s[i]==' '&&flag) break;
            }
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param s: A string
     * @return: the length of last word
     */
    public int lengthOfLastWord(String s) {
        // write your code here
        int ans=0;
        boolean flag=false;
        if(s.length()==0) return 0;
        else{
            for(int i=s.length()-1;i>=0;i--){
                if(s.charAt(i)!=' '){
                    ans++;
                    flag=true;
                }
                if(s.charAt(i)==' '&&flag) break;
            }
        }
        return ans;
    }
}
```