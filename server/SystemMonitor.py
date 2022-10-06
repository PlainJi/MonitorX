
# -*- coding: utf-8 -*-

import ctypes, sys, time
from psutilib import GetFullSystemData,GetSystemVersionWindows,GetNetWork,GetIoReadWrite,GetCpuConstants
from OpenHardwareMonitorLib import UpdateMonitor
from network import send
import json
import win32api, win32gui

def generate_output():
    hw_monitor = UpdateMonitor()
    hw_monitor['summary'] = dict()
    # CPU
    hw_monitor['summary']['cpu_load'] = round(hw_monitor['CPU']['Load']['CPU Total'] + 0.5, 0)
    cpu_temperature = hw_monitor['CPU']['Temperature']['CPU Core']
    hw_monitor['summary']['cpu_temp'] = round(sum(cpu_temperature) / len(cpu_temperature) + 0.5, 0)
    cpu_clock = hw_monitor['CPU']['Clock']['CPU Core']
    hw_monitor['summary']['cpu_clock'] = round(sum(cpu_clock) / len(cpu_clock) + 0.5, 0)

    # RAM
    hw_monitor['summary']['ram_load'] = round(hw_monitor['RAM']['Load']['Memory'] + 0.5, 0)
    ram_total =  hw_monitor['RAM']['Data']['Used Memory'] + hw_monitor['RAM']['Data']['Available Memory']
    hw_monitor['summary']['ram_total'] = round(ram_total + 0.5, 0)

    # GPU
    hw_monitor['summary']['gpu_load'] = hw_monitor['GpuNvidia']['Load']['GPU Core']
    hw_monitor['summary']['gram_load'] = round(hw_monitor['GpuNvidia']['Load']['GPU Memory'] + 0.5, 0)
    hw_monitor['summary']['gpu_temp'] = hw_monitor['GpuNvidia']['Temperature']['GPU Core']
    hw_monitor['summary']['gpu_clock'] = hw_monitor['GpuNvidia']['Clock']['GPU Core']

    # NET
    network = GetNetWork()
    hw_monitor['summary']['link_up'] = network['up']
    hw_monitor['summary']['link_dw'] = network['down']

    # IO
    io = GetIoReadWrite()
    hw_monitor['summary']['io_write'] = io['write']
    hw_monitor['summary']['io_read'] = io['read']

    return hw_monitor['summary']

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

if __name__ == '__main__':
    print(time.asctime())

    # run as service
    ct = win32api.GetConsoleTitle()
    hd = win32gui.FindWindow(0, ct)
    win32gui.ShowWindow(hd, 0)

    if is_admin():
        while True:
            output_dict = generate_output()
            output = json.dumps(output_dict)
            output += '\n'
            send(output.encode())
            time.sleep(1)
    else:
        ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, __file__, None, 1)
