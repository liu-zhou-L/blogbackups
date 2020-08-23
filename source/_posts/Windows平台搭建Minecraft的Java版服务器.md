title: Windows平台搭建Minecraft的Java版服务器
author: liu_zhou
abbrlink: 2202222a
date: 2020-05-02 08:54:00
tags:
---
## 准备

需要两个东西，Java环境和开服包

[Java8官网链接](https://www.java.com/zh_CN/)  
[官方开服包链接](https://mcversions.net/)

## 检查

在命令行输入以下代码：
```
java -version
```
如果出现类似下面的输出，则Java已安装成功
```
java version "1.8.0_251"
Java(TM) SE Runtime Environment (build 1.8.0_251-b08)
Java HotSpot(TM) Client VM (build 25.251-b08, mixed mode, sharing)
```

## 搭建服务器
安装完成Java后，将开服包放在合适的目录下，开始以下的步骤
### 配置
在服务器目录下新建start.cmd（将用来启动服务器）  
在其中输入以下代码：
```
@echo off
java -Xms1g -Xmx1g -jar server.jar
pause
```
双击启动服务器
<img src="https://s1.ax1x.com/2020/05/02/JjRLqS.jpg" style="zoom:70%">
关闭窗口，然后进入euls.txt文件，将false修改为true
<img src="https://s1.ax1x.com/2020/05/02/JjWuxx.jpg" style="zoom:70%">
完成后进入server.properties文件，参考以下内容对游戏设置进行编辑
```
#服务器基本设置
level-name = 服务器名称(这里必须使用英文)
hellworld = 地狱世界(true=开启 false=关闭)
spawn-monsters = 生成怪物(true=开启 false=关闭)
spawn-animals = 生成动物(true=开启 false=关闭)
online-mode = 在线模式(盗版服请设false)
max-players = 服务器上限人数(好友不多的建议10 否则设置多少消耗多少内存)
server-ip = 用于绑定服务器地址(建议留空 Hamachi例外)
pvp = 友军伤害(true=开启 false=关闭)
server-port = 服务器端口
white-list = 启用黑名单,在banned-players插入玩家名

#服务器隐藏设置
verify-names = 检测昵称,第一个重名昵称将被kick
spawn-protection = 重生点保护范围(单位:格 如32及32x32)
levelName = 服务器名称
onlineMode = 在线模式
autoSave = 自动保存
autoSaveMins = 服务器自动保存时间(单位:秒)
autoBackup = 自动备份
autoBackupMins = 自动备份时间(单位:秒)
keepBackupHours = 保留备份时间,超过将删除备份(单位:天)
autoRestart = 自动重启(服务端检测到错误时)
autoRestartMins = 自动重启时间(单位:秒)
exitOnFailure = 退出失效(未知)
port = 端口
internalPort = 内部端口
rconPort = 远程端口
rconPassword = 远程密码
useWhitelist = 是否启用特定的人才可加入服务器
useSMPAPI = 使用多核处理
c10tArgs = 是用C10T参数(好像是10进制的意思)
c10tMins = C10T处理时间(单位:秒)
maxPlayers = 同max-players
defaultGroup = 默认组(此为Steam组,盗版无视)
useSlashes = 使用斜杠语法(默认dots语法)
memory = 内存(及服务端最高吃多少内存)
useMsgFormats = 使用信息格式(未知)
msgTitleFormat = 信息标题格式
msgFormat = 信息格式
localChatRadius = 当地信息交互(AAA协议)
debug = 调试模式
alternateJarFile = 备用的jar文件(建议留空)
guestsCanViewComplex = 来宾可以查看(Complex好像是函数)
ipAddress = IP地址(建议留空)
javaArguments = Java参数
```

**盗版客户端请将online-mode设为false**

至此，服务器配置完成。

### 启动服务器
双击start.cmd即可启动服务器  
关闭服务器请在命令行窗口输入stop

### 使用端口映射在公网上联机

端口映射软件推荐使用免费的Sakura Frp  
[官网链接](https://www.natfrp.com/)

打开软件选择服务器的端口进行映射即可  