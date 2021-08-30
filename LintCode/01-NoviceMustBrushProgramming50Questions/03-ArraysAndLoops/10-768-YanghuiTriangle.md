# <center> 768 · 杨辉三角

## 描述

给一整数 n, 返回杨辉三角的前 n 行

> 0 <= n <= 20  
> 杨辉三角也被叫做帕斯卡三角形. --(Wikipedia)


## 样例

### 样例 1

#### 输入

```txt
n = 4
```

#### 输出

```txt
[
 [1]
 [1,1]
 [1,2,1]
 [1,3,3,1]
]
```

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: a Integer
     * @return: the first n-line Yang Hui's triangle
     */
    vector<vector<int>> calcYangHuisTriangle(int n) {
        // write your code here
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> line;
            for(int j=0;j<=i;j++){
                if(j==0||j==i) line.push_back(1);
                else line.push_back((ans[i-1][j]+ans[i-1][j-1]));
            }
            ans.push_back(line);
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: a Integer
     * @return: the first n-line Yang Hui's triangle
     */
    public List<List<Integer>> calcYangHuisTriangle(int n) {
        // write your code here
        List<List<Integer>> ans=new ArrayList<>();
        for(int i=0;i<n;i++){
            List<Integer> line=new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0||j==i) line.add(1);
                else line.add((ans.get(i-1).get(j)+ans.get(i-1).get(j-1)));
            }
            ans.add(line);
        }
        return ans;
    }
}
```