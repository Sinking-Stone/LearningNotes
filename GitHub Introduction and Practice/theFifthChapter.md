# 第五章　详细解说GitHub的功能

&emsp;&emsp;GitHub 为实现社会化编程提供了诸多功能。

## 5.1　键盘快捷键

&emsp;&emsp;在 GitHub 中，很多页面都可以使用键盘快捷键。熟悉键盘操作，能够让 GitHub 变得更加便捷。在各个页面按下 `shift ＋ /` 都可以打开键盘快捷键一览表，查看当前页面的快捷键。

## 5.2　工具栏

### 关于 UI

&emsp;&emsp;工具栏常驻于各个页面的上端。

#### 1 LOGO

&emsp;&emsp;点击 GitHub 的 LOGO 就会进入控制面板。

#### 2 Notifications

&emsp;&emsp;这一图标用于提示用户是否有新的通知。当图标为蓝色时表示有未读通知。用户在新建 Issue、被评论、进行 Pull Request 等时都会收到通知。另外，按照默认设置，用户在 GitHub 收到的通知会同时发送到该用户的注册邮箱。邮箱接收通知的相关设置在 Account settings 中进行。

> 设置通知：<https://github.com/settings/notifications>

#### 3 搜索窗口

&emsp;&emsp;在这里输入想找的用户或代码片段，就可以搜索到与之相关的信息。

#### 4 Explore

&emsp;&emsp;从各个角度介绍 GitHub 上的热门软件。

+ GitHub 公司特别介绍的软件（附开发者制作的视频）。
+ 按语言筛选本日 / 周 / 月的热门仓库 / 开发者。

> 热门仓库：<https://github.com/trending>

&emsp;&emsp;在这里有机会了解到最尖端的技术和软件。作为一名程序员，可以在上面找到许多灵感。

#### 5 Gist

&emsp;&emsp;Gist 功能主要用于管理及发布一些没必要保存在仓库中的代码，比如小的代码片段等。系统会自动管理更新历史，并且提供了 Fork 功能。另外，通过 Gist 还可以很方便地为同事编写代码示例。在 Gist 上添加的代码示例可以嵌入博客中。当然，如果选择了语言，还会自动添加语法高亮。

#### 6 Blog

&emsp;&emsp;这是到 GitHub 公司官方博客的超链接，GitHub 公司会在上面发布通知。新功能的通知、新入职员工的介绍、drinkup 聚会的信息等都会在上面定期发布。

#### 7 Help

&emsp;&emsp;GitHub 相关的帮助。虽然只有英文版，但用的都是比较简单的英文，遇到不懂的地方不妨在这里查一下。

#### 8 头像、用户名

&emsp;&emsp;点击后会显示用户的个人信息页面。

#### 9 Create a new ...

&emsp;&emsp;创建新的 Git 仓库或 Organization，向 Organization 添加成员、小组、仓库，为仓库添加 Issue 或 collaborator 等操作的菜单都聚集在这里。显示内容会根据当前页面不同而改变。

#### 10 Account settings

&emsp;&emsp;Account settings 的图标是一把螺丝刀和一柄锤子，点击它可以打开账户设置页面。在这里可以进行个人信息、安全管理、付费方案的设置，在使用 GitHub 时请务必浏览一遍。

#### 11 Sign out

&emsp;&emsp;点击这个按钮可以退出 GitHub。

> **注意：** 随着版本的更新，github上的界面也随之改变了很多，但是功能还是不变的，只是放在了不同的位置上。

## 5.3　控制面板

### 关于 UI

#### 1 News Feed

&emsp;&emsp;显示当前已 Follow 的用户和已 Watch 的项目的活动信息，用户可以在这里查看最新动向。将右上角 RSS 标志的 URL 添加到 RSS 阅读器中，还可以通过 RSS 查看。

#### 2 Pull Requests

&emsp;&emsp;显示用户已进行过的 Pull Request。通过这里，开发者可以很方便地追踪 Pull Request 的后续情况。

#### 3 Issues

&emsp;&emsp;在这里可以查看用户拥有权限的仓库或分配给自己的 Issue。当用户同时进行多个项目时，可以在这里一并查看 Issue。

#### 4 Stars

&emsp;&emsp;以列表的形式显示用户添加了 Star 的仓库。有些仓库需要经常查找，但又不必在 Watch 中频繁显示详细信息时，可以给这些仓库添加 Star，方便自己随时在这一栏中找到它们。

#### 5 Broadcast

&emsp;&emsp;主要用于接收 GitHub 公司发来的通知或使用技巧的小贴士。

#### 6 Repositories you contribute to

&emsp;&emsp;显示用户做过贡献的仓库。按贡献时间的先后顺序排列。

#### 7 Your Repositories

&emsp;&emsp;按更新时间顺序显示用户的仓库。标有钥匙图案的是非公开仓库，标有类似字母 Y 图案的是用户 Fork 过的仓库。

## 5.4　个人信息

访问 URL，就可以看到各位的个人信息：<https://github.com/用户名>

### 关于 UI

#### 1 用户信息

&emsp;&emsp;这里显示注册用户的基本信息，包括姓名、所属公司、邮箱地址、已加入的 Organization 等。如果对该用户感兴趣，可以点击页面右上角的 Follow 按钮（已经 Follow 的用户会显示 Unfollow）。这样一来，这个人在 GitHub 上的活动都会显示在您的 News Feed 中。

#### 2 Popular Repositories

&emsp;&emsp;显示公开仓库中受欢迎的、拥有大量 Star 的部分热门仓库。

#### 3 Repositories contributed to

&emsp;&emsp;按时间的先后顺序显示该用户做过贡献的部分仓库。该用户可能是这个仓库的软件开发者，也可能只是通过发送 Pull Request 等方式对该仓库做过某些贡献。

#### 4 Public contributions

&emsp;&emsp;一格表示一天，记录当日用户对拥有读取权限的仓库的大致贡献度。贡献度的衡量标准包括发送 Pull Request 的次数、写 Issue 的次数、进行提交的次数等。颜色越深代表贡献度越高。一名程序员绿色的天数越多，证明他对 GitHub 越熟悉。

#### 5 Contribution Activity

&emsp;&emsp;按时间顺序显示具体贡献活动的链接。

#### 6 Repositories

&emsp;&emsp;显示该用户公开的仓库。Fork 来的仓库也显示在这里。仓库名称、简要说明、使用的语言、最终更新日期都会出现在列表中。星形图案旁边的数字表示给这个仓库添加 Star 的人数，再旁边是被 Fork 数。背景显示的图标表示这个仓库的更新频率。横向为时间轴，右侧为最新时间。表中色块越高，该仓库的更新频率也就越高。背景显示的图标表示这个仓库的更新频率。横向为时间

#### 7 Public Activity

&emsp;&emsp;显示该用户的公开活动。活动就是指这个用户做了什么，比如向仓库进行提交或者 Pull Request 等，其大量的公开信息都会记录在这里。从这里可以了解到该用户平常都在 GitHub 上做些什么。比如查看一下崇拜已久的程序员的公开活动，就可以知道他现在关注些什么，或者正在热心于开发些什么。

## 5.5　仓库

&emsp;&emsp;仓库的 URL 形式：<https://github.com/用户名/仓库名>
&emsp;&emsp;这个页面可以说是各个软件的大门。循着目录找下去我们就可以查阅自己想要的文件。如果有相应权限，还可以对文件的内容直接进行编辑、提交。

### 关于 UI

#### 1 用户名（组织名）/ 仓库名

&emsp;&emsp;左上角图标旁边显示的是用户名和仓库名。斜线左侧为用户名。使用 GitHub 的组织账户时，这一部分则为组织名。斜线右侧是仓库名。

#### 2 Watch/Star/Fork

&emsp;&emsp;眼睛图标旁边写着 Watch 字样。点击这个按钮就可以 Watch 该仓库，今后该仓库的更新信息会显示在用户的公开活动中。Star 旁边的数字表示给这个仓库添加 Star 的人数。这个数越高，代表该仓库越受关注。
&emsp;&emsp;Watch 与 Star 有所不同，Watch 之后该仓库的相关信息会在后述的 Notifications 中显示，让用户可以追踪仓库的内容，而 Star 更像是书签，让用户将来可以在 Star 标记的列表中找到该仓库。另外，Star 数还是 GitHub 上判断仓库热门程度的指标之一。
&emsp;&emsp;旁边的分叉图标是 Fork 按钮。后面的数字代表该仓库被 Fork 至各用户仓库的次数。这个数字越大，表示参与这个仓库开发的人越多。

#### 3 Code

&emsp;&emsp;显示该仓库中的文件列表。仓库名下方是该仓库的简单说明和 URL。

#### 4 Issue

&emsp;&emsp;用于 BUG 报告、功能添加、方向性讨论等，将这些以 Issue 形式进行管理。Pull Request 时也会创建 Issue。旁边显示的数字是当前处于 Open 状态的 Issue 数。

#### 5 Pull Requests

&emsp;&emsp;在 Pull Requests 中可以列表查看并管理 Pull Request。代码的更改和讨论都可以在这里进行。旁边显示的数字表示尚未 Close 的 Pull Request 的数量。

#### 6 Wiki

&emsp;&emsp;Wiki 是一种比 HTML 语法更简单的页面描述功能。常用于记录开发者之间应该共享的信息或软件文档。数字表示当前 Wiki 的页面数量。

#### 7 Pulse

&emsp;&emsp;显示该仓库最近的活动信息。该仓库中的软件是无人问津，还是在火热地开发之中，从这里可以一目了然。

#### 8 Graphs

&emsp;&emsp;以图表形式显示该仓库的各项指标。让用户轻松了解该仓库的活动倾向。

#### 9 Network

&emsp;&emsp;以图表形式直观地显示出当前仓库的状态及 Fork 出的仓库的状态。同时会显示成员列表。

#### 10 Settings

&emsp;&emsp;这里可以更改当前仓库的设置。用户必须拥有更改设置的权限才能看到这个菜单。

#### 11 SSH clone URL

&emsp;&emsp;clone 仓库时所需的 URL。点击右侧的剪贴板图标可以将 URL 复制到剪贴板中。点击 HTTPS、SSH、Subversion 图标可以切换至相应协议的 URL。

#### 12 Clone in Desktop

&emsp;&emsp;启动 GitHub 专用的客户端应用程序并进行 clone。GitHub 专用的客户端应用程序有 Windows 版和 Mac 版。

#### 13 Download ZIP

&emsp;&emsp;将当前正在阅览的分支中的文件以 ZIP 形式打包下载。这种方式与 Git 的 clone 不同，只是单纯将文件下载到本地，所以无法通过 Git 查看日志或对仓库进行更改。如果只是想使用仓库中的文件，比较适合用这种方式下载。

##### a commits

&emsp;&emsp;在这里可以查看当前分支的提交历史。左侧的数字表示提交数。

##### b branches

&emsp;&emsp;可以查看仓库的分支列表。左侧的数字表示当前拥有的分支数。

##### c releases

&emsp;&emsp;显示仓库的标签（Tag）列表。同时可以将标签加入时的文件以归档形式（ZIP、tar.gz）下载到本地。软件在版本升级时一般都会打标签，如果需要特定版本的文件，可以从这里寻找。

##### d contributors

&emsp;&emsp;显示对该仓库进行过提交的程序员名单。如果您也对该仓库发送过 Pull Request 并且被采纳，那么在这里就能找到自己的名字。左边的数字是程序员的人数。

##### e Compare & review

&emsp;&emsp;可以查看当前显示的分支与其他分支的差别，以便进行审查。点击这个按钮，会出现一个页面让用户选择比较对象。

##### f branch

&emsp;&emsp;显示当前分支的名称。从这里可以切换仓库内分支，查看其他分支的文件。

##### g path

&emsp;&emsp;显示当前文件列表的路径。点击上级目录的链接就可以直接移动至该目录。

##### h Fork this project and Create a new file

&emsp;&emsp;可以在当前仓库的路径下新建文件。新建文件作为一个新的提交，记录在 Fork 出的分支中。
&emsp;&emsp;如果用户对该仓库拥有足够权限，该项则显示为 Create a new file，用户可以直接在当前路径下新建文件。

##### i files

&emsp;&emsp;可以查看当前分支的文件。顶端为最新提交的相关信息。在文件或目录的列表中，从左至右分别为文件名称、该文件最新的提交日志、更新日期。点击目录或文件就可以查看相应内容。
&emsp;&emsp;如果当前目录中包含 README 文件，那么在文件列表下方会显示 README。一般而言，README 中记录着该仓库中软件的说明或使用方法以及许可协议等信息，请务必加以阅读。

### 文件的相关操作

&emsp;&emsp;点开文件后会显示出文件的内容，同时右上角会显示用于该文件的菜单。Edit 可以对文件内容进行编辑并提交。Raw 可以直接在浏览器中显示该文件的内容。使用这个 URL，就能通过 HTTPS 协议获取该文件。Blame 能够按行显示最新提交的信息。History 可以查看该文件的历史记录。Delete 可以删除这个文件。
&emsp;&emsp;文件内容的左侧会显示该文件的行号。假如我们点击第 10 行的行号，这一行就会被高亮标记为黄色，同时 URL 末尾会自动添加“#L10”。使用这个 URL，程序员们在交流时，就可以将讨论明确指向某一行。另外，如果将“#L10”改成“#L10-15”，则会标记该文件的第 10 ～ 15 行。各位不妨将这点记下来，以便日后应用。

**通过部分名称搜索文件** ：在仓库页面试着按下键盘的 t 键，然后输入要找的目录或文件的部分名称。筛选器会在仓库的目录和文件中进行筛选，搜索出您要找的文件，这种方式要比一级级查看目录和文件快得多。

### 查看差别

&emsp;&emsp;在 GitHub 上，直接修改 URL 就可以让用户以多种形式查看差别。

#### 查看分支间的差别

&emsp;&emsp;比如我们想查看 4-0-stable 分支与 3-2-stable 分支之间的差别，可以像下面这样将分支名加到 URL 里。这样，就可以查看两个分支间的差别了。

> <https://github.com/rails/rails/compare/4-0-stable...3-2-stable>

#### 查看与几天前的差别

&emsp;&emsp;假如想查看 master 分支在最近 7 天内的差别，可以像将时间加入 URL。<https://github.com/rails/rails/compare/master@{7.day.ago}...master>

&emsp;&emsp;指定期间可以使用四个时间单位。

+ day
+ week
+ month
+ year

#### 查看与指定日期之间的差别

&emsp;&emsp;假设我们想查看 master 分支 2021 年 1 月 1 日与现在的区别，可以将日期加入 URL。

> <https://github.com/rails/rails/compare/master@{2021-01-01}...master>

&emsp;&emsp;这样，便可以查看与指定日期之间的差别。但是如果指定日期与现在的差别过大，或者指定日期过于久远，则无法显示。
&emsp;&emsp;由于可以从多种角度查看差别，所以 GitHub 也称得上是一个优秀的源代码查看器。各位不妨记住直接修改 URL 来查看差别的方法，当遇到上述情况时，它能帮您节省不少时间。

## 5.6　Issue

&emsp;&emsp;在软件开发过程中，开发者们为了跟踪 BUG 及进行软件相关讨论，进而方便管理，创建了 Issue。管理 Issue 的系统称为 BTS（Bug Tracking System，BUG 跟踪系统）。当今具有代表性的 BTS 有 Redmine[^网址1]、Trac5[^网址2]、Bugzilla6[^网址3] 等。

[^网址1]: <http://www.redmine.org/>
[^网址2]: <http://trac.edgewall.org/>
[^网址3]: <http://www.bugzilla.org/>

&emsp;&emsp;GitHub 也为自身加入了 BTS 的功能。在 GitHub 上，可以将它作为软件开发者之间的交流工具，多多加以利用。遇到下面几种情况时，各位就可以使用这个功能。

+ 发现软件的 BUG 并报告
+ 有事想向作者询问、探讨
+ 事先列出今后准备实施的任务

&emsp;&emsp;Issue 除 BUG 管理之外还有许多其他用途。在软件开发者的圈子中，将 Issue 用于多种用途的情况已经司空见惯。作为 GitHub 的功能之一，想必今后会有更多人自然而然地用到它。所以借此机会，让我们来共同学习 Issue 的一些简单用法。

### 简洁且表现力丰富的描述方法

&emsp;&emsp;GitHub 的 Issue 及评论可以使用 GFM[^网址4] 语法进行描述，从而获得丰富的表现力。点击 Preview，就可以看标记后的效果。

[^网址4]: <https://help.github.com/articles/github-flavored-markdown>

&emsp;&emsp;关于Markdown看一看专门的书籍来学习，这里不再赘述。

### 添加标签以便整理

&emsp;&emsp;Issue 可以通过添加标签（Label）来进行整理。添加标签后，Issue 的左侧就会显示标签。点击页面左侧的标签，还可以只显示该类标签的 Issue。
标签可以自由创建。标签既可以按语言和技术分类，也可以按照 BUG、任务、备忘等作业类型分类。各位可以按照需要选择便于整理的标签。

**提个小建议：** 其实在 Issue 比较少的情况下不必每个都添加标签，大可等 Issue 积攒到一定数量，只有进行筛选才能清晰把握时再添加标签。

### 添加里程碑以便管理

除标签外，还可以通过添加里程碑来管理 Issue。设置里程碑，就可以用 Issue 来管理任务。

+ 了解贡献时的规则

&emsp;&emsp;在描述 Issue 时，常常会看到贡献规范的链接。在该仓库的根目录下添加 CONTRIBUTING . md 文件后该链接就会显示出来。规范的内容一般包括报告时 Issue 的描述方法、Pull Request 时的规则或要求、许可证的相关信息等。为了在开源项目开发中能与其他人和谐相处，请务必在贡献之前仔细阅读这些规范。

### Tasklist 语法

&emsp;&emsp;Tasklist 语法会将Markdown语言的复选框文字被标记成复选列表的样式。这个复选列表可以直接勾选或者取消，不必打开 Issue 的编辑页面重新编辑，十分方便，

### 通过提交信息操作 Issue

&emsp;&emsp;在 GitHub 上，只要按照特定的格式描述提交信息，就可以像一般 BTS 带有的功能那样对 Issue 进行操作。

#### 在相关 Issue 中显示提交

&emsp;&emsp;在 Issue 一览表中可以看到，每一个 Issue 标题的下面都分配了诸如 “ #24 ” 的编号。只要在提交信息的描述中加入 “ #24 ” ，在 Issue 中显示该提交的相关信息，使关联的提交一目了然。这里只需轻轻点击一下便可以显示相应提交的具体内容，在代码审查时省去了从大量提交日志中搜索相应提交的麻烦，非常方便。

#### Close Issue

&emsp;&emsp;如果一个处于 Open 状态的 Issue 已经处理完毕，只要在该提交中以下列任意一种格式描述提交信息，对应的 Issue 就会被 Close。

+ fix #24
+ fixes #24
+ fixed #24
+ close #24
+ closes #24
+ closed #24
+ resolve #24
+ resolves #24
+ resolved #24

&emsp;&emsp;利用这个方法，每次提交并 push 之后，就不必再大费周章地到 GitHub 的 Issue 中寻找相应 Issue 再手动 Close，省去不少麻烦。像这样，只要按照特定的格式描述提交信息，GitHub 就会自动识别并处理，让使用 GitHub 变得更加轻松。目前，很多 GitHub 之外的 BTS 也实现了这一功能，记住它绝对是有利无弊的。

### 将特定的 Issue 转换为 Pull Request

&emsp;&emsp;在 GitHub 上，如果给 Issue 添加源代码，它就会变成我们马上要讲到的 Pull Request。Issue 与 Pull Request 的编号相互通用，通过 GitHub 的 API 可以将特定的 Issue 转换为 Pull Request，能够完成这一操作的 hub 命令将在本书的 8.1 节中讲解。在这里，各位只要先记住 Issue 与 Pull Request 的编号通用即可。

## 5.7　Pull Request

&emsp;&emsp;Pull Request 是用户修改代码后向对方仓库发送采纳请求的功能，也是 GitHub 的核心功能。正因为有了这个功能，才会让众多开发者轻松地加入到开源开发的队伍中来。
&emsp;&emsp在 Pull Request 页面能够列表查看当前处于 Open 状态的 Pull Request。通过点击页面左部和上部的选项可以进行筛选和重新排列。在列表中点击特定的 Pull Request 就会进入详细页面。页面上方显示着这次是从谁的哪个分支向谁的哪个分支发送了 Pull Request。

+ 获取 diff 格式与 patch 格式的文件

&emsp;&emsp;对长期投身于软件开发的人来说，有时可能会希望以 diff 格式文件和 patch 格式文件的形式来处理 Pull Request。

```shell
例如：假设 Pull Request 的 URL 如下所示。
https://github.com/用户名/仓库名/pull/28

如果想获取 diff 格式的文件，只要像下面这样在 URL 末尾添加 .diff 即可。
https://github.com/用户名/仓库名/pull/28.diff

同理，想要 patch 格式的文件，只需要在 URL 末尾添加 .patch 即可。
https://github.com/用户名/仓库名/pull/28.patch
```

### Conversation

&emsp;&emsp;在 Conversation 标签页中，可以查看与当前 Pull Request 相关的所有评论以及提交的历史记录。人们在这里添加评论互相探讨，发送提交落实讨论内容的整个过程会按时间顺序列出，供用户查看。提交日志的右侧有该提交的哈希值，点击链接即可确认相应提交的详细信息。

+ 引用评论

&emsp;&emsp;在 Conversation 中人们通过添加评论进行对话。这里有一个简单方法可以帮您引用某个人的评论。选中想引用的评论然后按 R 键，被选择的部分就会自动以评论语法写入评论文本框。这样一来就可以轻松便捷地引用评论了。该快捷键在 Issue 中同样有效。

### Commits

&emsp;&emsp;在 Commits 标签页中，按时间顺序列表显示了与当前 Pull Request 相关的提交。标签上的数字为提交的次数。每个提交右侧的哈希值可以连接到该提交的代码。

+ 在评论中应用表情

&emsp;&emsp;GitHub 的文化中有使用表情的习惯。表情种类繁多，要一次全记下来十分困难。这时我们可以利用表情的自动补全功能。在评论中输入 “ : ” （冒号）便会启动表情自动补全功能。只要输入几个与该表情相关的字母，系统就会为您筛选自动补全的对象。选择想要的表情，其相应代码（前后都有冒号的字符串）便会插入到文本框中。

### Files Changed

&emsp;&emsp;Files Changed 标签页中可以查看当前 Pull Request 更改的文件内容以及前后差别。标签上的数字表示新建及被更改的文件数。
&emsp;&emsp;默认情况下系统会将空格的不同也高亮显示，所以在空格有改动的情况下会难以阅读。这时只要在 URL 的末尾添加“?w=1”就可以不显示空格的差别。
&emsp;&emsp;将鼠标指针放到被更改行行号的左侧，我们会看到一个加号。点击这个加号可以在代码中插入评论。这样，评论是针对哪行代码的就一目了然了。
&emsp;&emsp;这个插入评论的功能让针对代码的讨论变得十分顺畅。特别是在多人协作的软件开发中，这个功能更加不可或缺。

## 5.8　Wiki

&emsp;&emsp;Wiki 是一个使用简单的语法就能编写文档的功能。所有有权限的人都可以对文章进行修改，所以比较适合多人共同编写文章的情况。创建、编辑文档时不必另外启动软件，用起来十分方便，非常适合用来针对更新频率较高的软件进行文档等信息方面的汇总。
&emsp;&emsp;与 Issue 和 Pull Request 相同，Wiki 也支持 GFM 语法，所以可以轻松创建表现力丰富的文档。点击页面右上角的 New Page 按钮便可以创建新的 Wiki 页。
&emsp;&emsp;Wiki 功能本身的数据也在 Git 中进行管理。点击 Clone URL 按钮可以将当前 Wiki 的 Git 仓库 URL 复制到剪贴板中。用户能够通过 clone 操作获取 Wiki 仓库，然后在本地创建、编辑页面，进行提交再 push，便可以完成对 Wiki 的创建及编辑工作。

### Pages

&emsp;&emsp;在 Pages 标签页中可以列表查看 Wiki 页面。

### History

&emsp;&emsp;在 History 标签页中可以查看 Wiki 的修改历史记录。
&emsp;&emsp;由于 Wiki 功能也有历史记录可查，所以软件开发者可以放心地投入到工作中去。将 Wiki 仓库 clone 到本地，就可以不借助浏览器，直接用自己熟悉的编辑器进行编辑，十分人性化。
&emsp;&emsp;一般情况下，Wiki 中记载着软件相关的 FAQ、文档、代码示例及解说等信息。各位在使用 GitHub 上开发的软件前，建议先查看一遍 Wiki。

+ 在 Wiki 中显示侧边栏

所有 Wiki 页面都可以显示侧边栏。做法很简单，只要创建名为“_sidebar”的页面即可。_sidebar 页不会显示在 Pages 的页面一览中。在编辑各页面时页面下部会附加 Sidebar 段，用户可以在这里编辑侧边栏的内容。

## 5.9　Pulse

&emsp;&emsp;Pulse 是体现该仓库软件开发活跃度的功能。近期该仓库创建了多少 Pull Request 或 Issue，有多少人参与了这个仓库的开发等，都可以在这里一目了然。
&emsp;&emsp;根据这个页面，用户可以判断目前这个软件是否正在被积极开发，或者持有仓库修改权限的人是否在认真地进行 BUG 修正等维护工作。在挑选 GitHub 上开发的软件时，它可以作为一个重要的衡量标准。

### active pull requests

&emsp;&emsp;页面中 Overview 的左半部分显示了特定期间内活动过的 Pull Request 数。如果想查看清单的详细内容，只要点击对应项即可。Pull Request 的概要及链接按照合并的先后顺序排列。
&emsp;&emsp;点击 proposed-pull-request 则可以按 创建的先后顺序查 看 Pull Request 的概要及链接。通过这些信息，用户可以了解该软件最近正在开发哪些功能。

### active issue

&emsp;&emsp;页面中 Overview 的右半部分显示了特定期间内活动过的 Issue 数。如果想查看清单的详细内容，只要点击对应项即可。Issue 的概要及链接按照 Close 的先后顺序排列。
&emsp;&emsp;点击 new issue 则可以按创建的先后顺序查看 Issue 的概要及链接。通过观察 Issue 的整体动向，用户能够知道这个软件是否有人在积极地维护与支持。对方仓库越是活跃，用户发送的 BUG 报告和相关探讨越可能收到回应。

### commits

&emsp;&emsp;Overview 下方显示的是与提交相关的信息。左侧部分包含了如下几类信息。

+ 编写过代码的人数
+ 提交的次数
+ default branch 中修改过的文件数
+ default branch 中添加的行数
+ default branch 中删除的行数

&emsp;&emsp;通过这些信息，用户可以大致把握该仓库中活跃开发者的人数。另外，右侧图表显示了这些开发者具体发送的提交数。通过图表我们可以了解到有哪些开发者在格外积极地向该仓库发送提交。

### Releases published

提交相关信息的下方显示了“5 Releases published”之类的字样，这是版本发布的相关信息。已发布的各版本的下载链接按照发布时间的先后顺序一一列出。

通过这里我们可以了解到该软件的版本升级频率。

### Unresolved Conversations

&emsp;&emsp;这里列出的 Issue 和 Pull Request 都创建于 Period 指定的时间之前，它们都尚未 Close 并且仍有人参与评论。一般情况下，仓库中软件的重大事项讨论都会持续很长时间，所以这些讨论大多放在这里。其中会有不少关于该软件今后发展方向的讨论。

## 5.10　Graphs

&emsp;&emsp;在 Graphs 页中，可以通过 4 种图表查看该仓库的相关统计信息。利用图表直观地汇总信息，可以让用户把握当前仓库的各种趋势。

### Contributors

&emsp;&emsp;在 Contributors 的图表中，我们可以看到每个用户在相应日期中发送提交、添加代码、删除代码的大致数量。从这里能够了解到该仓库的代码主要由哪些人编写。而且，还可以通过图表分析出该软件大幅修改阶段和稳定维护阶段的相应时期。另外，这些图表的统计中还包括发送 Pull Request 被采纳后产生的代码增减。

### Commit Activity

&emsp;&emsp;Commit Activity 中显示了一年内（52 周）每周收到的提交的大致数量。第二张表中还可以查看相应周每天的提交数量。判断某个仓库是否有人在积极更新时，这部分是一个重要的指标。

+ Code Frequency
  Code Frequency 中显示了该仓库中代码行数的增加量和删除量。一款优秀的软件并不会一味地增加代码，在经过重构之后，代码量往往会降低。通过这张图，我们可以直观地把握相应信息。

### Punchcard

&emsp;&emsp;从 Punchcard 的图中我们可以直观地掌握一周内每天何时收到的提交最多。黑色圆越大，表示提交越频繁。
&emsp;&emsp;仓库的关键人物往往会出现在提交频率高的时间段，因此用户发送的 Pull Request 最有可能在这段时间内被处理。大致了解时间规律，将有助于各位把握好发送 Pull Request 以及等待回复的时间点。另外，该软件的开发是集中在早上还是晚上，从这张图中也可一目了然。

## 5.11　Network

&emsp;&emsp;以图表形式显示包括克隆仓库在内的所有分支的提交。从图上可以直观地看出每个人做了多少工作。将鼠标指针停留在表中提交或合并的点上，可以查看相应的参考内容。

## 5.12　Settings

&emsp;&emsp;在这里可以对仓库进行任何设置。用户必须拥有更改设置的权限，才能看到这个页面。

### Options

&emsp;&emsp;在 Options 中可以变更仓库本身的相关设置。

#### 1 Settings

&emsp;&emsp;在这里可以修改仓库名称，设置显示仓库 URL 时默认显示的分支。这个默认分支同时也是创建 Pull Request 时的默认值，如果各位的主分支不是 master 分支，建议更改这一设置。

#### 2 Features

&emsp;&emsp;这里可以更改 Wiki 和 Issue 的相关设置。如果想关闭某些功能，只要取消已勾选的相应复选框，该功能就会从菜单中移除，无法使用。

#### 3 GitHub Pages

&emsp;&emsp;GitHub 有一个名为 GitHub Pages 的仓库，用户可以利用该仓库中的资料创建 Web 页，用来发布仓库中软件的相关信息。如果已经创建过 GitHub Pages，则会显示相应 URL。点击 Automatic Page Generator 即可以自动创建 GitHub Pages。

#### 4 Danger Zone

&emsp;&emsp;这里都是一些需要格外留意的设置。在这里，用户可以将仓库改为私有或是变更仓库所有者，甚至删除仓库本身。这些设置有可能影响到其他人，在变更时一定要谨慎。

### Collaborators

&emsp;&emsp;用户主要在这里设置仓库的访问权限。如果仓库隶属于个人账户，那么可以添加 GitHub 的用户名，赋予该用户直接读写仓库的权限。
&emsp;&emsp;不过，如果仓库隶属于 Organization 账户，则需要先创建 Team，然后赋予该 Team 读写仓库的权限。像这样使用 Organization 账户可以高效地设置仓库权限，在公司等多人共同进行开发的组织中，建议使用 Organization 账户。

### Webhooks & Services

&emsp;&emsp;在这个页面中，用户可以添加 Hook 让 GitHub 仓库与其他服务集成。通过 Add webhook 可以添加用户自己的 webhook。通过 Configure services 则可以从 GitHub 事先列出的可以集成的服务中进行选择。能与 GitHub 集成的服务非常多，其中还包括邮件及 IRC 等社交服务，建议各位不要错过这个设置。在如此大量的服务当中，相信各位能找到自己正在使用的工具。

### Deploy Keys

&emsp;&emsp;在这个页面中，用户可以添加用于部署的公开密钥，允许以只读方式访问仓库。设置公开密钥后，用户可以使用私有密钥通过 ssh 协议 clone 仓库。要注意的是，这里添加的公开密钥·私有密钥对无法再添加到其他仓库。使用 Deploy Keys 功能时，需要给每个仓库赋予不同的密钥对。

## 5.13　Notifications

&emsp;&emsp;页面左上角 LOGO 旁边的蓝色亮点就是 Notifications。点击它，我们可以看到 GitHub 所有活动的通知。灵活运用这个 Notifications，可以大幅提高合作开发的效率。每当创建 Issue、收到评论、创建 Pull Request 等情况发生时，我们就会在 Notifications 中收到通知。

&emsp;&emsp;页面左侧是 Notifications 的筛选器，可以分别查看未读的、与自己相关的通知，或者按仓库分类查看通知等。点击仓库名右侧的对勾，可以将该仓库的所有 Notifications 设置为已读状态。

&emsp;&emsp;点击各条通知右侧的扩音器图标，那么即使今后这个通知的相关内容再收到追加评论时，也不会再通知用户。点击通知右侧的对勾，可以将相应的 Notifications 设置为已读状态。当然，点击 Notifications 阅读详细内容后，该通知也会自动转换为已读状态。如果 LOGO 旁的蓝色亮点是发光状态，则表示有未读的 Notifications，请养成及时查看的习惯。越早处理通知，开发者之间的协同工作就越有效率。

## 5.14　其他功能

### GitHub Pages

&emsp;&emsp;GitHub Pages 主要用于在 GitHub 上托管静态 HTML，以便发布项目的 Web 页。由于可以绑定独立域名，人们也经常利用结合了这个功能的 Octopress 框架来搭建博客。

### GitHub Jobs

&emsp;&emsp;GitHub Jobs 是面向全世界招聘程序员的职位公告板。想到海外就职的程序员也可以多看一看这里。

### GitHub Enterprise

&emsp;&emsp;GitHub Enterprise 专为那些无法将源代码放到公司之外的企业设计。这项服务可以以虚拟机的形式提供 GitHub。申请后可以先试用 45 天，所以企业内部在探讨是否导入时可以实际使用一下再决定。

&emsp;&emsp;导入的最大阻碍其实是成本。这项服务主要面向 20 人以上的组织，如果规模不足，建议还是使用普通的 GitHub。详细内容请参照 GitHub Enterprise 的页面。考虑到实体机的运行成本及维护成本，除非是规模相当大的企业，否则还是不建议使用 GitHub Enterprise。

### GitHub API

&emsp;&emsp;GitHub 面向开发者公开了 API。特别是在开发面向程序员的 Web 服务时，能与 GitHub 集成绝对有利无弊。详细内容请参照官方网站。

## 5.15　小结

&emsp;&emsp;本文中，结合 GitHub 的实际操作页面讲解了 GitHub 上提供的各项功能。其中某些功能的细节可能经常使用 GitHub 的人也并不完全清楚。
