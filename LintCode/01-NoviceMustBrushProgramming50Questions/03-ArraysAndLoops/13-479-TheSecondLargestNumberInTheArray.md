# <center> 479 · 数组第二大数

## 描述

在数组中找到第二大的数。

> 你可以假定至少有两个数字。  
> 第二大的数是指降序数组中第二个数字。

## 样例

### 样例 1

#### 输入

```txt
[1,3,2,4]
```

#### 输出

```txt
3
```

### 样例 2

#### 输入

```txt
[1,1,2,2]
```

#### 输出

```txt
2
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The second max number in the array.
     */

    int secondMax(vector<int> &nums) {
        // write your code here
       int max1=-INT_MAX,max2=-INT_MAX,flag=0;
    for(int i=0;i<nums.size();i++){
        if(max1<nums[i]) {
            max1=nums[i];
            flag=i;
        }
    }
    nums.erase(nums.begin()+flag);
    for(int i=0;i<nums.size();i++){
        if(max2<nums[i]) max2=nums[i];
    }
    return max2;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param nums: An integer array
     * @return: The second max number in the array.
     */
    public int secondMax(int[] nums) {
        // write your code here
        Arrays.sort(nums);
        return nums[nums.length-2];
    }
}
```