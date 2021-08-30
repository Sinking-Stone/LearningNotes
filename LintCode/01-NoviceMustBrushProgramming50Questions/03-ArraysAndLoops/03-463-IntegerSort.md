# <center> 463 · 整数排序

## 描述

给一组整数，按照升序排序，使用选择排序，冒泡排序，插入排序或者任何 O(n2) 的排序算法。

## 样例

### 样例 1

#### 输入

```txt
[3, 2, 1, 4, 5]
```

#### 输出

```txt
[1, 2, 3, 4, 5]
```

### 样例解释

返回排序后的数组。


### 样例 2

#### 输入

```txt
[1, 1, 2, 1, 1]
```

#### 输出

```txt
[1, 1, 1, 1, 2]
```

### 样例解释

返回排好序的数组。


## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for(int i=1;i<A.size();i++){
            for(int j=0;j<A.size()-i;j++){
                if(A[j]>A[j+1]){
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param A: an integer array
     * @return: nothing
     */
    public void sortIntegers(int[] A) {
        // write your code here
        for(int i=0;i<A.length-1;i++){
            for(int j=0;j<A.length-i-1;j++){
                if(A[j]>A[j+1]){
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
    }
}
```