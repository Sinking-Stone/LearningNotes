# <center> 407 · 加一 

## 描述

给定一个非负数，表示一个数字数组，在该数的基础上+1，返回一个新的数组。

该数字按照数位高低进行排列，最高位的数在列表的最前面。

## 样例

### 样例 1

#### 输入

```txt
[1,2,3]
```

#### 输出

```txt
[1,2,4]
```

### 样例 2

#### 输入

```txt
[9,9,9]
```

#### 输出

```txt
[1,0,0,0]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        int one=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]=digits[i]+one;
            one=digits[i]/10;
            digits[i]%=10;
            if(one==0) break;
        }
        if(one==0) return digits;
        vector<int> ans;
        ans.push_back(1);
        for(int i=0;i<digits.size();i++) ans.push_back(digits[i]);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    public int[] plusOne(int[] digits) {
        // write your code here
        int one=1;
        for(int i=digits.length-1;i>=0;i--){
            digits[i]=digits[i]+one;
            one=digits[i]/10;
            digits[i]%=10;
            if(one==0) break;
        }
        if(one==0) return digits;
        int[] ans=new int[digits.length+1];
        ans[0]=1;
        return ans;
    }
}
```