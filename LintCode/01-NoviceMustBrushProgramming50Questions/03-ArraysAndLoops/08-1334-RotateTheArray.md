# <center> 1334 · 旋转数组

## 描述

给定一个数组，将数组向右移动k步，其中k为非负数。

## 样例

### 样例 1

#### 输入

```txt
[1,2,3,4,5,6,7], k = 3
```

#### 输出

```txt
[5,6,7,1,2,3,4]
```

#### 样例解释

    向右旋转1步: [7,1,2,3,4,5,6]
    向右旋转2步: [6,7,1,2,3,4,5]
    向右旋转3步: [5,6,7,1,2,3,4]

### 样例 2

#### 输入

```txt
[-1,-100,3,99], k = 2
```

#### 输出

```txt
[3,99,-1,-100]
```

#### 样例解释

    向右旋转1步: [99,-1,-100,3]
    向右旋转2步: [3,99,-1,-100]

## 挑战

    给出尽可能多的解决办法, 至少有三种方法可以解决这个问题.
    能够用O(1)的时间复杂度解决问题吗?


## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    vector<int> rotate(vector<int> &nums, int k) {
        // Write your code here
        vector<int> ans;
        int len=nums.size();
        k=k%len;
        for(int i=0;i<k;i++)
            ans.push_back(nums[(len-k+i)]);
        for(int i=0;i<len-k;i++)
            ans.push_back(nums[i]);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    public int[] rotate(int[] nums, int k) {
        // Write your code here
        int len=nums.length;
        int[] ans=new int[len];
        k=k%len;
        for(int i=0;i<k;i++)
            ans[i]=nums[(len-k+i)];
        for(int i=0;i<len-k;i++)
            ans[i+k]=nums[i];
        return ans;
    }
}
```