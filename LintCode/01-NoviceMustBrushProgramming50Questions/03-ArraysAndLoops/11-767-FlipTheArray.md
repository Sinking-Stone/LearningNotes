# <center> 767 · 翻转数组

## 描述

原地翻转给出的数组 nums

> 原地意味着你不能使用额外空间

## 样例

### 样例 1

#### 输入

```txt
nums = [1,2,5]
```

#### 输出

```txt
[5,2,1]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param nums: a integer array
     * @return: nothing
     */
    void reverseArray(vector<int> &nums) {
        // write your code here
        for(int i=0,j=nums.size()-1;i<nums.size()/2;i++,j--){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param nums: a integer array
     * @return: nothing
     */
    public void reverseArray(int[] nums) {
        // write your code here
        for(int i=0,j=nums.length-1;i<nums.length/2;i++,j--){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
}
```