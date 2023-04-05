
# -*- coding: utf-8 -*-

import ctypes, sys, time, logging, json
import win32api, win32gui
from network import send
from psutilib import GetNetWork,GetIoReadWrite
from OpenHardwareMonitorLib import UpdateMonitor


def generate_output():
    hw_monitor = UpdateMonitor()
    hw_monitor['summary'] = dict()

    # Time
    hw_monitor['summary']['time'] = time.strftime("%H:%M", time.localtime())
    hw_monitor['summary']['date'] = time.strftime("%Y-%m-%d", time.localtime())
    hw_monitor['summary']['week'] = time.strftime("%a", time.localtime()) + '.'

    # CPU
    hw_monitor['summary']['cpu_model'] = hw_monitor['CPU']['Name']
    hw_monitor['summary']['cpu_load'] = round(hw_monitor['CPU']['Load']['CPU Total'] + 0.5, 0)
    cpu_temperature = hw_monitor['CPU']['Temperature']['CPU Core']
    hw_monitor['summary']['cpu_temp'] = round(sum(cpu_temperature) / len(cpu_temperature) + 0.5, 0)
    cpu_clock = hw_monitor['CPU']['Clock']['CPU Core']
    hw_monitor['summary']['cpu_clock'] = round(sum(cpu_clock) / len(cpu_clock) + 0.5, 0)
    # RAM
    hw_monitor['summary']['ram_load'] = round(hw_monitor['RAM']['Load']['Memory'] + 0.5, 0)
    ram_total =  hw_monitor['RAM']['Data']['Used Memory'] + hw_monitor['RAM']['Data']['Available Memory']
    hw_monitor['summary']['ram_total'] = str(int(round(ram_total + 0.5, 0))) + 'GB'

    # GPU
    hw_monitor['summary']['gpu_model'] = hw_monitor['GpuNvidia']['Name']
    hw_monitor['summary']['gpu_load'] = hw_monitor['GpuNvidia']['Load']['GPU Core']
    hw_monitor['summary']['gpu_temp'] = hw_monitor['GpuNvidia']['Temperature']['GPU Core']
    hw_monitor['summary']['gpu_clock'] = hw_monitor['GpuNvidia']['Clock']['GPU Core']
    # GRAM
    hw_monitor['summary']['gram_load'] = round(hw_monitor['GpuNvidia']['Load']['GPU Memory'] + 0.5, 0)
    gram_total = round(hw_monitor['GpuNvidia']['SmallData']['GPU Memory Total']/1024.0, 0)
    hw_monitor['summary']['gram_total'] = str(int(gram_total)) + 'GB'

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
    t = time.strftime("%Y-%m-%d_%H-%M-%S", time.localtime())
    logging.basicConfig(filename="E:/2.code/python/system_monitor/" + t + ".log", filemode="w", format="%(asctime)s %(name)s:%(levelname)s:%(message)s",
                        datefmt="%Y-%m-%d %H:%M:%S", level=logging.DEBUG)
    logging.info(time.asctime())

    # run as service
    ct = win32api.GetConsoleTitle()
    hd = win32gui.FindWindow(0, ct)
    win32gui.ShowWindow(hd, 0)

    if is_admin():
        while True:
            output_dict = generate_output()
            logging.info(output_dict)
            print(output_dict)
            output = json.dumps(output_dict)
            output += '\n'
            send(output.encode())
            time.sleep(1)
    else:
        ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, __file__, None, 1)

    logging.error("exit!\n")