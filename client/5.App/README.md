## X86平台开发&调试
1. `make platform=x86`  
2. `./monitorX.x86`  

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