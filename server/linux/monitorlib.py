#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os, time, json
from io import StringIO
import psutil, gpustat
from cachelib import SimpleCache

class Monitor:
    def __init__(self):
        self.cache = SimpleCache()

        self.cpu_model = self.GetCpuModel()
        print('cpu model:', self.cpu_model)
        self.gpu_model, self.gpu_cnt = self.GetGpuInfo()
        print('detect {} {} gpus.'.format(self.gpu_cnt, self.gpu_model))


    def GetCpuModel(self):
        cpu_model = 'CPU'
        tmpStr = os.popen('cat /proc/cpuinfo |grep "model name" | head -n 1').readlines()
        if len(tmpStr) and 'CPU' in tmpStr[0]:
            cpu_model = tmpStr[0].split('CPU')[0].strip().split(' ')[-1]
        return cpu_model


    def GetGpuInfo(self):
        tmpStr = os.popen('nvidia-smi -L').readlines()
        gpu_cnt = 0
        gpu_model = 'unknown'
        if len(tmpStr) and 'GPU' in tmpStr[0]:
            gpu_cnt = len(tmpStr)
            gpu_model_l = tmpStr[0].split('(')[0].strip().split(' ')[-2:]
            gpu_model = gpu_model_l[0] + '-' + gpu_model_l[1]
        return gpu_model, gpu_cnt


    def GetGpuClock(self):
        cnt = 0
        clocks = []
        avg_clock = 0
        while cnt < self.gpu_cnt:
            cmd = 'nvidia-smi -i {} -q -d CLOCK |grep Graphics | head -n 1'.format(cnt)
            clocks.append(int(os.popen(cmd).readlines()[0].split(':')[1][:-5]))
            cnt += 1
        if len(clocks):
            avg_clock = sum(clocks) / len(clocks)
        return avg_clock


    def update(self):
        hw_monitor = dict()
        tempratures = psutil.sensors_temperatures()

        # Time
        hw_monitor['time'] = time.strftime("%H:%M", time.localtime())
        hw_monitor['date'] = time.strftime("%Y-%m-%d", time.localtime())
        hw_monitor['week'] = time.strftime("%a", time.localtime()) + '.'

        # CPU
        hw_monitor['cpu_model'] = self.cpu_model
        hw_monitor['cpu_load'] = psutil.cpu_percent()
        package_temps = [i for i in tempratures['coretemp'] if 'Package' in i[0] ]
        hw_monitor['cpu_temp'] = int(sum([i[1] for i in package_temps]) / len(package_temps))
        hw_monitor['cpu_clock'] = int(psutil.cpu_freq()[0])

        # RAM
        mem = psutil.virtual_memory()
        hw_monitor['ram_load'] = mem[2]
        hw_monitor['ram_total'] = str(int(round((mem[0] / 1024 / 1024 / 1024), 0))) + 'GB'

        # GPU
        gpu_stat = gpustat.GPUStatCollection.new_query()
        tmpStr = StringIO()
        gpu_stat.print_json(tmpStr)
        tmpJson = json.loads(tmpStr.getvalue())
        gpus = tmpJson['gpus']
        hw_monitor['gpu_model'] = self.gpu_model
        hw_monitor['gpu_load'] = sum([i['utilization.gpu'] for i in gpus]) / len(gpus)
        hw_monitor['gram_load'] = int(sum([i['memory.used'] for i in gpus]) / sum([i['memory.total'] for i in gpus]) * 100)
        hw_monitor['gpu_temp'] = sum([i['temperature.gpu'] for i in gpus]) / len(gpus)
        hw_monitor['gpu_clock'] = self.GetGpuClock()

        # NET
        network = psutil.net_io_counters()
        last_net_time = self.cache.get('last_net_time')
        if not last_net_time:
            last_net_time = time.time()
            self.cache.set('last_net_time', last_net_time, 10)
            self.cache.set('last_link_up', network[0], 10)
            self.cache.set('last_link_dw', network[1], 10)
        cur_time = time.time()
        hw_monitor['link_up'] = int((network[0]-self.cache.get('last_link_up')) / (cur_time-last_net_time))
        hw_monitor['link_dw'] = int((network[1]-self.cache.get('last_link_dw')) / (cur_time-last_net_time))
        self.cache.set('last_net_time', cur_time, 10)
        self.cache.set('last_link_up', network[0], 10)
        self.cache.set('last_link_dw', network[1], 10)

        # IO
        io = psutil.disk_io_counters()
        last_disk_time = self.cache.get('last_disk_time')
        if not last_disk_time:
            last_disk_time = time.time()
            self.cache.set('last_disk_time', last_disk_time, 10)
            self.cache.set('last_io_read', io[2], 10)
            self.cache.set('last_io_write', io[3], 10)
        cur_time = time.time()
        hw_monitor['io_read'] = int((io[2]-self.cache.get('last_io_read')) / (cur_time-last_disk_time))
        hw_monitor['io_write'] = int((io[3]-self.cache.get('last_io_write')) / (cur_time-last_disk_time))
        self.cache.set('last_disk_time', cur_time, 10)
        self.cache.set('last_io_read', io[2], 10)
        self.cache.set('last_io_write', io[3], 10)

        return hw_monitor
