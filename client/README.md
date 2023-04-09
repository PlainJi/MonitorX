## X86平台开发&调试
1. `make target=x86`  
2. `./sys_monitor_ui`  

## 部署到嵌入式平台
1. `make target=t113 clean`  
2. `make target=t113`  
3. 拷贝目录 `output/t113` 到板子上  

## 部署文件目录结构
```
.
├── monitorX.t113
└── thirdparty
    └── shared
        └── t113
            └── lib
                ├── libcrypto.so -> libcrypto.so.3
                ├── libcrypto.so.3
                ├── libcurl.la
                ├── libcurl.so -> libcurl.so.4.8.0
                ├── libcurl.so.4 -> libcurl.so.4.8.0
                ├── libcurl.so.4.8.0
                ├── libfreetype.la
                ├── libfreetype.so -> libfreetype.so.6.19.0
                ├── libfreetype.so.6 -> libfreetype.so.6.19.0
                ├── libfreetype.so.6.19.0
                ├── libssl.so -> libssl.so.3
                ├── libssl.so.3
                ├── libz.so -> libz.so.1.2.12
                ├── libz.so.1 -> libz.so.1.2.12
                ├── libz.so.1.2.12
                └── pkgconfig
                    ├── freetype2.pc
                    ├── libcrypto.pc
                    ├── libcurl.pc
                    ├── libssl.pc
                    └── openssl.pc
```