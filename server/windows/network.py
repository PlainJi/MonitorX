#coding:utf-8,
import socket
import time

ANY = '0.0.0.0'
MCAST_ADDR = '239.0.0.1'
MCAST_PORT = 5556
SENDERPORT=5555

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind((ANY, SENDERPORT))
sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 255)

def send(data):
    sock.sendto(data, (MCAST_ADDR,MCAST_PORT))
