# <center> 492 · 队列维护

## 描述

按链表实现队列。支持以下基本方法：

1. enqueue(item).将新元素放入队列中。
2. dequeue(). 将第一个元素移出队列，返回它。


## 样例

### 样例 1

#### 输入

```txt
enqueue(1)
enqueue(2)
enqueue(3)
dequeue() // return 1
enqueue(4)
dequeue() // return 2
```

#### 输出

```txt
[1, 2]
```

### 样例 2

#### 输入

```txt
enqueue(10)
dequeue()// return 10
```

#### 输出

```txt
[10]
```

## 我的代码

### C++语言

```c++
class MyQueue {
public:
    /*
     * @param item: An integer
     * @return: nothing
     */
    int q[100010] = {0}, h = 0, t = -1;
    void enqueue(int item) {
        // write your code here
        q[++t]=item;
    }

    /*
     * @return: An integer
     */
    int dequeue() {
        // write your code here
        return q[h++];
    }
};
```

### Java语言

```java
public class MyQueue {
    /*
     * @param item: An integer
     * @return: nothing
     */
    List<Integer> ans=new ArrayList<>();
    public void enqueue(int item) {
        // write your code here
        ans.add(item);
    }

    /*
     * @return: An integer
     */
    public int dequeue() {
        // write your code here
        return ans.remove(0);
    }
}
```