# <center> 353 · 最大字母

## 描述

给定字符串S，找到最大的字母字符，其大写和小写字母均出现在S中，则返回此字母的大写，若不存在则返回"NO"。

> 1<=len(s)<=$10^6$

## 样例

### 样例 1

#### 输入

```txt
S = "admeDCAB"
```

#### 输出

```txt
"D"
```

### 样例 2

#### 输入

```txt
S = "adme"
```

#### 输出

```txt
"NO"
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param s: a string
     * @return: a string
     */
    string largestLetter(string &s) {
        // write your code here
        if(s.size()==0||s.size()==1) return "NO";
        char max='A';
        int j,index=0;
        int flag=0;
        for(j=0;j<s.size()-1;j++){
            if((s[j]<='z'&&s[j]>='a'&&s[j+1]>='A'&&s[j+1]<='Z')||(s[j+1]<='z'&&s[j+1]>='a'&&s[j]>='A'&&s[j]<='Z'))
                break;
        }
        if(j==s.size()-1) return "NO";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                if(max<s[i]){
                    max=s[i];
                    index=i;
                    flag=1;
                }
            }   
        }
        string ans;
        ans.push_back(s[index]);
        if(flag==0) return "NO";
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param s: a string
     * @return: a string
     */
    public String largestLetter(String s) {
        // write your code here
        if(s.length()==0||s.length()==1||s==null) return "NO";
        char max='A';
        int j,index=0;
        int flag=0;
        for(j=0;j<s.length()-1;j++){
            if((s.charAt(j)<='z'&&s.charAt(j)>='a'&&s.charAt(j+1)>='A'&&s.charAt(j+1)<='Z')||(s.charAt(j+1)<='z'&&s.charAt(j+1)>='a'&&s.charAt(j)>='A'&&s.charAt(j)<='Z'))
                break;
        }
        if(j==s.length()-1) return "NO";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>='A'&&s.charAt(i)<='Z'){
                if(max<s.charAt(i)){
                    max=s.charAt(i);
                    index=i;
                    flag=1;
                }
            }   
        }
        String ans=""+s.charAt(index);
        if(flag==0) return "NO";
        return ans;
    }
}
```