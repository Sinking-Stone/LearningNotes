# 第三章　使用GitHub的前期准备

## 3.1　使用前的准备

### 创建账户

&emsp;&emsp;首先要先创建一个 GitHub 账户。

### 设置头像

&emsp;&emsp;在 GitHub 上随处可见的头像（账户独有的标识）是通过 Gravatar服务显示的。

### 设置 SSH Key

&emsp;&emsp;GitHub 上连接已有仓库时的认证，是通过使用了 SSH 的公开密钥认证方式进行的。现在让我们来创建公开密钥认证所需的 SSH Key，并将其添加至 GitHub。
&emsp;&emsp;运行下面的命令创建 SSH Key ：

```shell
$ ssh-keygen -t rsa -C "your_email@example.com"
Generating public/private rsa key pair.
Enter file in which to save the key
(/Users/your_user_directory/.ssh/id_rsa): 按回车键
Enter passphrase (empty for no passphrase): 输入密码
Enter same passphrase again: 再次输入密码
```

id_rsa 文件是私有密钥，id_rsa.pub 是公开密钥。

### 添加公开密钥

&emsp;&emsp;在 GitHub 中添加公开密钥，今后就可以用私有密钥进行认证了。
&emsp;&emsp;点击右上角的账户设定按钮（Account Settings），选择 SSH Keys 菜单之后，点击 Add SSH Key，会出现 Title 和 Key 两个输入框。在 Title 中输入适当的密钥名称。 Key 部分请粘贴 id_rsa.pub 文件里的内容。
&emsp;&emsp;id_rsa.pub 的内容可以用如下方法查看：

```shell
cat ~/.ssh/id_rsa.pub
```

&emsp;&emsp;添加成功之后，创建账户时所用的邮箱会接到一封提示“公共密钥添加完成”的邮件。
&emsp;&emsp;完成以上设置后，就可以用手中的私人密钥与 GitHub 进行认证和通信了。

```shell
$ ssh -T git@github.com
The authenticity of host 'github.com (207.97.227.239)' can't be established.
RSA key fingerprint is fingerprint值 .
Are you sure you want to continue connecting (yes/no)? 输入yes

出现如下结果即为成功。
Hi hirocastest! You've successfully authenticated, but GitHub does not provide shell access.
```

### 使用社区功能

&emsp;&emsp;创建账户后不妨试试 Follow（关注）别人。您所 Follow 的用户的活动就会显示在您的控制面板页面中。您可以通过这种方法知道那个人在 GitHub 上都做了些什么。

## 3.2　实际动手使用

&emsp;&emsp;实际创建一个公开的仓库。点击右上角工具栏里的 New repository图标，创建新的仓库。
&emsp;&emsp;仓库的各项内容根据实际需要填写。

### 连接仓库

地址是：`https://github.com/用户名/仓库名`

#### README.md文件

&emsp;&emsp;在初始化时已经生成好了。README . md 文件的内容会自动显示在仓库的首页当中。因此，人们一般会在这个文件中标明本仓库所包含的软件的概要、使用流程、许可协议等信息。如果使用 Markdown 语法进行描述，还可以添加标记，提高可读性。

#### GitHub Flavored Markdown

&emsp;&emsp;在 GitHub 上进行交流时用到的 Issue、评论、Wiki，都可以用 Markdown 语法表述，从而进行标记。准确地说应该是 GitHub Flavored Markdown（GFM）语法。该语法虽然是 GitHub 在 Markdown 语法基础上扩充而来的，但一般情况下只要按照原本的 Markdown 语法进行描述就可以。

#### 公开代码

##### clone 已有仓库

```shell
$ git clone git@github.com:hirocastest/Hello-World.git
Cloning into 'Hello-World'...
remote: Counting objects: 3, done.
remote: Total 3 (delta 0), reused 0 (delta 0)
Receiving objects: 100% (3/3), done.

$ cd Hello-World
```

&emsp;&emsp;这里会要求输入 GitHub 上设置的公开密钥的密码。认证成功后，仓库便会被 clone 至仓库名后的目录中。将想要公开的代码提交至这个仓库再 push 到 GitHub 的仓库中，代码便会被公开。

##### 编写代码

&emsp;&emsp;这里我们编写一个 hello_world.php 文件，用来输出“Hello World!”。

```php
hello_world.php的内容
<?php
    echo "Hello World!";
?>
```

&emsp;&emsp;由于 hello_word.php 还没有添加至 Git 仓库，所以显示为 Untracked files。

```shell
$ git status
# On branch master
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#       hello_world.php
nothing added to commit but untracked files present (use "git add" to track)
```

##### 提交

&emsp;&emsp;将 hello_word.php 提交至仓库。这样一来，这个文件就进入了版本管理系统的管理之下。今后的更改管理都交由 Git 进行。

```shell
git add hello_world.php
$ git commit -m "Add hello world script by php"
[master d23b909] Add hello world script by php
 1 file changed, 3 insertions(+)
 create mode 100644 hello_world.php
```

&emsp;&emsp;通过 git add命令将文件加入暂存区，再通过 git commit命令提交。添加成功后，可以通过 git log命令查看提交日志。

```shell
$ git log
commit d23b909caad5d49a281480e6683ce3855087a5da
Author: hirocastest <hohtsuka@gmail.com>
Date:   Tue May 1 14:36:58 2012 +0900
        　
    Add hello world script by php
```

##### 进行 push

之后只要执行 push，GitHub 上的仓库就会被更新。

```shell
$ git push
Counting objects: 4, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 328 bytes, done.
Total 3 (delta 0), reused 0 (delta 0)
To git@github.com:hirocastest/Hello-World.git
   46ff713..d23b909 master -> master
```

## 3.3　小结

&emsp;&emsp;本章讲解了初次在 GitHub 建立仓库以及公开代码的流程。完成这些，就踏入了 GitHub 的世界。
