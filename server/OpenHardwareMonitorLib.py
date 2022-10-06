# -*- coding: utf-8 -*-

import time
import clr  # the pythonnet module.
clr.AddReference(r'OpenHardwareMonitor/OpenHardwareMonitorLib')
from OpenHardwareMonitor.Hardware import Computer

class OpenHardwareMonitor:
    HardwareType = ["Mainboard",
                    "SuperIO",
                    "CPU",
                    "RAM",
                    "GpuNvidia",
                    "GpuAti",
                    "TBalancer",
                    "Heatmaster",
                    "HDD"]
    SensorType = ["Voltage",        # V
                  "Clock",          # MHz
                  "Temperature",    # °C
                  "Load",           # %
                  "Fan",            # RPM
                  "Flow",           # L/h
                  "Control",        # %
                  "Level",          # %
                  "Factor",         # 1
                  "Power",          # W
                  "Data",           # GB = 2^30 Bytes
                  "SmallData",      # MB = 2^20 Bytes
                  "Throughput"]     # MB/s = 2^20 Bytes/s

    def __init__(self):
        self.c = Computer()  # 实例这这个类
        self.c.CPUEnabled = True
        self.c.RAMEnabled = True
        self.c.GPUEnabled = True
        self.c.HDDEnabled = True
        self.c.Open()

    def Update(self):
        ret = dict()
        self.c.Hardware[0].Update()
        self.c.Hardware[1].Update()
        self.c.Hardware[2].Update()
        self.c.Hardware[3].Update()

        for hw_index in range(0, len(self.c.Hardware)):
            hw_type = self.HardwareType[self.c.Hardware[hw_index].HardwareType]
            ret[hw_type] = dict()
            for ss_index in range(0, len(self.c.Hardware[hw_index].Sensors)):
                ss_type = self.SensorType[self.c.Hardware[hw_index].Sensors[ss_index].SensorType]
                name = self.c.Hardware[hw_index].Sensors[ss_index].Name
                value = self.c.Hardware[hw_index].Sensors[ss_index].Value
                #print(ss_type, name, value)
                if ss_type not in ret[hw_type].keys():
                    ret[hw_type][ss_type] = dict()
                if '#' in name:
                    name = name.split('#')[0].strip()
                    if name not in ret[hw_type][ss_type].keys():
                        ret[hw_type][ss_type][name] = list()
                    ret[hw_type][ss_type][name].append(value)
                else:
                    ret[hw_type][ss_type][name] = value
        return ret

def UpdateMonitor():
    return monitor.Update()

monitor = OpenHardwareMonitor()