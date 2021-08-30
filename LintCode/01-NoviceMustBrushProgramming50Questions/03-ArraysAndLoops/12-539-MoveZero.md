# <center> 539 · 移动零

## 描述

给一个数组 nums 写一个函数将 0 移动到数组的最后面，非零元素保持原数组的顺序

> 1.必须在原数组上操作  
> 2.最小化操作数

## 样例

### 样例 1

#### 输入

```txt
nums = [0, 1, 0, 3, 12]
```

#### 输出

```txt
[1, 3, 12, 0, 0]
```

### 样例 2

#### 输入

```txt
nums = [0, 0, 0, 3, 1]
```

#### 输出

```txt
[3, 1, 0, 0, 0]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        vector<int> ans;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
                j++;
            }
        }
        for(int i=0;i<nums.size()-j;i++){
            ans.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[i];
        }
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    public void moveZeroes(int[] nums) {
        // write your code here
        int[] ans=new int[nums.length];
        int j=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                ans[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<nums.length-j;i++){
            ans[j+i]=0;
        }
        for(int i=0;i<nums.length;i++){
            nums[i]=ans[i];
        }
    }
}
```