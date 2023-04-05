#!/usr/bin/env bash

set -e

if [ "$(whoami)" != "root" ];then
    echo "Pls use root with sudo."
    exit 1
fi

systemctl stop MonitorX.service
systemctl disable MonitorX.service

rm -rf /opt/MonitorX/
rm -rf /etc/systemd/system/MonitorX.service
rm -rf /etc/systemd/system/multi-user.target.wants/MonitorX.service

echo 'Done!'
