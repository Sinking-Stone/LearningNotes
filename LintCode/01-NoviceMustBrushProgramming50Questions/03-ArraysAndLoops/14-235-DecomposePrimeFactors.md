# <center> 235 · 分解质因数

## 描述

将一个整数分解为若干质因数之乘积。

> 你需要从小到大排列质因子。

## 样例

### 样例 1

#### 输入

```txt
10
```

#### 输出

```txt
[2, 5]
```

### 样例 2

#### 输入

```txt
660
```

#### 输出

```txt
[2, 2, 3, 5, 11]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        // write your code here
        vector<int> ans;
        for(int i=2;i<=sqrt(num);i++){
            while(num%i==0){
                ans.push_back(i);
                num/=i;
            }
        }
        if(num!=1)
            ans.push_back(num);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param num: An integer
     * @return: an integer array
     */

    public List<Integer> primeFactorization(int num) {
        // write your code here
        List<Integer> ans=new ArrayList<>();
        for(int i=2;i<=Math.sqrt(num);i++){
            while(num%i==0){
                ans.add(i);
                num/=i;
            }
        }
        if(num!=1)
            ans.add(num);
        return ans;
    }
}
```