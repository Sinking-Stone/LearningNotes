# <center> 133 · 最长单词

## 描述

给一个词典，找出其中所有最长的单词。

## 样例

### 样例 1

#### 输入

```txt
 {
    "dog",
    "google",
    "facebook",
    "internationalization",
    "blabla"
}
```

#### 输出

```txt
["internationalization"]
```

### 样例 2

#### 输入

```txt
{
    "like",
    "love",
    "hate",
    "yes"		
}
```

#### 输出

```txt
["like", "love", "hate"]
```

## 挑战

遍历两次的办法很容易想到，如果只遍历一次你有没有什么好办法？

## 我的代码

### C++语言

```c++
class Solution {
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ans;
        int max=0;
        for(int i=0;i<dictionary.size();i++){
            int len=dictionary[i].size();
            if(max<len) {
            	max=len;
            }
        }
        for(int i=0;i<dictionary.size();i++)
        	if(dictionary[i].size()==max)
        		ans.push_back(dictionary[i]);
        return ans;
    }
};
```

### Java语言

```java
public class Solution {
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    public List<String> longestWords(String[] dictionary) {
        // write your code here
        List<String> ans=new ArrayList<>();
        int max=0;
        for(int i=0;i<dictionary.length;i++){
            int len=dictionary[i].length();
            if(max<len) {
            	max=len;
            }
        }
        for(int i=0;i<dictionary.length;i++)
        	if(dictionary[i].length()==max)
        		ans.add(dictionary[i]);
        return ans;
    }
}
```