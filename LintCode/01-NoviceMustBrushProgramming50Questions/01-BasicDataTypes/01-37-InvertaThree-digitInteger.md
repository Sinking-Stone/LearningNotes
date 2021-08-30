# <center> 37 · 反转一个三位整数

## 描述

反转一个只有3位数的整数。

> 你可以假设输入一定是一个只有三位数的整数，这个整数大于等于100，小于1000。

## 样例

### 样例 1

#### 输入

```txt
number = 123
```

#### 输出

```txt
321
```
#### 解释

反转数字。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        // write your code here
        int ans,a[3];
        a[0]=number/100;
        a[1]=number/10%10;
        a[2]=number%10;
        if(a[0]==0){
            if(a[1]==0) ans=a[2];
            else ans=a[2]*10+a[1];
        }
        ans=a[2]*100+a[1]*10+a[0];
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    public int reverseInteger(int number) {
        // write your code here
        int ans;
        int[] a=new int[3];
        a[0]=number/100;
        a[1]=number/10%10;
        a[2]=number%10;
        if(a[0]==0){
            if(a[1]==0) ans=a[2];
            else ans=a[2]*10+a[1];
        }
        ans=a[2]*100+a[1]*10+a[0];
        return ans;
    }
}
```