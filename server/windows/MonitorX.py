# -*- coding: utf-8 -*-

import os, time
import inspect, logging
import win32serviceutil, win32service, win32event
from logging.handlers import TimedRotatingFileHandler
from monitorlib import monitor_once

class SystemMonitorService(win32serviceutil.ServiceFramework):
    _svc_name_ = "MonitorX Service"             # 服务名
    _svc_display_name_ = "MonitorX Service"     # job在windows services上显示的名字
    _svc_description_ = "系统资源监控服务"

    def __init__(self, args):
        win32serviceutil.ServiceFramework.__init__(self, args)
        self.hWaitStop = win32event.CreateEvent(None, 0, 0, None)  # 创建一个未命名的事件对象
        self.logger = self._getLogger()
        self.run = True

    def _getLogger(self):
        logger = logging.getLogger('[MonitorX]')                # 构造logger对象
        this_file = inspect.getfile(inspect.currentframe())     # 获取当前执行文件的文件路径
        dirpath = os.path.abspath(os.path.dirname(this_file))   # 获取当前文件的父级路径
        if not os.path.isdir('%s\\log' % dirpath):              # 创建log文件夹
            os.mkdir('%s\\log' % dirpath)
        dir = '%s\\log' % dirpath
        handler = TimedRotatingFileHandler(os.path.join(dir, "MonitorX.log"), when="midnight", interval=1,
                                           backupCount=20)  # 配置日志的设置
        formatter = logging.Formatter('%(asctime)s %(name)-12s %(levelname)-8s %(message)s')  # 配置日志写入格式
        handler.setFormatter(formatter)     # 写入格式
        logger.addHandler(handler)          # 添加配置
        logger.setLevel(logging.INFO)       # 设置日志记录登记
        return logger

    def SvcDoRun(self):
        '''
        服务启动函数
        :return: None
        '''
        self.logger.info("service run....")
        try:
            while self.run:
                monitor_once()
        except Exception as e:
            self.logger.info(e)
            time.sleep(60)

    def SvcStop(self):
        '''
        服务停止时执行的操作
        :return: None
        '''
        self.logger.info("service stop....")
        self.ReportServiceStatus(win32service.SERVICE_STOP_PENDING)     # 发送服务停止信号
        win32event.SetEvent(self.hWaitStop)                             # 设置事件重置
        self.run = False


if __name__ == '__main__':
    win32serviceutil.HandleCommandLine(SystemMonitorService)

