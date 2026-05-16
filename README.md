# RM-training-2026
>培训统一验收仓库
<br>[w1](##w1)   <br>[w2](##w2)
## w1
<a id="w1"></a>
### 提交内容
- 开发环境：g++ --version 截图、cmake --version 截图、hello world 终端运行截图
- Git：wx发给组长个人仓库链接；
- C++ 基础：至少 2-3 段体现不同语法点的示例代码
- 命令行小程序：main.cpp、CMakeLists.txt
### 完成内容
- 配置了开发环境
- 用cmake编译了命令行问候小程序
- 学习了基础的C++编程语言
- 学习了用git记录
### 提交内容
- g++的版本截图
- cmake的版本截图
- cmake编译过程
- 命令问候代码
- 命令循环问候代码
- 计算随机数组中偶数个数
- 输出结构体中成绩最好的
- CMakeLists.txt
- hello world 终端运行截图
### 问题
把github中的仓库到本地后对github中仓库进行改动使得云端与本地时间线不统一导致无法push
```bash
training-2026.git main
warning: 重定向到 https://github.com/chenyihong130/RM-training-2026.git/
To http://github.com/chenyihong130/RM-training-2026.git
 ! [rejected]        main -> main (fetch first)
error: 无法推送一些引用到 'http://github.com/chenyihong130/RM-training-2026.git'
提示：更新被拒绝，因为远程仓库包含您本地尚不存在的提交。这通常是因为另外
提示：一个仓库已向该引用进行了推送。再次推送前，您可能需要先整合远程变更
提示：（如 'git pull ...'）。
提示：详见 'git push --help' 中的 'Note about fast-forwards' 小节。
```
pull完再push
###
在vscode中改完代码但是依旧显示错误应为忘了用ctri+s更新到文件导致g++编译的是未更改的文件
### cmake使用
#### 让Cmake生成编译规则&make编译出可执行文件
![让Cmake生成编译规则&make编译出可执行文件](https://github.com/chenyihong130/RM-training-2026/blob/main/w1/%E6%88%AA%E5%9B%BE%202026-05-10%2010-27-17.png)
#### 执行结果
![执行结果](https://github.com/chenyihong130/RM-training-2026/blob/main/w1/%E6%88%AA%E5%9B%BE%202026-05-10%2010-27-29.png)
### 未解决
- opencv 还未安装
## w2
<a id="w2"></a>
### 提交内容
- 环境接入与基础概念：turtlesim运行截图；ros2 topic list / echo / info截图
- 基础通信与 launch / 参数：training_pkg代码；colcon build成功截图；talker / listener同时运行截图；launch启动截图；参数生效截图
- bag 调试：ros2 bag info截图；README.md写清你是怎么录制、回放和观察自己话题的
- 给参数补默认值和范围说明
- 把参数写进YAML由launch加载
- 录了一个bag并由bag play复现
### 完成内容
-配置了ros2的开发环境
-了解了ros2中的基础概念
-创建了工作空间和节点
-学会了用launch同时启动两个节点
-学了bag录制与复现
### 提交内容
-turtlesim运行截图
-ros2 topic list / echo / info截图
-training_pkg代码
-colcon build成功截图
-talker / listener同时运行截图
-launch启动截图
-ros2 bag info截图
-给参数补默认值和范围说明
-把参数写进YAML由launch加载
-录了一个bag并由bag play复现
### 要求说明
#### workspace
ros2工程的根目录，包含src/install/log/build
#### package
ros2中的基本单位，包含代码，声明，配置
#### node
ros2中的独立进程，依靠话题通信
#### topic
机电间单向传输的通道，topic一致才可以传输
#### bag
用ros2 bag record录制了/chatter话题数据
用ros2 bag play回放
用ros2 bag info查看bag文件信息
### 问题
#### 1.
ros2 run 提示 Package not found
原因：
工作空间没有执行 source install/setup.bash，ROS2 找不到编译后的包。
新开的终端不会继承 VS Code 终端的环境变量，必须重新 source。
解决：
cd ~/桌面/w2/ros2_test
source install/setup.bash
ros2 run training_pkg talker
#### 2.
YAML 参数文件加载失败
原因：
CMakeLists.txt 没有添加 install(DIRECTORY params ...)，参数文件没被复制到 install 目录。
launch.py 里的路径拼接错误，或 YAML 里的节点名和代码里的不一致（必须完全匹配）。
解决：
在 CMakeLists.txt 中添加安装规则
install(DIRECTORY launch params DESTINATION share/${PROJECT_NAME})
### 未解决
可完成录制、回放操作，但不懂bag存储数据的底层原理
不会自主分析bag文件信息、话题时长、消息数量
回放后无法独立排查收不到话题数据的问题
## w3
