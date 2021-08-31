# <center> 50 · 数组剔除元素后的乘积

## 描述

给定一个整数数组A。  
定义B[i]=A[0]∗...∗A[i−1]∗A[i+1]∗...∗A[n−1]B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]B[i]=A[0]∗...∗A[i−1]∗A[i+1]∗...∗A[n−1]  
 计算B的时候请不要使用除法。请输出B。

## 样例

### 样例 1

#### 输入

```txt
A = [1,2,3]
```

#### 输出

```txt
[6,3,2]
```

#### 解释

B[0] = A[1] * A[2] = 6; B[1] = A[0] * A[2] = 3; B[2] = A[0] * A[1] = 2

### 样例 2

#### 输入

```txt
A = [2,4,6]
```

#### 输出

```txt
[24,12,8]
```

#### 解释

B[0] = A[1] * A[2] = 24; B[1] = A[0] * A[2] = 12; B[2] = A[0] * A[1] = 8

## 我的代码

### C++语言

```c++
class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(1L);
            for(int j=0;j<nums.size();j++){
                if(i!=j) ans[i]=ans[i]*nums[j];
            }
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    public List<Long> productExcludeItself(List<Integer> nums) {
        // write your code here
        List<Long> ans=new ArrayList<>();
        for(int i=0;i<nums.size();i++){
            ans.add(1L);
            for(int j=0;j<nums.size();j++) 
                if (i != j) ans.set(i, ans.get(i) * nums.get(j));
        }
        return ans;
    }
}
```