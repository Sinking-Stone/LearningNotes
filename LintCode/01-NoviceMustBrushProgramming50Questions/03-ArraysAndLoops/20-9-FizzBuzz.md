# <center> 9 · Fizz Buzz 问题 

## 描述

给定整数 n ，按照如下规则打印从 1 到 n 的每个数：

+ 如果这个数被3整除，打印fizz。
+ 如果这个数被5整除，打印buzz。
+ 如果这个数能同时被3和5整除，打印fizz buzz。
+ 如果这个数既不能被 3 整除也不能被 5 整除，打印数字本身。

## 样例

### 样例 1

#### 输入

```txt
n = 15
```

#### 输出

```txt
[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz", "11", "fizz",
  "13", "14", "fizz buzz"
]
```

## 挑战

你是否可以只用一个 if 来实现？

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        // write your code here
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i%3==0&&i%5==0) ans.push_back("fizz buzz");
            else if(i%3==0&&i%5!=0) ans.push_back("fizz");
            else if(i%5==0&&i%3!=0) ans.push_back("buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    public List<String> fizzBuzz(int n) {
        // write your code here
        List<String> ans=new ArrayList<>();
        for(int i=1;i<=n;i++){
            if(i%3==0&&i%5==0) ans.add("fizz buzz");
            else if(i%3==0&&i%5!=0) ans.add("fizz");
            else if(i%5==0&&i%3!=0) ans.add("buzz");
            else ans.add(i+"");
        }
        return ans;
    }
}
```