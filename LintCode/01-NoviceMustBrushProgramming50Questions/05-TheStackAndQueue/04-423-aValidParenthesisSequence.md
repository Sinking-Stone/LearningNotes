# <center> 423 · 有效的括号序列

## 描述

给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'， 判定是否是有效的括号序列。

括号必须依照 "()" 顺序表示， "()[]{}" 是有效的括号，但 "([)]" 则是无效的括号。

## 样例

### 样例 1

#### 输入

```txt
"([)]"
```

#### 输出

```txt
False
```

### 样例 2

#### 输入

```txt
"()[]{}"
```

#### 输出

```txt
True
```

## 挑战

O(n)的时间，n 为括号的个数。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        if(s.size()==1) return false;
        if(s.size()==0) return true;
        vector<char> ans;
        for(int i=0;i<s.size();i++){
            if (s[i] == ')' && (int)(ans.size() - 1) >= 0 && ans[ans.size() - 1] == '(')
                ans.pop_back();
            else if (s[i] == ']' && (int)(ans.size() - 1) >= 0 && ans[ans.size() - 1] == '[')
                ans.pop_back();
            else if (s[i] == '}' && (int)(ans.size() - 1) >= 0 && ans[ans.size() - 1] == '{')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        if(ans.size()!=0) return false;
        return true;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    public boolean isValidParentheses(String s) {
        // write your code here
        if(s.length()==1) return false;
        if(s.length()==0) return true;
        List<Character> ans=new ArrayList<>();
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')'&&ans.size()-1>=0&&ans.get(ans.size()-1)=='(') 
            	ans.remove(ans.size()-1);
            else if(s.charAt(i)==']'&&ans.size()-1>=0&&ans.get(ans.size()-1)=='[') 
            	ans.remove(ans.size()-1);
            else if(s.charAt(i)=='}'&&ans.size()-1>=0&&ans.get(ans.size()-1)=='{') 
            	ans.remove(ans.size()-1);
            else 
            	ans.add(s.charAt(i));
        }
        if(ans.size()!=0) return false;
        return true;
    }
}
```