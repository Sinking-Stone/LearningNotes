# <center> 214 · 数组的最大值

## 描述

给一个浮点数数组，求数组中的最大值。

## 样例

### 样例 1

#### 输入

```txt
[1.0, 2.1, -3.3]
```

#### 输出

```txt
2.1	
```

#### 样例解释

返回最大的数字

### 样例 2

#### 输入

```txt
[1.0, 1.0, -3.3]
```

#### 输出

```txt
1.0	
```

#### 样例解释

返回最大的数字。

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param A: An integer
     * @return: a float number
     */
    float maxOfArray(vector<float> &A) {
        // write your code here
        double max=-INT_MAX;
        for(int i=0;i<A.size();i++){
            if(max<A[i]) max=A[i];
        }
        return max;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param A: An integer
     * @return: a float number
     */
    public float maxOfArray(float[] A) {
        // write your code here
        float max=-Float.POSITIVE_INFINITY;
        for(int i=0;i<A.length;i++){
            if(max<A[i]) max=A[i];
        }
        return max;
    }
}
```