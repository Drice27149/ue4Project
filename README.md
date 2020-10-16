### 10.11~10.16

#### 本周内容: 

*  获取并编译ue4源码
*  新建一个c++工程, 进行简单的场景编辑和工程设置
*  将工程编译并形成安卓安装包, 在手机上正常运行

#### apk和视频文件

  * apk和视频文件放在同一个压缩包中, [百度网盘链接](https://pan.baidu.com/s/1MUDm_s79gTaI_immbr2XaQ), 提取码: xn4x

#### 遇到的问题和解决方法: 

* 获取并编译ue4源码

  * 编译途中visual studio报 fatal error, 错误代号有C3859, C1076, C1060

    参考[MS文档对这个错误的描述](https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/fatal-error-c1060?view=vs-2019), 错误的原因是编译时电脑虚拟内存不足。做了以下两步之后问题解决

    *  把"/Zm1000"改为"/Zm200"
    *  在电脑设置中手动提升虚拟内存的上限

  * Engine\Extras\Android\SetupAndroid.bat无法正常执行, 报错信息为

    ```shell
    setx错误：语法无效，默认选项不允许超过'2'时间
    ```

     错误的原因是本机电脑的环境变量Path存在格式问题, 导致

    ```shell 
    setx PATH "%USERPATH%;%PLATFORMTOOLS%"
    ```

    这条命令无法正常执行, 手动把%PLATFORMTOOLS%加到环境变量中, 再把这条命令从SetupAndroid.bat中删除就可以了。

* 编译并形成安卓安装包

  * 工程编译形成安卓安装包时, 报错

    ```shell
    Exception in thread "main" java.util.zip.ZipException: error in opening zip file...
    ```

    错误的原因是自动下载的gradle-5.4.1-all.zip是不完整的, 到gradle官网上下载相同的包把本地的替换即可。
