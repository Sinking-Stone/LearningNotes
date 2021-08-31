# <center> 491 · 回文数

## 描述

判断一个正整数是不是回文数。

回文数的定义是，将这个数反转之后，得到的数仍然是同一个数。

> 给的数一定保证是32位正整数，但是反转之后的数就未必了。


## 样例

### 样例 1

#### 输入

```txt
11
```

#### 输出

```txt
true
```

### 样例 2

#### 输入

```txt
1232
```

#### 输出

```txt
false
```

#### 解释

1232!=2321

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        int a[100];
        int i=0;
        while(num>0){
            a[i]=num%10;
            num/=10;
            i++;
        }
        for(int j=0,k=i-1;j<=i/2;j++,k--){
            if(a[j]!=a[k]) return false;
        }
        return true;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    public boolean isPalindrome(int num) {
        // write your code here
        int[] a=new int[100];
        int i=0;
        while(num>0){
            a[i]=num%10;
            num/=10;
            i++;
        }
        for(int j=0,k=i-1;j<=i/2;j++,k--){
            if(a[j]!=a[k]) return false;
        }
        return true;
    }
}
```