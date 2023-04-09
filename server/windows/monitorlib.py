
import time, json
from network import send
from psutilib import GetNetWork, GetIoReadWrite
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
    hw_monitor['summary']['ram_capacity'] = str(int(round(ram_total + 0.5, 0))) + 'GB'

    # GPU
    hw_monitor['summary']['gpu_model'] = hw_monitor['GpuNvidia']['Name']
    hw_monitor['summary']['gpu_load'] = hw_monitor['GpuNvidia']['Load']['GPU Core']
    hw_monitor['summary']['gpu_temp'] = hw_monitor['GpuNvidia']['Temperature']['GPU Core']
    hw_monitor['summary']['gpu_clock'] = hw_monitor['GpuNvidia']['Clock']['GPU Core']
    # GRAM
    hw_monitor['summary']['gram_load'] = round(hw_monitor['GpuNvidia']['Load']['GPU Memory'] + 0.5, 0)
    gram_total = round(hw_monitor['GpuNvidia']['SmallData']['GPU Memory Total']/1024.0, 0)
    hw_monitor['summary']['gram_capacity'] = str(int(gram_total)) + 'GB'

    # NET
    network = GetNetWork()
    hw_monitor['summary']['link_up'] = network['link_up']
    hw_monitor['summary']['link_dw'] = network['link_dw']

    # IO
    io = GetIoReadWrite()
    hw_monitor['summary']['io_write'] = io['io_write']
    hw_monitor['summary']['io_read'] = io['io_read']

    return hw_monitor['summary']

def monitor_once():
    output_dict = generate_output()
    output = json.dumps(output_dict).encode()
    send(output)
    time.sleep(1)