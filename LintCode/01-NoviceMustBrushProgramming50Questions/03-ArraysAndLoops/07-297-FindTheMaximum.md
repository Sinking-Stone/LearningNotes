# <center> 297 · 寻找最大值

## 描述

寻找 n 个数中的最大值。

> 保证列表里的所有数字都在 int 范围内。

## 样例

### 样例 1

#### 输入

```txt
[1, 2, 3, 4, 5]
```

#### 输出

```txt
5
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param nums: the list of numbers
     * @return: return the maximum number.
     */
    int maxNum(vector<int> &nums) {
        // write your code here
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(ans<nums[i]) ans=nums[i];
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param nums: the list of numbers
     * @return: return the maximum number.
     */
    public int maxNum(List<Integer> nums) {
        // write your code here
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(ans<nums.get(i)) ans=nums.get(i);
        }
        return ans;
    }
}
```