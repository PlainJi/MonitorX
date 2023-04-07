# -*- coding: utf-8 -*-

import time
import psutil
from cachelib import SimpleCache

cache = SimpleCache()

def GetNetWork():
    hw_monitor = dict()
    network = psutil.net_io_counters()
    last_net_time = cache.get('last_net_time')
    if not last_net_time:
        last_net_time = time.time()
        cache.set('last_net_time', last_net_time, 10)
        cache.set('last_link_up', network[0], 10)
        cache.set('last_link_dw', network[1], 10)
        hw_monitor['link_up'] = 0
        hw_monitor['link_dw'] = 0
    else:
        cur_time = time.time()
        hw_monitor['link_up'] = int((network[0]-cache.get('last_link_up')) / (cur_time-last_net_time))
        hw_monitor['link_dw'] = int((network[1]-cache.get('last_link_dw')) / (cur_time-last_net_time))
        cache.set('last_net_time', cur_time, 10)
        cache.set('last_link_up', network[0], 10)
        cache.set('last_link_dw', network[1], 10)
    return hw_monitor

def GetIoReadWrite():
    hw_monitor = dict()
    io = psutil.disk_io_counters()
    last_disk_time = cache.get('last_disk_time')
    if not last_disk_time:
        last_disk_time = time.time()
        cache.set('last_disk_time', last_disk_time, 10)
        cache.set('last_io_read', io[2], 10)
        cache.set('last_io_write', io[3], 10)
        hw_monitor['io_read'] = 0
        hw_monitor['io_write'] = 0
    else:
        cur_time = time.time()
        hw_monitor['io_read'] = int((io[2]-cache.get('last_io_read')) / (cur_time-last_disk_time))
        hw_monitor['io_write'] = int((io[3]-cache.get('last_io_write')) / (cur_time-last_disk_time))
        cache.set('last_disk_time', cur_time, 10)
        cache.set('last_io_read', io[2], 10)
        cache.set('last_io_write', io[3], 10)
    return hw_monitor