# <center> 263 · 小括号匹配

## 描述

给定一个字符串所表示的括号序列，包含以下字符： '(', ')'， 判定是否是有效的括号序列。

括号必须依照 "()" 顺序表示， "()" 是有效的括号，但 ")(" 则是无效的括号。

## 样例

### 样例 1

#### 输入

```txt
")("
```

#### 输出

```txt
False
```

### 样例 2

#### 输入

```txt
"()"
```

#### 输出

```txt
True
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param string: A string
     * @return: whether the string is a valid parentheses
     */
    bool matchParentheses(string &string) {
        // write your code here
        vector<char> ans;
        for(int i=0;i<string.length();i++){
            if(string[i]==')'&&(int)(ans.size()-1)>=0&&ans[ans.size()-1]=='(') 
            	ans.pop_back();
            else 
            	ans.push_back(string[i]);
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
     * @param string: A string
     * @return: whether the string is a valid parentheses
     */
    public boolean matchParentheses(String string) {
        // write your code here
        List<Character> ans=new ArrayList<>();
        for(int i=0;i<string.length();i++){
            if(string.charAt(i)==')'&&ans.size()-1>=0&&ans.get(ans.size()-1)=='(') 
            	ans.remove(ans.size()-1);
            else 
            	ans.add(string.charAt(i));
        }
        if(ans.size()!=0) return false;
        return true;
    }
}
```