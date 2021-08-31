# <center> 67 · 二叉树的中序遍历

## 描述

给出一棵二叉树,返回其中序遍历。

## 样例

### 样例 1

#### 输入

```txt
二叉树 = {1,2,3}
```

#### 输出

```txt
[2,1,3]
```

#### 解释

```txt
    1
  /  \
 2    3

它将被序列化为{1,2,3}中序遍历
 ```

### 样例 2

#### 输入

```txt
二叉树 = {1,#,2,3}
```

#### 输出

```txt
[1,3,2]
```

#### 样例解释

```txt
    1
      \
        2
      /
    3

它将被序列化为{1,#,2,3}中序遍历
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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
     void helper(TreeNode * root,vector<int>& ans){
        if(root==nullptr) return;

        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
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
     * @return: Inorder in ArrayList which contains node values.
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        // write your code here
        List<Integer> ans=new ArrayList<>();
        if(root==null) return ans;

        ans.addAll(inorderTraversal(root.left));
        ans.add(root.val);
        ans.addAll(inorderTraversal(root.right));

        return ans;
    }
}
```