# 第四章　通过实际操作学习Git

## 4.1　基本操作

### git init——初始化仓库

&emsp;&emsp;要使用 Git 进行版本管理，必须先初始化仓库。Git 是使用 git init命令进行初始化的。请实际建立一个目录并初始化仓库。

```shell
$ mkdir git-tutorial
$ cd git-tutorial
$ git init
Initialized empty Git repository in /Users/hirocaster/github/github-book
/git-tutorial/.git/
```

&emsp;&emsp;如果初始化成功，执行了 git init命令的目录下就会生成 .git 目录。这个 .git 目录里存储着管理当前目录内容所需的仓库数据。
&emsp;&emsp;在 Git 中，我们将这个目录的内容称为“附属于该仓库的工作树”。文件的编辑等操作在工作树中进行，然后记录到仓库中，以此管理文件的历史快照。如果想将文件恢复到原先的状态，可以从仓库中调取之前的快照，在工作树中打开。开发者可以通过这种方式获取以往的文件。

### git status——查看仓库的状态

&emsp;&emsp;git status命令用于显示 Git 仓库的状态。这是一个十分常用的命令，请务必牢记。
&emsp;&emsp;工作树和仓库在被操作的过程中，状态会不断发生变化。

```shell
$ git status
# On branch master
#
# Initial commit
#
nothing to commit (create/copy files and use "git add" to track)
```





