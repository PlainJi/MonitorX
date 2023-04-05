#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time, json
from network import send
from monitorlib import Monitor

if __name__ == '__main__':
    print(time.asctime())
    monitor = Monitor()

    while True:
        output_dict = monitor.update()
        output = json.dumps(output_dict)
        output += '\n'
        send(output.encode())
        print(output.encode())
        time.sleep(1)
