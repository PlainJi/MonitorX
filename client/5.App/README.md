## X86平台开发&调试
1. `make platform=x86`  
2. `./monitorX.x86`  

## 无开发板/无显示器的仿真调试（SDL + Xvfb）
1. 拉取子模块 `git submodule update --init`（lvgl、iniparser）
2. 安装依赖 `sudo apt install libsdl2-dev libfreetype-dev libjpeg-dev libcurl4-openssl-dev xvfb xdotool imagemagick`
3. 编译 `mkdir build && cd build && cmake .. -DCMAKE_C_COMPILER=/usr/bin/cc -DCMAKE_CXX_COMPILER=/usr/bin/c++ && make -j`，可执行文件 `MonitorX` 生成在本目录
4. 运行 `Xvfb :99 -screen 0 800x480x24 &`，然后在本目录执行 `DISPLAY=:99 SDL_RENDER_DRIVER=software ./MonitorX`
5. 截图 `DISPLAY=:99 import -window root shot.png`，模拟点击 `DISPLAY=:99 xdotool mousemove 160 168 click 1`

## 部署到嵌入式平台
1. `make platform=t113 clean`  
2. `make platform=t113`  
3. 拷贝目录 `output/monitorX.t113` 到板子上  
4. `./monitorX.t113`

## 部署文件目录结构
```
.
├── monitorX.x86
├── config.ini
├── lib
│   └── x86
│       └── lib
│           ├── libcrypto.so -> libcrypto.so.3
│           ├── libcrypto.so.3
│           ├── libcurl.la
│           ├── libcurl.so -> libcurl.so.4.8.0
│           ├── libcurl.so.4 -> libcurl.so.4.8.0
│           ├── libcurl.so.4.8.0
│           ├── libfreetype.la
│           ├── libfreetype.so -> libfreetype.so.6.19.0
│           ├── libfreetype.so.6 -> libfreetype.so.6.19.0
│           ├── libfreetype.so.6.19.0
│           ├── libssl.so -> libssl.so.3
│           ├── libssl.so.3
│           ├── libz.so -> libz.so.1.2.12
│           ├── libz.so.1 -> libz.so.1.2.12
│           ├── libz.so.1.2.12
│           └── pkgconfig
│               ├── freetype2.pc
│               ├── libcrypto.pc
│               ├── libcurl.pc
│               ├── libssl.pc
│               └── openssl.pc
└── res
    ├── font
    │   ├── FangZhengHeiTi-GBK.ttf
    │   └── SmileySans-Oblique.ttf
    └── image
        ├── bg.png
        ├── big_pointer.png
        ├── bili_pressed.png
        ├── bili_released_loading.png
        ├── bili_released.png
        ├── coin.png
        ├── disconnect_48.png
        ├── face.jpg
        ├── face.png
        ├── favorite.png
        ├── follower.png
        ├── following.png
        ├── git_pressed.png
        ├── git_released_loading.png
        ├── git_released.png
        ├── like.png
        ├── mem_usage1.png
        ├── mem_usage2.png
        ├── small_pointer.png
        ├── tomato_100.png
        └── video.png
```