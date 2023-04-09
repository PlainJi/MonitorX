#!/usr/bin/env bash

set -e

if [ "$(whoami)" != "root" ]; then
    echo "Please run as root with sudo."
    exit 1
fi

which python3
if [ "$?" -ne 0 ]; then
    echo "python3 not found, pls install it first."
    echo "sudo apt install python3"
    exit 2
fi

which pip3
if [ "$?" -ne 0 ]; then
    echo "pip3 not found, pls install it first."
    echo "sudo apt install python3-pip"
    exit 3
fi

pip3 install -r requirements.txt
mkdir /opt/MonitorX
cp *.py /opt/MonitorX
chmod +x /opt/MonitorX/SystemMonitor.py

cp MonitorX.service /etc/systemd/system/
chmod 644 /etc/systemd/system/MonitorX.service
systemctl daemon-reload
systemctl enable MonitorX.service
systemctl start MonitorX.service
sleep 1
systemctl status MonitorX.service

echo 'Done!'
