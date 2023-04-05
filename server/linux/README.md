## 安装
`bash install.sh`  
安装后开机以服务形式在后台自启动

## 卸载
`bash uninstall.sh`

## 数据格式
```
{  
    "time":"01:39",             # String  
    "date":"2023-04-06",        # String  
    "week":"Thu.",              # String  
    "cpu_model":"i7-6700K",     # String  
    "cpu_load":2,               # Percentage  
    "cpu_temp":37,              # Celsius  
    "cpu_clock":3600,           # MHz  
    "ram_load":25,              # Percentage  
    "ram_total":"16GB",         # String  
    "gpu_model":"GTX-1080",     # String  
    "gpu_load":1,               # Percentage  
    "gram_load":8,              # Percentage  
    "gpu_temp":38,              # Celsius  
    "gpu_clock":1607,           # MHz  
    "link_up":322,              # bytes/s  
    "link_dw":53,               # bytes/s  
    "io_read":0,                # bytes/s  
    "io_write":0                # bytes/s  
}
```