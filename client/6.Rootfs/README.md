# 

# custom rootfs
1. add to `/etc/profile` and `source /etc/profile`  
```
alias vim="vim.tiny"
alias ll="ls -al"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/root/thirdparty/shared/t113/lib/
``` 
3. `vim /etc/modules` and `mkdir -p /lib/modules/$(uname -r)`  
4. `cp *.ko /lib/modules/$(uname -r)` and `depmod -a` (TODO)  
```
# /etc/modules: kernel modules to load at boot time.  
#
# This file contains the names of kernel modules that should be loaded
# at boot time, one per line. Lines beginning with "#" are ignored.

8723ds.ko
gt9xxnew_ts.ko
# usb-storage.ko
# sunxi_gpadc.ko
```
3. `vim /etc/init.d/network.sh` and `chmod 766 /etc/init.d/network.sh` and `update-rc.d network.sh defaults`
```
#! /bin/bash

### BEGIN INIT INFO
# Provides:          network
# Required-Start:    $local_fs
# Required-Stop:     $local_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: network service
# Description:       init network service
### END INIT INFO

ifconfig wlan0 up
mkdir -p /var/run
rm -rf /var/run/wpa_supplicant/wlan0
wpa_supplicant -B -d -i wlan0 -c /etc/wpa_supplicant.conf

#udhcpc -i wlan0
ifconfig wlan0 192.168.1.8 netmask 255.255.255.0
route add default gw 192.168.1.1
#ifconfig
```
5. 
6. 