# <center> 485 · 生成给定大小的数组

## 描述

给你一个大小size,生成一个元素从1 到 size的数组

## 样例

### 样例 1

#### 输入

```txt
size = 4
```

#### 输出

```txt
[1, 2, 3, 4]
```

#### 样例解释

返回一个顺序填充1到4的数组。

### 样例 2

#### 输入

```txt
size = 1
```

#### 输出

```txt
[1]
```

#### 样例解释

返回一个顺序填充1到1的数组

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param size: An integer
     * @return: An integer list
     */
    vector<int> generate(int size) {
        // write your code here
        vector<int> a;
        for(int i=1;i<=size;i++){
            a.push_back(i);
        }
        return a;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param size: An integer
     * @return: An integer list
     */
    public List<Integer> generate(int size) {
        // write your code here
        List<Integer> a=new ArrayList<>();
        for(int i=1;i<=size;i++){
            a.add(i);
        }
        return a;
    }
}
```