# <center> 1300 · 巴什博弈

## 描述

&emsp;&emsp;给定一个整数r代表一个圆的半径。
&emsp;&emsp;你的任务是返回一个数组。
&emsp;&emsp;其中数组的第一个元素代表圆的周长，数组的第二个元素代表圆的面积。

> PI = 3.14

## 样例

### 样例 1

#### 输入

```txt
r = 2 
```

#### 输出

```txt
[12.56, 12.56]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param r: a Integer represent radius
     * @return: the circle's circumference nums[0] and area nums[1]
     */
    vector<double> calculate(int r) {
        // write your code here
        vector<double> ans;
        ans.push_back(2*3.14*r);
        ans.push_back(r*3.14*r);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param r: a Integer represent radius
     * @return: the circle's circumference nums[0] and area nums[1]
     */
    public double[] calculate(int r) {
        // write your code here
        double[] ans=new double[2];
        ans[0]=2*3.14*r;
        ans[1]=r*3.14*r;
        return ans;
    }
}
```