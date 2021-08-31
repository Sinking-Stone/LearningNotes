# <center> 1343 · 两字符串和

## 描述

给定两个仅含数字的字符串，你需要返回一个由各个位之和拼接的字符串。

> A 和 B 是由数字组成的字符串

## 样例

### 样例 1

#### 输入

```txt
A = "99"
B = "111"
```

#### 输出

```txt
"11010"
```

### 解释

因为 9 + 1 = 10, 9 + 1 = 10, 0 + 1 = 1,连接之后的结果是 "11010"。

### 样例 2

#### 输入

```txt
A = "2"
B = "321"
```

#### 输出

```txt
"323"
```

### 解释

因为 1 + 2 = 3, 2 + 0 = 2, 3 + 0 = 3,连接之后的结果。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    string SumofTwoStrings(string &A, string &B) {
        // write your code here
        string ans="";
        int Alen=A.size()-1,Blen=B.size()-1;
        while(Alen>=0) {
        	if(Blen==-1&&Alen>=0) {
        		ans=A[Alen]+ans;
        		Alen--;
        	}
        	else {
	        	int temp=(A[Alen]-'0')+(B[Blen]-'0');
	        	ans= to_string(temp)+ans;
	        	Alen--;
	        	Blen--;
        	}
        }
        if(Blen>=0) {
        	for(int i=Blen;i>=0;i--) ans=B[i]+ans;
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    public String SumofTwoStrings(String A, String B) {
        // write your code here
        String ans="";
        int Alen=A.length()-1,Blen=B.length()-1;
        while(Alen>=0) {
        	if(Blen==-1&&Alen>=0) {
        		ans=A.charAt(Alen)+ans;
        		Alen--;
        	}
        	else {
	        	int temp=(A.charAt(Alen)-'0')+(B.charAt(Blen)-'0');
	        	ans=temp+ans;
	        	Alen--;
	        	Blen--;
        	}
        }
        if(Blen>=0) {
        	for(int i=Blen;i>=0;i--) ans=B.charAt(i)+ans;
        }
        return ans;
    }
}
```