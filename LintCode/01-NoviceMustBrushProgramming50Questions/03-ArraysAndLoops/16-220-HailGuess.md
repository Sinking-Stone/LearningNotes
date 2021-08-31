# <center> 220 · 冰雹猜想 

## 描述

数学家们曾提出一个著名的猜想——冰雹猜想。
对于任意一个自然数N，如果N是偶数，就把它变成N / 2；
如果N是奇数，就把它变成 3 * N+1。
按照这个法则运算下去，最终必然得1。
试问，该数通过几轮变换，会变成1呢？

> 1<=n<=1000

## 样例

### 样例 1

#### 输入

```txt
4
```

#### 输出

```txt
2
```

#### 解释

第一轮：4/2=2  
第二轮：2/2=1  
答案为2

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param num: an integer
     * @return: return an integer
     */
    int getAnswer(int num) {
        // write your code here.
        int ans=0;
        while(num!=1){
            if(num%2==0){
                num/=2;
                ans++;
            }
            else {
                num=3*num+1;
                ans++;
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
     * @param num: an integer
     * @return: return an integer
     */
    public int getAnswer(int num) {
        // write your code here.
        int ans=0;
        while(num!=1){
            if(num%2==0){
                num/=2;
                ans++;
            }
            else {
                num=3*num+1;
                ans++;
            }
        }
        return ans;
    }
}
```