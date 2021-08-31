# <center> 68 · 二叉树的后序遍历

## 描述

给出一棵二叉树，返回其节点值的后序遍历。

> 首个数据为根节点，后面接着是其左儿子和右儿子节点值，"#"表示不存在该子节点。  
> 节点数量不超过20


## 样例

### 样例 1

#### 输入

```txt
二叉树 = {1,2,3}
```

#### 输出

```txt
[2,3,1]
```

#### 解释

```txt
    1
  /  \
 2    3

 它将被序列化为{1,2,3}之后进行后序遍历
 ```

### 样例 2

#### 输入

```txt
二叉树 = {1,#,2,3}
```

#### 输出

```txt
[3,2,1]
```

#### 样例解释

```txt
    1
      \
        2
      /
    3

它将被序列化为{1,#,2,3}之后进行后序遍历
```

## 挑战

你能使用非递归实现么？

## 我的代码

### C++语言

```c++
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    void helper(TreeNode * root,vector<int>& ans){
        if(root==nullptr) return;

        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->val);
    }
};
```

### Java语言

```java
/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

public class Solution {
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    public List<Integer> postorderTraversal(TreeNode root) {
        // write your code here
        List<Integer> ans=new ArrayList<>();
        if(root==null) return ans;

        ans.addAll(postorderTraversal(root.left));
        ans.addAll(postorderTraversal(root.right));
        ans.add(root.val);

        return ans;
    }
}
```