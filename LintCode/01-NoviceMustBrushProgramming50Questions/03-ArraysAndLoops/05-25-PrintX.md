# <center> 25 · 打印X

## 描述

输入一个正整数N， 你需要按样例的方式返回一个字符串列表。

> 1≤n≤15

## 样例

### 样例 1

#### 输入

```txt
n = 1
```

#### 输出

```txt
["X"]
```

#### 样例解释

答案列表可以被视为下面的图形

```txt
X
```

### 样例 2

#### 输入

```txt
n = 2
```

#### 输出

```txt
["XX", "XX"]
```

#### 样例解释

答案列表可以被视为下面的图形

```txt
XX
XX
```

### 样例 3

#### 输入

```txt
n = 3
```

#### 输出

```txt
["X X", " X ", "X X"]
```

#### 样例解释

答案列表可以被视为下面的图形

```txt
X X
 X
X X
```

### 样例 4

#### 输入

```txt
n = 4
```

#### 输出

```txt
["X  X", " XX ", " XX ", "X  X"]
```

#### 样例解释

答案列表可以被视为下面的图形

```txt
X  X 
 XX  
 XX 
X  X
```

### 样例 5

#### 输入

```txt
n = 5
```

#### 输出

```txt
["X   X", " X X ", "  X  ", " X X ", "X   X"]
```

#### 样例解释

答案列表可以被视为下面的图形

```txt
X   X 
 X X  
  X   
 X X  
X   X 
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: An integer.
     * @return: A string list.
     */
    vector<string> printX(int n) {
        // write your code here
        vector<string> ans;
        for(int i=0;i<n;i++){
            string line="";
            for(int j=0;j<n;j++){
                if((i==j)||(j==n-i-1)) line+="X";
                else line+=" ";
            }
            ans.push_back(line);
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: An integer.
     * @return: A string list.
     */
    public List<String> printX(int n) {
        // write your code here
        List<String> ans=new ArrayList<>();
        for(int i=0;i<n;i++){
            StringBuffer line=new StringBuffer();
            for(int j=0;j<n;j++){
                if((i==j)||(j==n-i-1)) line.append("X");
                else line.append(" ");
            }
            ans.add(new String(line));
        }
        return ans;
    }
}
```