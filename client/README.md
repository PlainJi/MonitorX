## 编译 & 运行
1. `make`  
2. `sudo ./sys_monitor_ui`  

## 配置芒果派开机自启动
1. `cp client/system-monitor.service /usr/lib/systemd/system`  
2. `systemctl enable system-monitor.service`  
3. `systemctl start system-monitor.service`  