# <center> 46 · 主元素 

## 描述

给定一个整型数组，找出主元素，它在数组中的出现次数大于数组元素个数的二分之一。

> 假设数组非空，且数组中总是存在主元素。

## 样例

### 样例 1

#### 输入

```txt
数组 = [1, 1, 1, 1, 2, 2, 2]
```

#### 输出

```txt
1
```

#### 解释

数组中1的个数大于数组元素的二分之一。

### 样例 2

#### 输入

```txt
数组 = [1, 1, 1, 2, 2, 2, 2]
```

#### 输出

```txt
2
```

#### 解释

数组中2的个数大于数组元素的二分之一。

## 挑战

要求时间复杂度为O(n)，空间复杂度为O(1)

## 我的代码

### C++语言

```c++
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */

    int majorityNumber(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
};
```

### Java语言

```java
public class Solution {
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(List<Integer> nums) {
        // write your code here
        // Map<Integer, Integer> maps = new HashMap<>();
        // for(int i=0;i<nums.size();i++){
        //     maps.put(nums.get(i), );
        // }
        Collections.sort(nums);
        return nums.get(nums.size()/2);
    }
}
```