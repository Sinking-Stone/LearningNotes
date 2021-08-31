# <center> 771 · 二阶阶乘

## 描述

实现一个栈，可以使用除了栈之外的数据结构

## 样例

### 样例 1

#### 输入

```txt
push(1)
pop()
push(2)
top()  // return 2
pop()
isEmpty() // return true
push(3)
isEmpty() // return false
```

#### 输出

```txt
[2, true, false]
```

### 样例 2

#### 输入

```txt
isEmpty()
```

#### 输出

```txt
[true]
```

## 我的代码

### C++语言

```c++
class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    
    vector<int> ans;
    void push(int x) {
        // write your code here
        ans.push_back(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        ans.pop_back();
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if(!this->isEmpty())
            return ans[ans.size()-1];
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        return ans.size()==0;
    }
};
```

### Java语言

```java
public class Stack {
    /*
     * @param x: An integer
     * @return: nothing
     */
    List<Integer> ans=new ArrayList<>();
    public void push(int x) {
        // write your code here
        ans.add(x);
    }

    /*
     * @return: nothing
     */
    public void pop() {
        // write your code here
        ans.remove(ans.size()-1);
    }

    /*
     * @return: An integer
     */
    public int top() {
        // write your code here
            return ans.get(ans.size()-1);
    }

    /*
     * @return: True if the stack is empty
     */
    public boolean isEmpty() {
        // write your code here
        return ans.size()==0;
    }
}
```