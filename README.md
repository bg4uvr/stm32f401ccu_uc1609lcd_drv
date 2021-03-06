#### 前言
刚开始接触STM32时，是使用MDK环境，用STD库学习的。后来不想用D版了，就改用EmBitz环境来了，EmBitz在使用时，库文件是自动复制的，不需要手工整理了，比较方便。但这个EmBitz在版本已经很老了，有几年没有更新了。最近发现STM官方的STM32CubeIDE不错，于是开始学习这个环境。软件操作很快就可以上手，但难点在于以前都是用STD库，没有学过HAL库，所以所有硬件操作对于我来说都是全新的方法，需要摸索。现在有些时间，就把学习过程记录一下，希望能帮到和我一样准备转换开发环境或者刚开始学习HAL库的朋友。



#### 实验简介
实验使用某宝买到的stm32f401ccu6小板（19块包邮），来演示驱动一片19264 COB封装的液晶屏（9.9元包邮）。本代码修改于我之前在其他硬件及软件环境下的屏幕驱动，其中字符显示及绘图部分代码源于网络，因时间较久，已无法查证具体出处，在此对原作者表示感谢。

本驱动使用了硬件SP1端口，工作在42Mbps速率，在RAM中开辟1.5KB专用显存，使用定时器10每20mS产生一次中断，来使用DMA模式直接从RAM向SPI硬件刷新显示数据。另外定时器11用来驱动一个在PC13口的LED每秒闪烁1次。

**因此本驱动的特点是：**

1. 用硬件SPI口，工作在最高速率。
2. 使用DMA方式来传输显示数据。
3. 显示数据是定时器自动刷新的。
4. 使用者只要调用显示函数，点阵的数据就直接存储在显存中。

所以，本驱动的特点就一个字，快！如果感觉50Hz的刷新速率不够，您还可定时器改得更快，最高能到多快，我还真没试过，有兴趣的朋友可以试试。



学习过程中的作品，如有错误不足敬请谅解~



**演示视频**

https://v.youku.com/v_show/id_XNDY1MzcxOTUyNA==.html


有朋友可能觉得，这好像也没看出有啥快的啊，好吧我重新拍了个视频
https://v.youku.com/v_show/id_XNDY1ODE4NDc4OA==.html

**完整实验代码下载地址：**
[Gitee](https://gitee.com/bg4uvr/stm32f401ccu_uc1609lcd_drv)
[Github](https://github.com/bg4uvr/stm32f401ccu_uc1609lcd_drv)




#### 怎样打开这个项目：

由于国内玩STM32单片机的爱好者，大部份都是使用MDK开发环境学习的，如果之前没接触过STM32cubeIDE这个软件，直接打开这个工程很可能会失败，从而是影响心情，所以这里把步骤说一下，供需要朋友参考：

1. **怎样克隆项目**

   如果你平时就使用git，那这就不是问题了，直接用一句 git clone 就可以克隆到本地了。

   如果你没有安装git软件，那么可以直接点击“克隆/下载”，然后点击下面的“下载ZIP”，这样会下载一个ZIP压缩文件，下载好后解压缩就可以得到项目的文件夹了。
   
2. **怎样打开项目**

   * 安装STM32CubeIDE

     打开官网 https://www.st.com/zh/development-tools/stm32cubeide.html 下载STM32CubeIDE，官网下载需要注册，如果你不想注册也可以去其他地方下载。下载后安装好，不再赘述。

   * 导入项目

     克隆好的项目并不能在 STM32CubeIDE 软件中直接打开，这是因为你下载好后的项目代码，路径和我的电脑上是不一样的，因此需要导入这个项目后才可以。具体操作如果：

     * 打开你的 STM32CubeIDE 软件，如果有更新之类的，都让它自己更新好，其实你安装后，你不用任何设置，它就已经可以很好的工作了。随着你对它的熟悉，你可能会有一些更细致的设置需求，那时你可以再仔细研究，本处略过不说。
     
     * 打开软件后，默认是打开 “Welcome to STM32CubeIDE” 欢迎页面的，但这个页面可能之前被你关掉过了，它就不会再自动打开。如果没自动打开这个页面也没关系，可以点击图标栏上最右一个叹号的图标 “Information Center” (消息中心)，就可以打开这个欢迎页面了。
     * 点击3个蓝色方块的中间一个，“Start new project from STM32CubeMX .ioc file”，在新出现的窗口上点击右侧的 “Browse...”，然后选择刚才克隆好的项目目录，选中 .ioc文件，点击“打开”，再点击 “Finish”，经过一番跑条后，你应该终于看到了一个显示芯片的引脚的界面。
     * 本处是讲如何导入这个项目，所以本页里面具体的设置就不多聊了，直接点击工具栏图标的 “黄色齿轮” 图标（Device Configuration Tool Code Generation），又是一番跑条，点击工具栏图标最后侧 ”蓝色MX“ 图标左面那个图标（C/C++），左侧就可以看到项目管理器了，你可以点击打开各个代码来查看，也可以进行编译下载了。
     * 项目这样导入后，下次就可以直接打开了，不需要再次导入。