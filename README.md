# PageSystem
突发奇想写的终端。大约 80 行代码，使用 C++ 标准库、Windows API。
目前版本：V1.0.4-11141

## 预览
```text
========
PageSystem V1.0.4-11141
>>> print
Content: Hello!
Hello!
>>> program
Program name: notepad
[ 启动成功 ]
```
## 容错判断
目前加了一些容错逻辑，比如 program 的容错、write 的容错。
### 重点
- 防 Ctrl+Z 导致的无限输入 ( V1.0.4-11101+ ) 。
- 防写入时创建失败，无文件导致的用户疑惑 ( V1.0.3+ ) 。
- 防启动程序时启动失败，导致用户疑惑 [ Windows 已有容错 ] ( V1.0.3-1161+ ) 。

## 目前功能
**1.** info ( 打印系统信息 ) 
**2.** print ( 打印内容 )
**3.** program ( 启动电脑中的程序 )
**4.** exit ( 退出此程序 )
**5.** delete ( 删除文件 )
**6.** write ( 写入文件 )
**7.** download ( 下载文件 )

## 声明
- **数据无价，谨慎操作！**
- 下载功能依赖 **curl**，低版本 Windows **可能失效**。

> [!IMPORTANT]
> 如果陌生人给您发来任何带 **|**、**&**、**&&** 等带有 **特殊符号** 的命令，请您一定不要执行它。
> 攻击者很可能在这些符号的后面增加恶意代码，窃取您的隐私信息或植入后门木马、病毒。
> **请勿输入不明来源的命令**。

## 调试与运行
如需调试与运行，方法如下：

### 调试
**1.** 下载此项目的 ZIP 后，打开 `build.bat` 就可以编译了。
build.bat 未加 **-std=c++17**，如果您使用的是旧版本 MinGW，需要这样写才能编译成功：
```bash
taskkill /f /im PageSystem.exe
g++ -std=c++17 -g "main.cpp" -o "PageSystem.exe"
# 提示：高于 C++ 17 的版本也可以。
```
> [!TIP]
> 为什么加 **`taskkill /f /im PageSystem.exe`**？因为如果当前已经运行了 `PageSystem.exe`，直接编译会报错（因为进程会被占用），所以需要用 taskkill 来终止进程。

**2.** 打开 **`PageSystem.exe`**，此程序就是主程序的入口。

### 运行
**1.** 下载此项目的 ZIP 后，**直接打开 `PageSystem.exe`** 就可以运行了。

### 运行失败？
如果 `build.bat` 打不开，可以直接在终端尝试此命令：
```bash
taskkill /f /im PageSystem.exe
g++ -g "main.cpp" -o "PageSystem.exe"
# 旧版本 MinGW：g++ -std=c++17 -g "main.cpp" -o "PageSystem.exe"，高于 C++ 17 的版本也可以。
```
如果还是不行，可能是**没有安装 MinGW 编译器**，下载就可以了（需要配置环境变量）。

## 许可证
本项目采用 **MIT License** 许可证。