# PageSystem
突发奇想写的终端。大约 80 行代码，使用 C++ 标准库、Windows API。
目前版本：V1.0.3

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

> [!WARNING]
> program 功能需要提醒：**禁止输入带 &、| 等字符的命令！**
> 如果攻击者发给您一串带 **&、| 等字符**的命令，此命令很可能包含**恶意 cmd 代码**！
> 需要启动，请把带 **&、| 等字符**之后的内容、此字符和此字符前面的空格去除！并按回车启动正常软件（如 notepad.exe）

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
# 旧版本 MINGW：g++ -std=c++17 -g "main.cpp" -o "PageSystem.exe"，高于 C++ 17 的版本也可以。
```
如果还是不行，可能是**没有安装 MinGW 编译器**，下载就可以了（需要配置环境变量）。

## 许可证
本项目采用 **MIT License** 许可证。