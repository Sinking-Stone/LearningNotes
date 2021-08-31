# <center> 146 · 大小写转换 II 

## 描述

对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。

> 在面试中我是否需要实现KMP算法？  
> 不需要，当这种问题出现在面试中时，面试官很可能只是想要测试一下你的基础应用能力。当然你需要先跟面试官确认清楚要怎么实现这个题。

## 样例

### 样例 1

#### 输入

```txt
source = "source"
target = "target"
```

#### 输出

```txt
-1   
```

#### 解释

如果source里包含target的内容，返回target在source里第一次出现的位置

## 挑战

可用O(nm)算法，如果能用O(n)算法做出来就更好。（提示：KMP）

## 我的代码

### C++语言

```c++
class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        if(target.size()==0) return 0;
        int j,ans=-1,len=target.size();
        for(int i=0;i<source.size();i++){
            if(target[0]==source[i]){
                if(len==1) return i;
                for(j=1;j<len;j++) {
                    if(target[j]!=source[i+j])
                        break;
                }
                if(j==len) return i;
            }
        }
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    public int strStr(String source, String target) {
        // Write your code here
        if(target.length()==0) return 0;
        int j,ans=-1,len=target.length();
        for(int i=0;i<source.length();i++){
            if(target.charAt(0)==source.charAt(i)){
                if(len==1) return i;
                for(j=1;j<len;j++) {
                    if(i+j<source.length()&&target.charAt(j)!=source.charAt(i+j))
                        break;
                    if(i+j>=source.length()) return ans;
                }
                if(j==len) return i;
            }
        }
        return ans;
    }
}
```