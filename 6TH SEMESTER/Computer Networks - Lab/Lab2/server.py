# -*- coding: utf-8 -*-
"""
Created on Fri Feb  3 13:04:00 2023

@author: Syed Hassan
"""

# server.py
import time
import socket

print("Starting the server side\n")
time.sleep(1)

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# this represents the domain and type of connection

host = socket.gethostname()
ip = socket.gethostbyname(host)
port = 12345

server_socket.bind((host, port))
print(host, "(", ip, ")\n")
name = input(str("Enter your name: "))
           

server_socket.listen(1)
print("\nWaiting for incoming connections...\n")
conn, addr = server_socket.accept()
print("Received connection from ", addr[0], "(", addr[1], ")\n")

s_name = conn.recv(1024)
s_name = s_name.decode()
print(s_name, "is ready for communication, enter x to terminate communication\n")
conn.send(name.encode())

while True:
    message = input(str("you : "))
    if message == "x":
        message = "terminated the connection!"
        conn.send(message.encode())
        print("\n")
        break
    conn.send(message.encode())
    message = conn.recv(1024)
    message = message.decode()
    print(s_name, ":", message)